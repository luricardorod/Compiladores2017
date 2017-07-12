#include "CSExpression.h"



SYNTACTIC_STATES::E CSExpression::Evaluate(Token token, SYNTACTIC_STATES::E oldState, std::string parent)
{
	(*m_States)[SYNTACTIC_STATES::STERM]->Evaluate(token, SYNTACTIC_STATES::SEXPRESSION);

	if (isOperator())
	{
		(*m_States)[SYNTACTIC_STATES::STERM]->Evaluate(token, SYNTACTIC_STATES::SEXPRESSION);
	}
	else
	{
		(*m_indexToken)--;
	}

	return SYNTACTIC_STATES::E();
}

CSExpression::CSExpression()
{
}


CSExpression::~CSExpression()
{
}
