#include "CSemAssign.h"

SEMANTIC_STATES::E CSemAssign::Evaluate(Token token, SEMANTIC_STATES::E oldState, std::string parent)
{

	if (token.itype != LEXIC_STATES::lID)
	{
		m_errorHandler->AddError(ERROR33, "sintactico", token.line);
	}
	token = NextToken();
	if (token.svalue == "[")
	{
		(*m_States)[SEMANTIC_STATES::SEXPRESSION]->Evaluate(token, SEMANTIC_STATES::SBLOCK);
		token = NextToken();
		if (token.svalue != "]")
		{
			m_errorHandler->AddError(ERROR12, "Sintactico", token.line);
			while (token.svalue != ")" && token.svalue != "NULL")
			{
				token = NextToken();
			}
		}
		token = NextToken();
	}
	if (token.svalue == "=")
	{
		(*m_States)[SEMANTIC_STATES::SEXPRESSION]->Evaluate(token, SEMANTIC_STATES::SBLOCK);
		token = NextToken();

		if (token.svalue != ";")
		{
			m_errorHandler->AddError(ERROR10, "sintactico", token.line);
		}
	}
	else if (token.svalue == "(" && oldState == SEMANTIC_STATES::SBLOCK)
	{
		token = NextToken();
		if (token.svalue != ")") {
			(*m_indexToken)--;
			(*m_States)[SEMANTIC_STATES::SEXPRESSION]->Evaluate(token, SEMANTIC_STATES::SBLOCK);
			token = NextToken();
			if (token.svalue != ")")
			{
				m_errorHandler->AddError(ERROR10, "sintactico", token.line);
				token = NextToken();
				if (token.svalue != ";")
				{
					m_errorHandler->AddError(ERROR10, "sintactico", token.line);
					while (token.svalue != ";" && token.svalue != "}" && token.svalue != "NULL")
					{
						token = NextToken();
					}
				}
			}
		}

	}
	else
	{
		m_errorHandler->AddError(ERROR35, "sintactico", token.line);
	}
	return SEMANTIC_STATES::E();
}

CSemAssign::CSemAssign()
{
}


CSemAssign::~CSemAssign()
{
}
