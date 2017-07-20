#include "compiladores.h"
#include <string>
#include "CLexicalAnalysis.h"
#include "CSyntacticAnalysis.h"
#include "CTokenizer.h"
#include "CErrorHandler.h"
#include "NodesVars.h"
#include <iostream>
#include <fstream>

Compiladores::Compiladores(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
	connect(ui.actionSalir, SIGNAL(triggered()), this, SLOT(exit()));
	connect(ui.actionCompilar, SIGNAL(triggered()), this, SLOT(compile()));
	connect(ui.actionGuardar, SIGNAL(triggered()), this, SLOT(save()));
}

Compiladores::~Compiladores()
{

}

void Compiladores::compile()
{
	CTokenizer tokenizer;
	CErrorHandler errorHandler;
	tokenizer.m_errorHandler = &errorHandler;
	CNodesVars nodes;
	nodes.m_errorHandler = &errorHandler;

	nodes.Init();
	CLexicalAnalysis lexicalAnalysis;
	std::string file = ui.textEdit->toPlainText().toStdString();
	file = "var ? a, b, c[10]:int; \n <===>!=<><>><<>+<+=>>=++ \n[[[\nfunction factorial(n:int) :int \n{ \n &&|||&&!!|&!||&& \n \"hola123321sfdfs\" \n \n \"hola12 3321sfdfs\" \n if ? (n < 2.055) \n2+3.0+89/96*44- 96 *78\n/*var lon 5.5skjhfa sd* asd ofisa#$^$#^%#$% */\n{ \n    return 1; \n } \n  else \n{ \n    return n*factorial(n - 1); \n } \n }  \n main \n{ \n print(factorial, factorial(5)); \n }";
	file = ui.textEdit->toPlainText().toStdString();
	lexicalAnalysis.Compile(&file, &tokenizer, &errorHandler);
	m_tokens = tokenizer.GetTokens();

	CSyntacticAnalysis sintacticAnalysis;

	sintacticAnalysis.Compile(&tokenizer, &errorHandler, &nodes);
	m_nodes = nodes.GetNodes();

	m_errors = errorHandler.GetErrors();
	nodes.GetNodes();
	int numberErrors = errorHandler.GetNumberError();
	std::string temp = "-------Compilado-------\n";
	if (numberErrors != 0)
	{
		temp += "-------Error " + std::to_string(numberErrors) + " -------\n";
	}
	else
	{
		temp += "-------Success-------\n";

	}
	ui.textEdit_2->setPlainText(QString::fromStdString(temp + m_errors));

}

void Compiladores::save()
{
	std::ofstream table("table.lex", std::ofstream::out);
	table << m_tokens;
	table.close();
	std::ofstream err("errors.lex", std::ofstream::out);
	err << m_errors;
	err.close();

	std::ofstream syn("syn.lex", std::ofstream::out);
	syn << m_nodes;
	syn.close();
}

void Compiladores::exit()
{
	QApplication::exit();
}