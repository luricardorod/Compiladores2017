#include "CSProgram.h"

SYNTACTIC_STATES::E CSProgram::Evaluate(Token token, SYNTACTIC_STATES::E oldState, std::string parent)
{
	
	if (token.itype == LEXIC_STATES::lKEYWORD)
	{
		while (token.svalue == "var")
		{
			(*m_States)[SYNTACTIC_STATES::SVAR]->Evaluate(token, SYNTACTIC_STATES::SPROGRAM);
			token = NextToken();
		}
		while (token.svalue == "function" || token.svalue == "procedure")
		{
			if (token.svalue == "function")
			{
				token = NextToken();
				(*m_States)[SYNTACTIC_STATES::SFUNCTION]->Evaluate(token, SYNTACTIC_STATES::SPROGRAM);
				token = NextToken();
			}
			else
			{
				token = NextToken();
				(*m_States)[SYNTACTIC_STATES::SPROCESS]->Evaluate(token, SYNTACTIC_STATES::SPROGRAM);
				(*m_indexToken)--;
				token = NextToken();
			}
		}
		bool flag = true;
		while (token.svalue != "main" && token.svalue != "NULL")
		{
			if (flag)
			{
				flag = false;
				m_errorHandler->AddError(ERROR28, "sintactico", token.line);
			}
			token = NextToken();
		}
		if (token.svalue == "main")
		{
			token = NextToken();
			if (token.svalue != "(")
			{
				m_errorHandler->AddError(ERROR19, "sintactico", token.line);
				while (token.svalue != "{" && token.svalue != "NULL")
				{
					token = NextToken();
				}
			}
			token = NextToken();
			if (token.svalue != ")")
			{
				m_errorHandler->AddError(ERROR25, "sintactico", token.line);
			}
			(*m_States)[SYNTACTIC_STATES::SBlock]->Evaluate(token, SYNTACTIC_STATES::SPROGRAM, "main");
		}
		else
		{
			m_errorHandler->AddError(ERROR17, "sintactico");
		}
	}
	return SYNTACTIC_STATES::SPROGRAM;
}

CSProgram::CSProgram()
{
}


CSProgram::~CSProgram()
{
}
