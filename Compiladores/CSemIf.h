#pragma once
#include "CSemanticStates.h"
class CSemIf :public CSemanticStates
{
public:
	virtual SEMANTIC_STATES::E Evaluate(Token token, SEMANTIC_STATES::E oldState, std::string parent);
	CSemIf();
	~CSemIf();
};
