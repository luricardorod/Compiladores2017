#include "CLNumberFloat.h"



LEXIC_STATES::E CLNumberFloat::Evaluate(char character)
{
	if (IsNumber(character))
	{
		m_flagFirstNumber = true;
		m_string.push_back(character);
		return LEXIC_STATES::lNUMBERFLOAT;
	}
	else if (!(character == 10 || character == 32 || isLogicOperators(character) || IsAritmeticOperator(character) || isRelacionalOperators(character) || character == '=' || IsDelimiter(character) || IsGroupOperators(character) || character == '[' || character == ']'))
	{
		m_bflagError = true;
	}
	return LEXIC_STATES::lNONE;
}

LEXIC_STATES::E CLNumberFloat::Enter(char character, std::string string)
{
	m_string = string + ".";
	m_flagFirstNumber = false;
	m_bflagError = false;
	return LEXIC_STATES::lNUMBERFLOAT;
}

std::string CLNumberFloat::Exit()
{
	if (!m_flagFirstNumber)
	{
		m_errorHandler->AddError(ERROR6, "lexico");
	}
	else if(m_bflagError)
	{
		m_errorHandler->AddError(ERROR5, "lexico");
	}
	else
	{
		m_tokenaizer->AddToken(m_string, "float", LEXIC_STATES::lNUMBERFLOAT);
	}
	return std::string();
}

CLNumberFloat::CLNumberFloat()
{
}


CLNumberFloat::~CLNumberFloat()
{
}
