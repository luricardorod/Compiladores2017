#pragma once
#include "CSyntacticStates.h"
class CSIf :public CSyntacticStates
{
public:
	virtual SYNTACTIC_STATES::E Evaluate(Token token, SYNTACTIC_STATES::E oldState, std::string parent);
	CSIf();
	~CSIf();
};