#include "CLComments.h"



LEXIC_STATES::E CLComments::Evaluate(char character)
{
	if (m_bflagChangeState)
	{
		return LEXIC_STATES::lNONE;
	}
	if (character == 10)
	{
		m_errorHandler->Nextline();
	}
	if (character == '*')
	{
		m_bflagClose = true;
	}
	else if (m_bflagClose)
	{
		m_bflagClose = false;
		if (character == '/')
		{
			m_bflagChangeState = true;
		}
	}
	return LEXIC_STATES::lCOMMENTS;
}

LEXIC_STATES::E CLComments::Enter(char character, std::string string)
{
	m_bflagClose = false;
	m_bflagChangeState = false;
	return LEXIC_STATES::lCOMMENTS;
}

std::string CLComments::Exit()
{
	return std::string();
}

CLComments::CLComments()
{
}


CLComments::~CLComments()
{
}
