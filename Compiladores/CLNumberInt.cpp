#include "CLNumberInt.h"



LEXIC_STATES::E CLNumberInt::Evaluate(char character)
{
	if (IsNumber(character))
	{
		m_string.push_back(character);
		return LEXIC_STATES::lNUMBERINT;

	}
	else if (character == '.')
	{
		flag = true;
		return LEXIC_STATES::lNUMBERFLOAT;

	}
	else if (!(character == 10 || character == 32 || isLogicOperators(character) || IsAritmeticOperator(character) || isRelacionalOperators(character) || character == '=' || IsDelimiter(character) || IsGroupOperators(character) || character == '[' || character == ']'))
	{
		m_errorHandler->AddError(ERROR5, "lexico");
		m_bflagError = true;
	}

	return LEXIC_STATES::lNONE;

}

LEXIC_STATES::E CLNumberInt::Enter(char character, std::string string)
{
	m_string = "";
	m_string.push_back(character);
	flag = false;
	m_bflagError = false;
	return LEXIC_STATES::lNUMBERINT;
}

std::string CLNumberInt::Exit()
{
	if (m_bflagError)
	{
		return std::string();
	}
	if (flag)
	{
		return m_string;
	}
	m_tokenaizer->AddToken(m_string, "Int", LEXIC_STATES::lNUMBERINT);
	return std::string();
}

CLNumberInt::CLNumberInt()
{

}


CLNumberInt::~CLNumberInt()
{
}
