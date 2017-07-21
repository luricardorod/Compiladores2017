#include "CSProgram.h"

SYNTACTIC_STATES::E CSProgram::Evaluate(Token token, SYNTACTIC_STATES::E oldState, std::string parent)
{
	bool phaseVar = false;
	bool phaseFuncProc = false;
	bool phaseMain = false;

	while (token.svalue != "NULL")
	{
		if (token.svalue == "var")
		{
			if (phaseVar)
			{
				m_errorHandler->AddError(ERROR30, "sintactico", token.line);
			}
			(*m_States)[SYNTACTIC_STATES::SVAR]->Evaluate(token, SYNTACTIC_STATES::SPROGRAM);
		}
		else if (token.svalue == "function" || token.svalue == "procedure")
		{
			phaseVar = true;
			if (phaseFuncProc)
			{
				m_errorHandler->AddError(ERROR31, "sintactico", token.line);
			}
			if (token.svalue == "function")
			{
				token = NextToken();
				(*m_States)[SYNTACTIC_STATES::SFUNCTION]->Evaluate(token, SYNTACTIC_STATES::SPROGRAM);
			}
			else
			{
				token = NextToken();
				(*m_States)[SYNTACTIC_STATES::SPROCESS]->Evaluate(token, SYNTACTIC_STATES::SPROGRAM);
				(*m_indexToken)--;
			}
		}
		else if (token.svalue == "main")
		{
			phaseFuncProc = true;
			if (phaseMain)
			{
				m_errorHandler->AddError(ERROR32, "sintactico", token.line);
			}
			phaseMain = true;
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
			(*m_States)[SYNTACTIC_STATES::SBlock]->Evaluate(token, SYNTACTIC_STATES::SPROCESS, "main");
		}
		token = NextToken();

	}
	if (!phaseMain)
	{
		m_errorHandler->AddError(ERROR17, "sintactico");
	}
	return SYNTACTIC_STATES::SPROGRAM;
}

CSProgram::CSProgram()
{
}


CSProgram::~CSProgram()
{
}
