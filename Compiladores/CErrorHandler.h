#pragma once
#include <string>
const std::string ERROR1 = "Caracter invalido";
const std::string ERROR2 = "No se cerro el comentario";
const std::string ERROR3 = "no cerro constante alfanumerica";
const std::string ERROR4 = "Operador Logico incompleto";
const std::string ERROR5 = "Se esperaba un numero u operador";
const std::string ERROR6 = "Se esperaba un numero";

class CErrorHandler
{
public:
	int line;
	int m_numberErrors;
	std::string m_Errors;
	void AddError(std::string error, std::string phase);
	int GetNumberError();
	void Nextline();
	void Initialize();
	std::string GetErrors();
	CErrorHandler();
	~CErrorHandler();
};

