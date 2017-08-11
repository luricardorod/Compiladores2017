#include "CSemExpression.h"


SEMANTIC_STATES::E CSemExpression::Evaluate(Token token, SEMANTIC_STATES::E oldState, std::string parent)
{
	std::vector<Token> expressionPosfija;
	std::vector<Token> operators;
	(*m_States)[SEMANTIC_STATES::STERM]->Evaluate(token, SEMANTIC_STATES::SEXPRESSION, "", &expressionPosfija, &operators);
	token = NextToken();

	if (isOperator(token))
	{
		operators.push_back(token);
		(*m_States)[SEMANTIC_STATES::SEXPRESSION]->Evaluate(token, SEMANTIC_STATES::SEXPRESSION, "", &expressionPosfija, &operators);
	}
	else
	{
		(*m_indexToken)--;
	}

	return SEMANTIC_STATES::E();
}

SEMANTIC_STATES::E CSemExpression::Evaluate(Token token, SEMANTIC_STATES::E oldState, std::string parent, std::vector<Token>* expressionPosfija, std::vector<Token>* operators)
{
	(*m_States)[SEMANTIC_STATES::STERM]->Evaluate(token, SEMANTIC_STATES::SEXPRESSION, "", expressionPosfija, operators);
	token = NextToken();

	if (isOperator(token))
	{
		(*operators).push_back(token);
		(*m_States)[SEMANTIC_STATES::SEXPRESSION]->Evaluate(token, SEMANTIC_STATES::SEXPRESSION, "", expressionPosfija, operators);
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
