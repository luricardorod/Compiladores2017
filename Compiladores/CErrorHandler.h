#pragma once
#include <string>
namespace LEXIC_STATES
{
	enum E
	{
		lNONE,
		lID,			//a...z | A...Z | _ [<text>] done
		lNUMBERINT,		//0...9 [number] done
		lNUMBERFLOAT,	//[number] . [number] done
		lCOMMENTS,		///*....*/ done
		lLOGICOPERATORS, //&&, || , ! done
		lARITMETICOPERATORS,  // +, -, *, / , %, ^ done
		lRELACIONALOPERATORS, //<, >, <= , >= , == , != done
		lASSIGN,     //= done
		lSTRING, //"..." done
		lDELIMITERS, // , ; : done
		lGROUPOPERATORS, //(, ), { , } done
		lOPENDIMENSIONOPERATOR, // [ done
		lCLOSEDIMENSIONOPERATOR, // ] done
		lKEYWORD,
		lBOOL,
		lSTATES_MAX
	};
}
namespace CATEGORIES_EXPRESSION
{
	enum E
	{
		NULLCATEGORY,
		VAR,
		FUNCTION,
		PROCEDURE,
		MAIN
	};
}
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
const std::string ERROR36 = "se esperaba declaracion de variables funcion o precidimiento";
const std::string ERROR37 = "solo las funciones tienen return";
const std::string ERROR38 = "falta return";
const std::string ERROR39 = "No existe funcion o procedimiento";
const std::string ERROR40 = "No ecorresponden numero de parametros";
const std::string ERROR41 = "Los parametros no corresponden";
const std::string ERROR42 = "No existe ID";
const std::string ERROR43 = "ID sin dimension";
const std::string ERROR44 = "Error la expresion esperaba un int";
const std::string ERROR45 = "El tipo no es igual a la asigancion";
const std::string ERROR46 = "tipo Return distinto a tipo funcion";
const std::string ERROR47 = "se esperaba un bool de la funcion";
const std::string ERROR48 = "se esperaba un int";
const std::string ERROR49 = "se esperaba un int o flotante";
const std::string ERROR50 = "se esperaba un bool";






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
	LEXIC_STATES::E SetType(std::string type);
	CErrorHandler();
	~CErrorHandler();
};

