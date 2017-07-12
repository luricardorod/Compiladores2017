#pragma once
#include "CTokenizer.h"
#include "CErrorHandler.h"
#include <string>


class CLexicalStates
{
public:
	virtual LEXIC_STATES::E Evaluate(char character) = 0;
	virtual LEXIC_STATES::E Enter(char character, std::string string) = 0;
	virtual std::string Exit() = 0;
	virtual ~CLexicalStates() {};
	std::string m_string;
	CTokenizer* m_tokenaizer;
	CErrorHandler* m_errorHandler;
	bool IsNumber(char character) {
		return character > 47 && character < 58;
	}
	bool IsLetter(char character) {
		return (character > 64 && character < 91) || (character > 96 && character < 123);
	}
	bool Is_(char character) {
		return character == '_';
	}
	//// +, -, *, / , %, ^
	bool IsAritmeticOperator(char character) {
		return character == '+' || character == '-' || character == '*' || character == '/' || character == '%' || character == '^';
	}

	// , ; :
	bool IsDelimiter(char character) {
		return character == ',' || character == ':' || character == ';';
	}

	//(, ), { , }
	bool IsGroupOperators(char character) {
		return character == '(' || character == ')' || character == '{' || character == '}';
	}

	bool isLogicOperators(char character) {
		return character == '|' || character == '&' || character == '!';
	}

	bool isRelacionalOperators(char character) {
		return character == '<' || character == '>';
	}
};

//48 57  numeros  65 a 90 may  97 122 min