#include "CSemProgram.h"

SEMANTIC_STATES::E CSemProgram::Evaluate(Token token, SEMANTIC_STATES::E oldState, std::string parent)
{


	while (token.svalue != "NULL")
	{
		if (token.svalue == "var")
		{
			(*m_States)[SEMANTIC_STATES::SVAR]->Evaluate(token, SEMANTIC_STATES::SPROGRAM);
		}
		else if (token.svalue == "function" || token.svalue == "procedure")
		{
			if (token.svalue == "function")
			{
				token = NextToken();
				(*m_States)[SEMANTIC_STATES::SFUNCTION]->Evaluate(token, SEMANTIC_STATES::SPROGRAM);
			}
			else
			{
				token = NextToken();
				(*m_States)[SEMANTIC_STATES::SPROCESS]->Evaluate(token, SEMANTIC_STATES::SPROGRAM);
				(*m_indexToken)--;
			}
		}
		else if (token.svalue == "main")
		{
			(*m_name) = "main";
			token = NextToken();
			token = NextToken();
			(*m_States)[SEMANTIC_STATES::SBLOCK]->Evaluate(token, SEMANTIC_STATES::SPROCESS, "main");
			(*m_name) = "NULL";
		}
		token = NextToken();

	}

	return SEMANTIC_STATES::SPROGRAM;
}

CSemProgram::CSemProgram()
{
}


CSemProgram::~CSemProgram()
{
}
