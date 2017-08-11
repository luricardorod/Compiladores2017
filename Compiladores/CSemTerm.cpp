#include "CSemTerm.h"



SEMANTIC_STATES::E CSemTerm::Evaluate(Token token, SEMANTIC_STATES::E oldState, std::string parent, std::vector<Token>* expressionPosfija, std::vector<Token>* operators)
{
	token = NextToken();
	if (token.svalue == "(")
	{
		(*m_States)[SEMANTIC_STATES::SEXPRESSION]->Evaluate(token, SEMANTIC_STATES::SEXPRESSION);
		token = NextToken();
		if (token.svalue != ")")
		{
			m_errorHandler->AddError(ERROR25, "sintactico", token.line);
		}
	}
	else if ( token.itype == LEXIC_STATES::lNUMBERINT || token.itype == LEXIC_STATES::lNUMBERFLOAT || token.itype == LEXIC_STATES::lCONSTANTALFANUMERIC)
	{
		(*expressionPosfija).push_back(token);
		return SEMANTIC_STATES::E();
	}
	else if (token.itype == LEXIC_STATES::lID)
	{
		(*expressionPosfija).push_back(token);
		token = NextToken();
		if (token.svalue == "[")
		{
			(*expressionPosfija).push_back(token);
			(*m_States)[SEMANTIC_STATES::SEXPRESSION]->Evaluate(token, SEMANTIC_STATES::SEXPRESSION);
			token = NextToken();
			(*expressionPosfija).push_back(token);

			if (token.svalue != "]")
			{
				m_errorHandler->AddError(ERROR12, "Sintactico", token.line);
				while (token.svalue != ")" && token.svalue != "NULL")
				{
					token = NextToken();
				}
				return SEMANTIC_STATES::SPROGRAM;
			}
		}
		else if (token.svalue == "(")
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
			(*m_indexToken)--;
		}
	}
	else if (token.svalue == "!" || token.svalue == "-")
	{
		(*expressionPosfija).push_back(token);
		(*m_States)[SEMANTIC_STATES::STERM]->Evaluate(token, SEMANTIC_STATES::STERM, "", expressionPosfija, NULL);
	}
	else
	{
		m_errorHandler->AddError(ERROR26, "sintactico", token.line);
		token = NextToken();
		if (token.svalue == "(" || (token.itype == LEXIC_STATES::lID) || (token.itype == LEXIC_STATES::lNUMBERINT || token.itype == LEXIC_STATES::lNUMBERFLOAT || token.itype == LEXIC_STATES::lCONSTANTALFANUMERIC) || (token.svalue == "!")) {
			(*m_indexToken)--;
			(*m_States)[SEMANTIC_STATES::STERM]->Evaluate(token, SEMANTIC_STATES::STERM, "", expressionPosfija, NULL);
		}
		else
		{
			(*m_indexToken)--;
		}

	}
	return SEMANTIC_STATES::E();
}

SEMANTIC_STATES::E CSemTerm::Evaluate(Token token, SEMANTIC_STATES::E oldState, std::string parent)
{
	return SEMANTIC_STATES::E();
}

CSemTerm::CSemTerm()
{
}


CSemTerm::~CSemTerm()
{
}
