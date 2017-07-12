#include "CLRelacionalOperators.h"



LEXIC_STATES::E CLRelacionalOperators::Evaluate(char character)
{
	if (m_bchangeState)
	{
		return LEXIC_STATES::lNONE;
	}
	if (character == '=')
	{
		m_string.push_back(character);
		m_bchangeState = true;
		return LEXIC_STATES::lRELACIONALOPERATORS;
	}
	return LEXIC_STATES::lNONE;
}

LEXIC_STATES::E CLRelacionalOperators::Enter(char character, std::string string)
{
	//<, >, <= , >= , == , !=
	if (string == "!")
	{
		m_tokenaizer->AddToken("!=", "Relacional Operator", LEXIC_STATES::lRELACIONALOPERATORS);
		return LEXIC_STATES::lNONE;
	}
	if (string == "=")
	{
		m_tokenaizer->AddToken("==", "Relacional Operator", LEXIC_STATES::lRELACIONALOPERATORS);
		return LEXIC_STATES::lNONE;
	}
	m_string = "";
	m_string.push_back(character);
	m_bchangeState = false;
	return LEXIC_STATES::lRELACIONALOPERATORS;
}

std::string CLRelacionalOperators::Exit()
{
	m_tokenaizer->AddToken(m_string, "Relacional Operator", LEXIC_STATES::lRELACIONALOPERATORS);

	return std::string();
}

CLRelacionalOperators::CLRelacionalOperators()
{
}


CLRelacionalOperators::~CLRelacionalOperators()
{
}
