#include "CSCondition.h"



SYNTACTIC_STATES::E CSCondition::Evaluate(Token token, SYNTACTIC_STATES::E oldState, std::string parent)
{
	(*m_States)[SYNTACTIC_STATES::STERM]->Evaluate(token, SYNTACTIC_STATES::SEXPRESSION);
	token = NextToken();
	if (token.itype != LEXIC_STATES::lRELACIONALOPERATORS)
	{
		m_errorHandler->AddError(ERROR34, "sintactico", token.line);
	}
	(*m_States)[SYNTACTIC_STATES::STERM]->Evaluate(token, SYNTACTIC_STATES::SEXPRESSION);
	token = NextToken();

	if (token.svalue != ";")
	{
		m_errorHandler->AddError(ERROR10, "sintactico", token.line);
	}
	return SYNTACTIC_STATES::E();
}

CSCondition::CSCondition()
{
}


CSCondition::~CSCondition()
{
}
