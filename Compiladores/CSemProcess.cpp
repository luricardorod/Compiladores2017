#include "CSemProcess.h"

SEMANTIC_STATES::E CSemProcess::Evaluate(Token token, SEMANTIC_STATES::E oldState, std::string parent)
{
	if (token.itype != LEXIC_STATES::lID)
	{
		while (token.svalue != "}" && token.svalue != "NULL")
		{
			token = NextToken();
		}
		return SEMANTIC_STATES::E();
	}
	(*m_name) = token.svalue;
	while (token.svalue != "{" && token.svalue != "NULL")
	{
		token = NextToken();
	}
	(*m_indexToken)--;
	(*m_States)[SEMANTIC_STATES::SBLOCK]->Evaluate(token, SEMANTIC_STATES::SFUNCTION);
	(*m_name) = "NULL";
}

CSemProcess::CSemProcess()
{
}


CSemProcess::~CSemProcess()
{
}
