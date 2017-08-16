#include "CSemCondition.h"


SEMANTIC_STATES::E CSemCondition::Evaluate(Token token, SEMANTIC_STATES::E oldState, std::string parent)
{
	(*m_States)[SEMANTIC_STATES::STERM]->Evaluate(token, SEMANTIC_STATES::SEXPRESSION);
	token = NextToken();
	
	(*m_States)[SEMANTIC_STATES::STERM]->Evaluate(token, SEMANTIC_STATES::SEXPRESSION);
	token = NextToken();

	
	return SEMANTIC_STATES::E();
}

CSemCondition::CSemCondition()
{
}


CSemCondition::~CSemCondition()
{
}
