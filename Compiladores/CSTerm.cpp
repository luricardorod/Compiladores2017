#include "CSTerm.h"



SYNTACTIC_STATES::E CSTerm::Evaluate(Token token, SYNTACTIC_STATES::E oldState, std::string parent)
{
	token = NextToken();
	if (token.svalue == "(")
	{
		(*m_States)[SYNTACTIC_STATES::SEXPRESSION]->Evaluate(token, SYNTACTIC_STATES::SEXPRESSION);
		token = NextToken();
		if (token.svalue != ")")
		{
			m_errorHandler->AddError(ERROR25, "sintactico", token.line);
		}
	}
	else if (token.svalue == "true" || token.svalue == "false" || token.itype == LEXIC_STATES::lNUMBERINT || token.itype == LEXIC_STATES::lNUMBERFLOAT || token.itype == LEXIC_STATES::lSTRING)
	{
		return SYNTACTIC_STATES::E();
	}
	else if (token.itype == LEXIC_STATES::lID)
	{
		token = NextToken();
		if (token.svalue == "[")
		{
			(*m_States)[SYNTACTIC_STATES::SEXPRESSION]->Evaluate(token, SYNTACTIC_STATES::SEXPRESSION);
			token = NextToken();
			if (token.svalue != "]")
			{
				m_errorHandler->AddError(ERROR12, "Sintactico", token.line);
				while (token.svalue != ")" && token.svalue != "NULL")
				{
					token = NextToken();
				}
				return SYNTACTIC_STATES::SPROGRAM;
			}
		}
		else if (token.svalue == "(")
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
			(*m_indexToken)--;
		}
	}
	else if (token.svalue == "!" || token.svalue == "-")
	{
		(*m_States)[SYNTACTIC_STATES::STERM]->Evaluate(token, SYNTACTIC_STATES::SEXPRESSION);
	}
	else
	{
		m_errorHandler->AddError(ERROR26, "sintactico", token.line);
		token = NextToken();
		if (token.svalue == "(" || (token.itype == LEXIC_STATES::lID) || (token.itype == LEXIC_STATES::lNUMBERINT || token.itype == LEXIC_STATES::lNUMBERFLOAT || token.itype == LEXIC_STATES::lSTRING) || (token.svalue == "!")) {
			(*m_indexToken)--;
			(*m_States)[SYNTACTIC_STATES::STERM]->Evaluate(token, SYNTACTIC_STATES::STERM);
		}
		else
		{
			(*m_indexToken)--;
			(*m_indexToken)--;
		}

	}
	return SYNTACTIC_STATES::E();
}

CSTerm::CSTerm()
{
}


CSTerm::~CSTerm()
{
}
