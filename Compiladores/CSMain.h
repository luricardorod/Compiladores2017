#pragma once
#include "CSyntacticStates.h"

class CSMain :public CSyntacticStates
{
public:
	virtual SYNTACTIC_STATES::E Evaluate(Token token, SYNTACTIC_STATES::E oldState, std::string parent);



	CSMain();
	~CSMain();
};

