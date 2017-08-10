#include "CSemSwitch.h"



SEMANTIC_STATES::E CSemSwitch::Evaluate(Token token, SEMANTIC_STATES::E oldState, std::string parent)
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
		(*m_States)[SEMANTIC_STATES::SBLOCK]->Evaluate(token, oldState, parent);
		token = NextToken();
	}
	if (token.svalue != "}")
	{
		m_errorHandler->AddError(ERROR27, "sintactico", token.line);
	}
	return SEMANTIC_STATES::E();
}

CSemSwitch::CSemSwitch()
{
}


CSemSwitch::~CSemSwitch()
{
}
