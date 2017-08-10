#include "CSemProcess.h"

SEMANTIC_STATES::E CSemProcess::Evaluate(Token token, SEMANTIC_STATES::E oldState, std::string parent)
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
		return SEMANTIC_STATES::E();
	}
	tempGlobal.m_name = token.svalue;

	token = NextToken();
	if (token.svalue == "(")
	{
		int i = GroupParams(tempGlobal.m_name);
		if (i != 0)
		{
			if (i == 4)
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
			return SEMANTIC_STATES::E();
		}

		tempGlobal.m_type = "NULL";

		m_nodes->addGlobalNode(tempGlobal, token.line);
		(*m_States)[SEMANTIC_STATES::SBLOCK]->Evaluate(token, SEMANTIC_STATES::SFUNCTION, tempGlobal.m_name);
		////////////block

	}
	else
	{
		m_errorHandler->AddError(ERROR7, "sintactico", token.line);
		while (token.svalue != "}" && token.svalue != "NULL")
		{
			token = NextToken();
		}
		return SEMANTIC_STATES::E();
	}
	return SEMANTIC_STATES::E();
}

CSemProcess::CSemProcess()
{
}


CSemProcess::~CSemProcess()
{
}
