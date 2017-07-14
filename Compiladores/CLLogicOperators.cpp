#include "CLLogicOperators.h"



LEXIC_STATES::E CLLogicOperators::Evaluate(char character)
{
	if (m_bflagChangeState)
	{
		return LEXIC_STATES::lNONE;
	}
	if (m_bflagNegate)
	{
		if (character == '=')
		{
			m_bflagChangeState = true;
			return LEXIC_STATES::lRELACIONALOPERATORS;
		}
		return LEXIC_STATES::lNONE;
	}
	else if (m_bflagOr)
	{
		if (character == '|')
		{
			m_bflagChangeState = true;
			return LEXIC_STATES::lLOGICOPERATORS;
		}
	}
	else
	{
		if (character == '&')
		{
			m_bflagChangeState = true;
			return LEXIC_STATES::lLOGICOPERATORS;
		}
	}
	return LEXIC_STATES::lNONE;
}

LEXIC_STATES::E CLLogicOperators::Enter(char character, std::string string)
{
	m_bflagOr = false;
	m_bflagChangeState = false;
	m_bflagNegate = false;

	if (character == '!')
	{
		m_bflagNegate = true;
	}
	else if (character == '|')
	{
		m_bflagOr = true;
	}

	return LEXIC_STATES::lLOGICOPERATORS;
}

std::string CLLogicOperators::Exit()
{
	if (!m_bflagChangeState && m_bflagNegate)
	{
		m_tokenaizer->AddToken("!", "Logic Operator", LEXIC_STATES::lLOGICOPERATORS);
		return std::string();

	}
	else if (m_bflagNegate)
	{
		return "!";
	}
	else if (!m_bflagChangeState)
	{
		m_errorHandler->AddError(ERROR4, "lexico");
		return std::string();
	}
	if (m_bflagOr)
	{
		m_tokenaizer->AddToken("||", "Logic Operator", LEXIC_STATES::lLOGICOPERATORS);
	}
	else
	{
		m_tokenaizer->AddToken("&&", "Logic Operator", LEXIC_STATES::lLOGICOPERATORS);
	}
	return std::string();
}

CLLogicOperators::CLLogicOperators()
{
}


CLLogicOperators::~CLLogicOperators()
{
}
