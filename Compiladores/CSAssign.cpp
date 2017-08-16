#include "CSAssign.h"



SYNTACTIC_STATES::E CSAssign::Evaluate(Token token, SYNTACTIC_STATES::E oldState, std::string parent)
{
	
	if (token.itype != LEXIC_STATES::lID)
	{
		m_errorHandler->AddError(ERROR33, "sintactico", token.line);
	}
	token = NextToken();
	if (token.svalue == "(" && oldState == SYNTACTIC_STATES::SBLOCK)
	{
		token = NextToken();
		if (token.svalue != ")") {
			(*m_indexToken)--;
			do
			{
				(*m_States)[SYNTACTIC_STATES::SEXPRESSION]->Evaluate(token, SYNTACTIC_STATES::SBLOCK);
				token = NextToken();
			} while (token.svalue == ",");
			if (token.svalue != ")")
			{
				m_errorHandler->AddError(ERROR10, "sintactico", token.line);
				(*m_indexToken)--;
			}
			token = NextToken();
			if (token.svalue != ";")
			{
				m_errorHandler->AddError(ERROR10, "sintactico", token.line);
				while (token.svalue != ";" && token.svalue != "}" && token.svalue != "NULL")
				{
					token = NextToken();
				}
				(*m_indexToken)--;
			}
		}

	} 
	else
	{
		if (token.svalue == "[")
		{
			(*m_States)[SYNTACTIC_STATES::SEXPRESSION]->Evaluate(token, SYNTACTIC_STATES::SBLOCK);
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
			(*m_States)[SYNTACTIC_STATES::SEXPRESSION]->Evaluate(token, SYNTACTIC_STATES::SBLOCK);
			token = NextToken();

			if (token.svalue != ";")
			{
				m_errorHandler->AddError(ERROR10, "sintactico", token.line);
			}
		}
		else
		{
			m_errorHandler->AddError(ERROR35, "sintactico", token.line);
		}
	}
	return SYNTACTIC_STATES::E();
}

CSAssign::CSAssign()
{
}


CSAssign::~CSAssign()
{
}
