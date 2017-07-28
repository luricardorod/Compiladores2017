#pragma once
#include "CSyntacticStates.h"
class CSCondition :public CSyntacticStates
{
public:
	virtual SYNTACTIC_STATES::E Evaluate(Token token, SYNTACTIC_STATES::E oldState, std::string parent);
	CSCondition();
	~CSCondition();
};