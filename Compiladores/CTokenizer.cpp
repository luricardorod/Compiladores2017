#include "CTokenizer.h"



void CTokenizer::AddToken(std::string token, std::string type)
{
	m_tokens += token + "\t" + type + "\n";
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
