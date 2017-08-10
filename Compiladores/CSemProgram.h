#pragma once
#include "CSemanticStates.h"

class CSemProgram :public CSemanticStates
{
public:
	virtual SEMANTIC_STATES::E Evaluate(Token token, SEMANTIC_STATES::E oldState, std::string parent);

	CSemProgram();
	~CSemProgram();
};
