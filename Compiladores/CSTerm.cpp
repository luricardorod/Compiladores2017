#include "CSTerm.h"



SYNTACTIC_STATES::E CSTerm::Evaluate(Token token, SYNTACTIC_STATES::E oldState, std::string parent)
{
	token = NextToken();
	if (token.svalue == "(")
	{
		(*m_States)[SYNTACTIC_STATES::SEXPRESSION]->Evaluate(token, SYNTACTIC_STATES::SEXPRESSION);
	}
	else if (token.itype == LEXIC_STATES::lNUMBERINT)
	{
		return SYNTACTIC_STATES::E();
	}
	else if (token.itype == LEXIC_STATES::lID)
	{
		token = NextToken();
		if (token.svalue == "[")
		{
			int dim = ProcessDimension();
			if (dim == -1)
			{
				m_errorHandler->AddError(ERROR8, "Sintactico", token.line);
				while (token.svalue != ")" && token.svalue != "NULL")
				{
					token = NextToken();
				}
				return SYNTACTIC_STATES::SPROGRAM;
			}
			else if (dim == -2)
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
			int i = GroupIds();
			if (i)
			{
				m_errorHandler->AddError(ERROR23, "sintactico", token.line);
				while (token.svalue != ")" && token.svalue != "NULL")
				{
					token = NextToken();
				}
				return SYNTACTIC_STATES::E();
			}
		}
		else
		{
			(*m_indexToken)--;
		}
	}
	else
	{
		m_errorHandler->AddError(ERROR26, "sintactico", token.line);
	}
	return SYNTACTIC_STATES::E();
}

CSTerm::CSTerm()
{
}


CSTerm::~CSTerm()
{
}
