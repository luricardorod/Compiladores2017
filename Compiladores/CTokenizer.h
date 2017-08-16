#pragma once
#include <string>
#include <vector>
#include "CErrorHandler.h"

struct Token
{
	std::string svalue;
	int itype;
	int line;
};
class CTokenizer
{
public:
	CErrorHandler *m_errorHandler;
	std::vector<Token> m_listTokens;
	std::string m_tokens;
	void AddToken(std::string token, std::string typeString, int typeLexic);
	std::string GetTokens();
	void Initialize();
	CTokenizer();
	~CTokenizer();
};

