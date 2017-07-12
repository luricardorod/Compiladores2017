#pragma once
#include "CSyntacticStates.h"
class CSVar :public CSyntacticStates
{
public:
	
	virtual SYNTACTIC_STATES::E Evaluate(Token token, SYNTACTIC_STATES::E oldState, std::string parent);

	CSVar();
	~CSVar();
};

