#include "CSSwitch.h"



SYNTACTIC_STATES::E CSSwitch::Evaluate(Token token, SYNTACTIC_STATES::E oldState, std::string parent)
{
	token = NextToken();
	if (token.svalue != "(")
	{
		m_errorHandler->AddError(ERROR19, "sintactico", token.line);
	}
	token = NextToken();

	if (token.itype != LEXIC_STATES::lID)
	{
		m_errorHandler->AddError(ERROR33, "sintactico", token.line);
	}
	token = NextToken();

	if (token.svalue != ")")
	{
		m_errorHandler->AddError(ERROR25, "sintactico", token.line);
	}
	token = NextToken();
	if (token.svalue != "{")
	{
		m_errorHandler->AddError(ERROR21, "sintactico", token.line);
	}
	token = NextToken();
	while (token.itype == LEXIC_STATES::lNUMBERINT)
	{
		token = NextToken();
		if (token.svalue != ":")
		{
			m_errorHandler->AddError(ERROR21, "sintactico", token.line);
		}
		(*m_States)[SYNTACTIC_STATES::SBLOCK]->Evaluate(token, oldState, parent);
		token = NextToken();
	}
	if (token.svalue != "default")
	{
		token = NextToken();
		if (token.svalue != ":")
		{
			m_errorHandler->AddError(ERROR21, "sintactico", token.line);
		}
		(*m_States)[SYNTACTIC_STATES::SBLOCK]->Evaluate(token, oldState, parent);
		token = NextToken();
	}
	if (token.svalue != "}")
	{
		m_errorHandler->AddError(ERROR27, "sintactico", token.line);
	}
	return SYNTACTIC_STATES::E();
}

CSSwitch::CSSwitch()
{
}


CSSwitch::~CSSwitch()
{
}
