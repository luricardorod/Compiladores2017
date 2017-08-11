#include "CSBlock.h"



SYNTACTIC_STATES::E CSBlock::Evaluate(Token token, SYNTACTIC_STATES::E oldState, std::string parent)
{
	token = NextToken();
	if (token.svalue != "{")
	{
		m_errorHandler->AddError(ERROR21, "sintactico", token.line);
		while (token.svalue != "}" && token.svalue != "NULL")
		{
			token = NextToken();
		}
		return SYNTACTIC_STATES::E();
	}

	token = NextToken();
	while (token.svalue != "}" && token.svalue != "NULL")
	{
		if (token.svalue == ";") {

		}
		else if (token.svalue == "var")
		{
			if (oldState == SYNTACTIC_STATES::SPROCESS || oldState == SYNTACTIC_STATES::SFUNCTION || oldState == SYNTACTIC_STATES::SPROGRAM)
			{
				(*m_States)[SYNTACTIC_STATES::SVAR]->Evaluate(token, oldState, parent);
			}
			else
			{
				m_errorHandler->AddError(ERROR29, "sintactico", token.line);
				while (token.svalue != ";" && token.svalue != "NULL")
				{
					token = NextToken();
				}
			}
		}
		else if (token.svalue == "if" || token.svalue == "while")
		{
			(*m_States)[SYNTACTIC_STATES::SIF]->Evaluate(token, SYNTACTIC_STATES::SBLOCK);

			
		}
		else if (token.svalue == "for")
		{
			(*m_States)[SYNTACTIC_STATES::SFOR]->Evaluate(token, SYNTACTIC_STATES::SBLOCK);

		}
		else if (token.svalue == "switch")
		{
			(*m_States)[SYNTACTIC_STATES::SSWITCH]->Evaluate(token, SYNTACTIC_STATES::SBLOCK);

		}
		else if (token.itype == LEXIC_STATES::lID)
		{
			(*m_States)[SYNTACTIC_STATES::SASSINGCALL]->Evaluate(token, SYNTACTIC_STATES::SBLOCK);

		}
		else if (token.svalue == "return")
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
			m_errorHandler->AddError(ERROR22, "sintactico", token.line);
		}
		token = NextToken();
	}
	
	if (token.svalue != "}")
	{
		m_errorHandler->AddError(ERROR27, "sintactico", token.line);
	}
	return SYNTACTIC_STATES::E();
}

CSBlock::CSBlock()
{
}


CSBlock::~CSBlock()
{
}
