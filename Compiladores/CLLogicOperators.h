#pragma once
#include "CLexicalStates.h"
class CLLogicOperators : public CLexicalStates
{
public:
	virtual LEXIC_STATES::E Evaluate(char character);
	virtual LEXIC_STATES::E Enter(char character, std::string string);
	virtual std::string Exit();
	bool m_bflagOr;
	bool m_bflagNegate;
	bool m_bflagChangeState;
	CLLogicOperators();
	~CLLogicOperators();
};