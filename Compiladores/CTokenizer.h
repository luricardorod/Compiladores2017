#pragma once
#include <string>
class CTokenizer
{
public:
	std::string m_tokens;
	void AddToken(std::string token, std::string type);
	std::string GetTokens();
	void Initialize();
	CTokenizer();
	~CTokenizer();
};

