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
		else if (token.svalue == "if" || token.svalue == "while")
		{
			token = NextToken();
			if (token.svalue != "(")
			{
				m_errorHandler->AddError(ERROR19, "sintactico", token.line);
				token = NextToken();
				
				if (token.svalue != "(")
				{
					(*m_indexToken) -= 2;
				}
				else
				{
					(*m_indexToken)--;
				}
			}
			(*m_States)[SYNTACTIC_STATES::SEXPRESSION]->Evaluate(token, SYNTACTIC_STATES::SBlock, "");
			token = NextToken();
			if (token.svalue != ")")
			{
				m_errorHandler->AddError(ERROR25, "sintactico", token.line);
				(*m_indexToken)--;
			}
			(*m_States)[SYNTACTIC_STATES::SBlock]->Evaluate(token, SYNTACTIC_STATES::SBlock);
		}
		else if (token.svalue == "for")
		{
			token = NextToken();
			if (token.svalue != "(")
			{
				m_errorHandler->AddError(ERROR19, "sintactico", token.line);
			}
			token = NextToken();
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
				(*m_States)[SYNTACTIC_STATES::SEXPRESSION]->Evaluate(token, SYNTACTIC_STATES::SBlock);
				token = NextToken();

				if (token.svalue != ";")
				{
					m_errorHandler->AddError(ERROR10, "sintactico", token.line);
				}
			}
			(*m_States)[SYNTACTIC_STATES::SEXPRESSION]->Evaluate(token, SYNTACTIC_STATES::SBlock);
			token = NextToken();
			if (token.svalue != ";")
			{
				m_errorHandler->AddError(ERROR10, "sintactico", token.line);
			}
			(*m_States)[SYNTACTIC_STATES::SEXPRESSION]->Evaluate(token, SYNTACTIC_STATES::SBlock);
			if (token.svalue != ")")
			{
				m_errorHandler->AddError(ERROR25, "sintactico", token.line);
			}
			(*m_States)[SYNTACTIC_STATES::SBlock]->Evaluate(token, SYNTACTIC_STATES::SBlock);

		}
		else if (token.svalue == "switch")
		{

		}
		else if (token.itype == LEXIC_STATES::lID)
		{
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
				(*m_States)[SYNTACTIC_STATES::SEXPRESSION]->Evaluate(token, SYNTACTIC_STATES::SBlock);
				token = NextToken();

				if (token.svalue != ";")
				{
					m_errorHandler->AddError(ERROR10, "sintactico", token.line);
				}
			}
			else if (token.svalue == "(")
			{
				(*m_States)[SYNTACTIC_STATES::SEXPRESSION]->Evaluate(token, SYNTACTIC_STATES::SBlock);
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
				token = NextToken();
				if (token.svalue != ";")
				{
					m_errorHandler->AddError(ERROR10, "sintactico", token.line);
					(*m_indexToken)--;
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
	return SYNTACTIC_STATES::E();
}

CSBlock::CSBlock()
{
}


CSBlock::~CSBlock()
{
}
