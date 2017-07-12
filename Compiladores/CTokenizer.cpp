#include "CTokenizer.h"

void CTokenizer::AddToken(std::string token, std::string typeString, int typeLexic)
{
	m_tokens += token + "\t" + typeString + "\n";
	Token temp;
	temp.itype = typeLexic;
	temp.svalue = token;
	temp.line = m_errorHandler->line;
	m_listTokens.push_back(temp);
}

std::string CTokenizer::GetTokens()
{
	return m_tokens;
}

void CTokenizer::Initialize()
{
	m_tokens = "";

}

CTokenizer::CTokenizer()
{
	Initialize();
}


CTokenizer::~CTokenizer()
{
}
