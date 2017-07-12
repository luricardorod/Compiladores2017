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
		if (token.svalue == "var")
		{
			(*m_States)[SYNTACTIC_STATES::SVAR]->Evaluate(token, oldState, parent);
		}
		else if (token.svalue == "if")
		{
			token = NextToken();
			if (token.svalue != "(")
			{
				m_errorHandler->AddError(ERROR19, "sintactico", token.line);
				while (token.svalue != ")" && token.svalue != "NULL")
				{
					token = NextToken();
				}
				return SYNTACTIC_STATES::E();
			}
			(*m_States)[SYNTACTIC_STATES::SEXPRESSION]->Evaluate(token, SYNTACTIC_STATES::SBlock, "");
			token = NextToken();
			if (token.svalue != ")")
			{
				m_errorHandler->AddError(ERROR25, "sintactico", token.line);
				while (token.svalue != ")" && token.svalue != "NULL")
				{
					token = NextToken();
				}
				return SYNTACTIC_STATES::E();
			}
			(*m_States)[SYNTACTIC_STATES::SBlock]->Evaluate(token, SYNTACTIC_STATES::SBlock);
		}
		else if (token.svalue == "for")
		{

		}
		else if (token.svalue == "while")
		{

		}
		else if (token.svalue == "switch")
		{

		}
		else if (token.itype == LEXIC_STATES::lID)
		{

		}
		else if (token.svalue == "}")
		{
			return SYNTACTIC_STATES::E();
		}
		else
		{
			m_errorHandler->AddError(ERROR22, "sintactico", token.line);
			while (token.svalue != "}" && token.svalue != "NULL")
			{
				token = NextToken();
			}
			return SYNTACTIC_STATES::E();
		}
		token = NextToken();
	}
	
	if (token.svalue != "}")
	{
		m_errorHandler->AddError(ERROR27, "sintactico");
	}
	return SYNTACTIC_STATES::E();
}

CSBlock::CSBlock()
{
}


CSBlock::~CSBlock()
{
}
