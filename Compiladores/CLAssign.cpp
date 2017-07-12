#pragma once
#include "CLAssign.h"

LEXIC_STATES::E CLAssign::Evaluate(char character)
{
	if (character == '=')
	{
		m_bflag = true;
		return LEXIC_STATES::lRELACIONALOPERATORS;
	}
	return LEXIC_STATES::E();
}

LEXIC_STATES::E CLAssign::Enter(char character, std::string string)
{
	m_string = "";
	m_bflag = false;
	return LEXIC_STATES::lASSIGN;
}

std::string CLAssign::Exit()
{
	if (m_bflag)
	{
		return "=";
	}
	m_tokenaizer->AddToken("=", "Assign", LEXIC_STATES::lASSIGN);

	return std::string();
}

CLAssign::CLAssign()
{
}


CLAssign::~CLAssign()
{
}
