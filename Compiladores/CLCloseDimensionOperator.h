#pragma once
#include "CLexicalStates.h"

class CLCloseDimensionOperator : public CLexicalStates
{
public:
	virtual LEXIC_STATES::E Evaluate(char character);
	virtual LEXIC_STATES::E Enter(char character, std::string string);
	virtual std::string Exit();
	CLCloseDimensionOperator();
	~CLCloseDimensionOperator();
};