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

