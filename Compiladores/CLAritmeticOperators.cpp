#include "CLAritmeticOperators.h"



LEXIC_STATES::E CLAritmeticOperators::Evaluate(char character)
{
	if (character == '*')
	{
		m_bflagComment = true;
		return LEXIC_STATES::lCOMMENTS;
	}
	return LEXIC_STATES::lNONE;
}

LEXIC_STATES::E CLAritmeticOperators::Enter(char character, std::string string)
{
	if (character == '/')
	{
		m_bflagComment = false;
		return LEXIC_STATES::lARITMETICOPERATORS;
	}
	m_string = "";
	m_string.push_back(character);
	m_tokenaizer->AddToken(m_string, "AritmeticOperator");
	return LEXIC_STATES::lNONE;
}

std::string CLAritmeticOperators::Exit()
{
	if (!m_bflagComment)
	{
		m_tokenaizer->AddToken("/", "AritmeticOperator");
	}
	return std::string();
}

CLAritmeticOperators::CLAritmeticOperators()
{
}


CLAritmeticOperators::~CLAritmeticOperators()
{
}
