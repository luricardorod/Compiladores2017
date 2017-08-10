#include "CSemExpression.h"


SEMANTIC_STATES::E CSemExpression::Evaluate(Token token, SEMANTIC_STATES::E oldState, std::string parent)
{
	(*m_States)[SEMANTIC_STATES::STERM]->Evaluate(token, SEMANTIC_STATES::SEXPRESSION);

	if (isOperator())
	{
		(*m_States)[SEMANTIC_STATES::SEXPRESSION]->Evaluate(token, SEMANTIC_STATES::SEXPRESSION);
	}
	else
	{
		(*m_indexToken)--;
	}

	return SEMANTIC_STATES::E();
}

CSemExpression::CSemExpression()
{
}


CSemExpression::~CSemExpression()
{
}
