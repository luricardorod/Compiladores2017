#pragma once
#include <string>

const std::string ERROR1 = "Caracter invalido";
const std::string ERROR2 = "No se cerro el comentario";
const std::string ERROR3 = "no cerro constante alfanumerica";
const std::string ERROR4 = "Operador Logico incompleto";
const std::string ERROR5 = "Se esperaba un numero u operador";
const std::string ERROR6 = "Se esperaba un numero";
const std::string ERROR7 = "Se esperaba un ID";
const std::string ERROR8 = "Se esperaba un Int";
const std::string ERROR9 = "Se esperaba :";
const std::string ERROR10 = "Se esperaba ;";
const std::string ERROR11 = "Se esperaba un tipo";
const std::string ERROR12 = "Se esperaba un ]";
const std::string ERROR13 = "Var global duplicada";
const std::string ERROR14 = "funcion global duplicada";
const std::string ERROR15 = "procedimiento global duplicado";
const std::string ERROR16 = "var repetida en funcion/procedimiento";
const std::string ERROR17 = "falta funcion main";
const std::string ERROR18 = "funcion o preocedimiento repetido";
const std::string ERROR19 = "se esperaba (";
const std::string ERROR20 = "se esperaba id o )";
const std::string ERROR21 = "se esperaba {";
const std::string ERROR22 = "se esperaba var o un statement";
const std::string ERROR23 = "se esperaba , o )";
const std::string ERROR24 = "se esperaba un operador";
const std::string ERROR25 = "se esperaba  )";
const std::string ERROR26 = "se esperaba  termino";
const std::string ERROR27 = "se esperaba  }";
const std::string ERROR28 = "se esperaba funcion/procedimiento";
const std::string ERROR29 = "Declaracion de variables al principio de la funcion";
const std::string ERROR30 = "Declaracion de variables globales al principio del programa";
const std::string ERROR31 = "Declaracion de Funciones o procedimientos des pues de variables globales";
const std::string ERROR32 = "Funcion main repetida";
const std::string ERROR33 = "se esperaba id";
const std::string ERROR34 = "se esperaba operador relacional";
const std::string ERROR35 = "se esperaba =";


class CErrorHandler
{
public:
	int line;
	int m_numberErrors;
	std::string m_Errors;
	void AddError(std::string error, std::string phase);
	void AddError(std::string error, std::string phase, int line);

	int GetNumberError();
	void Nextline();
	void Initialize();
	std::string GetErrors();
	CErrorHandler();
	~CErrorHandler();
};

