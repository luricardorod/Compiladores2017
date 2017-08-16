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
		token = NextToken();

		if (token.svalue != "(")
		{
			(*m_indexToken) -= 2;
		}
	}
	LEXIC_STATES::E temp = transformSemToType((*m_States)[SEMANTIC_STATES::SEXPRESSION]->Evaluate(token, SEMANTIC_STATES::SEXPRESSION));
	if (temp != LEXIC_STATES::lBOOL)
	{
		m_errorHandler->AddError(ERROR47, "semantico", token.line);
	}
	token = NextToken();
	if (token.svalue != ")")
	{
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
