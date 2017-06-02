#include "CLId.h"

LEXIC_STATES::E CLId::Evaluate(char character)
{
	if (IsNumber(character) || IsLetter(character) || Is_(character))
	{
		m_string.push_back(character);
		return LEXIC_STATES::lID;
	}
	return LEXIC_STATES::lNONE;
}

LEXIC_STATES::E CLId::Enter(char character, std::string string)
{
	m_string = "";
	m_string.push_back(character);
	return LEXIC_STATES::lID;
}

std::string CLId::Exit()
{
	if (
		m_string == "var" ||
		m_string == "int" ||
		m_string == "float" ||
		m_string == "string" ||
		m_string == "bool" ||
		m_string == "function" ||
		m_string == "procedure" ||
		m_string == "main" ||
		m_string == "for" ||
		m_string == "while" ||
		m_string == "if" ||
		m_string == "else" ||
		m_string == "switch" ||
		m_string == "print" ||
		m_string == "read" ||
		m_string == "return" ||
		m_string == "default"
	)
	{
		m_tokenaizer->AddToken(m_string, "Keyword");
	}
	else
	{
		m_tokenaizer->AddToken(m_string, "Id");
	}
	return std::string();
}

CLId::CLId()
{
}


CLId::~CLId()
{
}
