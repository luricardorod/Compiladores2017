#pragma once
#include "CLexicalStates.h"
class CLComments : public CLexicalStates
{
public:
	virtual LEXIC_STATES::E Evaluate(char character);
	virtual LEXIC_STATES::E Enter(char character, std::string string);
	virtual std::string Exit();
	bool m_bflagClose;
	bool m_bflagChangeState;


	CLComments();
	~CLComments();
};