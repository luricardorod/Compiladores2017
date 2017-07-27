#pragma once
#include "CSyntacticStates.h" 
class CSSwitch :public CSyntacticStates
{
public:
	virtual SYNTACTIC_STATES::E Evaluate(Token token, SYNTACTIC_STATES::E oldState, std::string parent);
	CSSwitch();
	~CSSwitch();
};
