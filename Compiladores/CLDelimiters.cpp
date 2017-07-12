#include "CLDelimiters.h"



LEXIC_STATES::E CLDelimiters::Evaluate(char character)
{
	return LEXIC_STATES::E();
}

LEXIC_STATES::E CLDelimiters::Enter(char character, std::string string)
{
	m_string = "";
	m_string.push_back(character);
	m_tokenaizer->AddToken(m_string, "Delimiter", LEXIC_STATES::lDELIMITERS);
	return LEXIC_STATES::lNONE;
}

std::string CLDelimiters::Exit()
{
	return std::string();
}

CLDelimiters::CLDelimiters()
{
}


CLDelimiters::~CLDelimiters()
{
}
