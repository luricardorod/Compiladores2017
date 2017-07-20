#ifndef COMPILADORES_H
#define COMPILADORES_H

#include <QtWidgets/QMainWindow>
#include "ui_compiladores.h"

class Compiladores : public QMainWindow
{
	Q_OBJECT

public:
	Compiladores(QWidget *parent = 0);
	~Compiladores();
	std::string m_tokens;
	std::string m_errors;
	std::string m_nodes;

private:
	Ui::CompiladoresClass ui;
	private slots:
	void exit();
	void compile();
	void save();
};

#endif // COMPILADORES_H
