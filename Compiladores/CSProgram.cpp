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
				token = NextToken();
			}
		}
		if (token.svalue == "main")
		{

		}
		else
		{
			m_errorHandler->AddError(ERROR17, "sintactico");
		}
	}
	else
	{
		//error se esperaba var main func proc
	}
	return SYNTACTIC_STATES::SPROGRAM;
}

CSProgram::CSProgram()
{
}


CSProgram::~CSProgram()
{
}
