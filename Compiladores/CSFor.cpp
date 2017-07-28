#include "CSFor.h"

SYNTACTIC_STATES::E CSFor::Evaluate(Token token, SYNTACTIC_STATES::E oldState, std::string parent)
{
	token = NextToken();
	if (token.svalue != "(")
	{
		m_errorHandler->AddError(ERROR19, "sintactico", token.line);
	}
	token = NextToken();
	(*m_States)[SYNTACTIC_STATES::SASSINGCALL]->Evaluate(token, SYNTACTIC_STATES::SFOR);

	(*m_States)[SYNTACTIC_STATES::SCONDITIONAL]->Evaluate(token, SYNTACTIC_STATES::SFOR);

	(*m_States)[SYNTACTIC_STATES::SEXPRESSION]->Evaluate(token, SYNTACTIC_STATES::SFOR);
	/*		
	token = NextToken();

	if (token.svalue == "=")
	{
		token = NextToken();

		if (token.itype != LEXIC_STATES::lID && token.itype != LEXIC_STATES::lNUMBERINT && token.itype != LEXIC_STATES::lNUMBERFLOAT && token.itype != LEXIC_STATES::lCONSTANTALFANUMERIC)
		{
			m_errorHandler->AddError(ERROR10, "sintactico", token.line);
			token = NextToken();

			if (token.itype != LEXIC_STATES::lID && token.itype != LEXIC_STATES::lNUMBERINT && token.itype != LEXIC_STATES::lNUMBERFLOAT && token.itype != LEXIC_STATES::lCONSTANTALFANUMERIC)
			{
				while (token.svalue != ";" && token.svalue != "}" && token.svalue != "NULL")
				{
					token = NextToken();
				}
			}
		}
		(*m_indexToken)--;
		(*m_States)[SYNTACTIC_STATES::SEXPRESSION]->Evaluate(token, SYNTACTIC_STATES::SBLOCK);
		token = NextToken();

		if (token.svalue != ";")
		{
			m_errorHandler->AddError(ERROR10, "sintactico", token.line);
		}
	}
	(*m_States)[SYNTACTIC_STATES::SEXPRESSION]->Evaluate(token, SYNTACTIC_STATES::SBLOCK);
	token = NextToken();
	if (token.svalue != ";")
	{
		m_errorHandler->AddError(ERROR10, "sintactico", token.line);
	}
	(*m_States)[SYNTACTIC_STATES::SEXPRESSION]->Evaluate(token, SYNTACTIC_STATES::SBLOCK);*/
	token = NextToken();
	if (token.svalue != ")")
	{
		m_errorHandler->AddError(ERROR25, "sintactico", token.line);
	}
	(*m_States)[SYNTACTIC_STATES::SBLOCK]->Evaluate(token, SYNTACTIC_STATES::SBLOCK);
	return SYNTACTIC_STATES::E();
}

CSFor::CSFor()
{
}


CSFor::~CSFor()
{
}
