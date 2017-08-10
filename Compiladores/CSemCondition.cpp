#include "CSemCondition.h"


SEMANTIC_STATES::E CSemCondition::Evaluate(Token token, SEMANTIC_STATES::E oldState, std::string parent)
{
	(*m_States)[SEMANTIC_STATES::STERM]->Evaluate(token, SEMANTIC_STATES::SEXPRESSION);
	token = NextToken();
	if (token.itype != LEXIC_STATES::lRELACIONALOPERATORS)
	{
		m_errorHandler->AddError(ERROR34, "sintactico", token.line);
	}
	(*m_States)[SEMANTIC_STATES::STERM]->Evaluate(token, SEMANTIC_STATES::SEXPRESSION);
	token = NextToken();

	if (token.svalue != ";")
	{
		m_errorHandler->AddError(ERROR10, "sintactico", token.line);
	}
	return SEMANTIC_STATES::E();
}

CSemCondition::CSemCondition()
{
}


CSemCondition::~CSemCondition()
{
}
