#include "CSemIf.h"



SEMANTIC_STATES::E CSemIf::Evaluate(Token token, SEMANTIC_STATES::E oldState, std::string parent)
{
	bool flagIf = false;
	if (token.svalue == "if")
	{
		flagIf = true;
	}
	token = NextToken();
	if (token.svalue != "(")
	{
		m_errorHandler->AddError(ERROR19, "sintactico", token.line);
		token = NextToken();

		if (token.svalue != "(")
		{
			(*m_indexToken) -= 2;
		}
	}
	(*m_States)[SEMANTIC_STATES::SEXPRESSION]->Evaluate(token, SEMANTIC_STATES::SBLOCK, "");
	token = NextToken();
	if (token.svalue != ")")
	{
		m_errorHandler->AddError(ERROR25, "sintactico", token.line);
		token = NextToken();

		if (token.svalue != ")")
		{
			(*m_indexToken) -= 2;
		}
	}
	(*m_States)[SEMANTIC_STATES::SBLOCK]->Evaluate(token, SEMANTIC_STATES::SBLOCK);
	if (flagIf)
	{
		token = NextToken();
		if (token.svalue == "else")
		{
			(*m_States)[SEMANTIC_STATES::SBLOCK]->Evaluate(token, SEMANTIC_STATES::SBLOCK, "");
		}
		else
		{
			(*m_indexToken)--;
		}
	}
	return SEMANTIC_STATES::E();
}

CSemIf::CSemIf()
{
}


CSemIf::~CSemIf()
{
}
