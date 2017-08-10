#include "CSemBlock.h"


SEMANTIC_STATES::E CSemBlock::Evaluate(Token token, SEMANTIC_STATES::E oldState, std::string parent)
{
	token = NextToken();
	if (token.svalue != "{")
	{
		while (token.svalue != "}" && token.svalue != "NULL")
		{
			token = NextToken();
		}
		return SEMANTIC_STATES::E();
	}

	token = NextToken();
	while (token.svalue != "}" && token.svalue != "NULL")
	{
		if (token.svalue == ";") {

		}
		else if (token.svalue == "var")
		{
			if (oldState == SEMANTIC_STATES::SPROCESS || oldState == SEMANTIC_STATES::SFUNCTION || oldState == SEMANTIC_STATES::SPROGRAM)
			{
				(*m_States)[SEMANTIC_STATES::SVAR]->Evaluate(token, oldState, parent);
			}
			else
			{
				while (token.svalue != ";" && token.svalue != "NULL")
				{
					token = NextToken();
				}
			}
		}
		else if (token.svalue == "if" || token.svalue == "while")
		{
			(*m_States)[SEMANTIC_STATES::SIF]->Evaluate(token, SEMANTIC_STATES::SBLOCK);
		}
		else if (token.svalue == "for")
		{
			(*m_States)[SEMANTIC_STATES::SFOR]->Evaluate(token, SEMANTIC_STATES::SBLOCK);
		}
		else if (token.svalue == "switch")
		{
			(*m_States)[SEMANTIC_STATES::SSWITCH]->Evaluate(token, SEMANTIC_STATES::SBLOCK);
		}
		else if (token.itype == LEXIC_STATES::lID)
		{
			(*m_States)[SEMANTIC_STATES::SASSINGCALL]->Evaluate(token, SEMANTIC_STATES::SBLOCK);
		}
		else if (token.svalue == "return")
		{
			token = NextToken();
			if (token.svalue != ";")
			{
				(*m_indexToken)--;
				(*m_States)[SEMANTIC_STATES::SEXPRESSION]->Evaluate(token, SEMANTIC_STATES::SBLOCK);
				token = NextToken();
				if (token.svalue != ";")
				{
					m_errorHandler->AddError(ERROR10, "sintactico", token.line);
				}
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
	return SEMANTIC_STATES::E();
}

CSemBlock::CSemBlock()
{
}


CSemBlock::~CSemBlock()
{
}
