#include "CLConstantAlfanumeric.h"



LEXIC_STATES::E CLConstantAlfanumeric::Evaluate(char character)
{
	if (m_bflagChangeState)
	{
		return LEXIC_STATES::lNONE;
	}
	if (character == '"')
	{
		m_bflagChangeState = true;
	}
	else if(IsNumber(character) || IsLetter(character))
	{
		m_string.push_back(character);
	}
	else
	{
		m_flagError = true;
		m_errorHandler->AddError(ERROR1, "Lexico");
		//error caracter invalido en constantealfanumerica
	}

	return LEXIC_STATES::lCONSTANTALFANUMERIC;
}

LEXIC_STATES::E CLConstantAlfanumeric::Enter(char character, std::string string)
{
	m_string = "";
	m_bflagChangeState = false;
	m_flagError = false;
	return LEXIC_STATES::lCONSTANTALFANUMERIC;
}

std::string CLConstantAlfanumeric::Exit()
{
	if (m_bflagChangeState && !m_flagError)
	{
		m_tokenaizer->AddToken(m_string, "Constant Alfanumeric", LEXIC_STATES::lCONSTANTALFANUMERIC);
	}
	return std::string();
}

CLConstantAlfanumeric::CLConstantAlfanumeric()
{
}


CLConstantAlfanumeric::~CLConstantAlfanumeric()
{
}
