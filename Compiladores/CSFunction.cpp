#include "CSFunction.h"



SYNTACTIC_STATES::E CSFunction::Evaluate(Token token, SYNTACTIC_STATES::E oldState, std::string parent)
{
	GlobalNode tempGlobal;
	tempGlobal.m_category = "function";
	tempGlobal.m_type = "NULL";
	tempGlobal.m_dimension = 0;
	if (token.itype != LEXIC_STATES::lID)
	{
		m_errorHandler->AddError(ERROR7, "sintactico", token.line);
		while (token.svalue != "}" && token.svalue != "NULL")
		{
			token = NextToken();
		}
		return SYNTACTIC_STATES::E();
	}
	tempGlobal.m_name = token.svalue;

	token = NextToken();
	if (token.svalue == "(")
	{
		int i = GroupParams();
		if (i != 0)
		{
			if (i==4)
			{
				m_errorHandler->AddError(ERROR20, "sintactico", token.line);
			}
			else if (i == 3)
			{
				m_errorHandler->AddError(ERROR7, "sintactico", token.line);

			}
			else if (i == 2)
			{
				m_errorHandler->AddError(ERROR11, "sintactico", token.line);
			}
			else if (i == 1)
			{
				m_errorHandler->AddError(ERROR9, "sintactico", token.line);
			}
			while (token.svalue != "}" && token.svalue != "NULL")
			{
				token = NextToken();
			}
			return SYNTACTIC_STATES::E();
		}

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

		m_nodes->addGlobalNode(tempGlobal, token.line);
		////////////block
		while (token.svalue != "}" && token.svalue != "NULL")
		{
			token = NextToken();
		}
	}
	else
	{
		m_errorHandler->AddError(ERROR7, "sintactico", token.line);
		while (token.svalue != "}" && token.svalue != "NULL")
		{
			token = NextToken();
		}
		return SYNTACTIC_STATES::E();
	}
	return SYNTACTIC_STATES::E();
}

CSFunction::CSFunction()
{
}


CSFunction::~CSFunction()
{
}
