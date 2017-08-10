#include "CSProcess.h"

SYNTACTIC_STATES::E CSProcess::Evaluate(Token token, SYNTACTIC_STATES::E oldState, std::string parent)
{
	GlobalNode tempGlobal;
	tempGlobal.m_category = "procedure";
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
		int i = GroupParams(tempGlobal.m_name, &tempGlobal.m_values);
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
			return SYNTACTIC_STATES::E();
		}
		
		tempGlobal.m_type = "NULL";
		tempGlobal.m_dimension = tempGlobal.m_values.size();
		m_nodes->addGlobalNode(tempGlobal, token.line);
		(*m_States)[SYNTACTIC_STATES::SBLOCK]->Evaluate(token, SYNTACTIC_STATES::SFUNCTION, tempGlobal.m_name);
		////////////block

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

CSProcess::CSProcess()
{
}


CSProcess::~CSProcess()
{
}
