#pragma once
#include "CSemanticStates.h"

class CSemTerm :public CSemanticStates
{
public:
	virtual SEMANTIC_STATES::E Evaluate(Token token, SEMANTIC_STATES::E oldState, std::string parent);
	virtual SEMANTIC_STATES::E Evaluate(Token token, SEMANTIC_STATES::E oldState, std::string parent, std::vector<Token>* expressionPosfija, std::vector<Token>* operators);
	CSemTerm();
	~CSemTerm();
};
