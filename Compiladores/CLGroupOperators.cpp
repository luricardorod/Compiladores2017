#include "CLGroupOperators.h"



LEXIC_STATES::E CLGroupOperators::Evaluate(char character)
{
	return LEXIC_STATES::E();
}

LEXIC_STATES::E CLGroupOperators::Enter(char character, std::string string)
{
	m_string = "";
	m_string.push_back(character);
	m_tokenaizer->AddToken(m_string, "Group Operators");
	return LEXIC_STATES::lNONE;
}

std::string CLGroupOperators::Exit()
{
	return std::string();
}

CLGroupOperators::CLGroupOperators()
{
}


CLGroupOperators::~CLGroupOperators()
{
}
