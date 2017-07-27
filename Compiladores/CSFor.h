#pragma once
#include "CSyntacticStates.h"
class CSFor :public CSyntacticStates
{
public:
	virtual SYNTACTIC_STATES::E Evaluate(Token token, SYNTACTIC_STATES::E oldState, std::string parent);
	CSFor();
	~CSFor();
};