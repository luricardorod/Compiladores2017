#include "CSIf.h"



SYNTACTIC_STATES::E CSIf::Evaluate(Token token, SYNTACTIC_STATES::E oldState, std::string parent)
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
	(*m_States)[SYNTACTIC_STATES::SEXPRESSION]->Evaluate(token, SYNTACTIC_STATES::SBLOCK, "");
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
	(*m_States)[SYNTACTIC_STATES::SBLOCK]->Evaluate(token, SYNTACTIC_STATES::SBLOCK);
	if (flagIf)
	{
		token = NextToken();
		if (token.svalue == "else")
		{
			(*m_States)[SYNTACTIC_STATES::SBLOCK]->Evaluate(token, SYNTACTIC_STATES::SBLOCK, "");
		}
		else
		{
			(*m_indexToken)--;
		}
	}
	return SYNTACTIC_STATES::E();
}

CSIf::CSIf()
{
}


CSIf::~CSIf()
{
}
