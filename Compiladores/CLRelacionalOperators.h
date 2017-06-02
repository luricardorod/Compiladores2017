#pragma once
#include "CLexicalStates.h"
class CLRelacionalOperators : public CLexicalStates
{
public:
	virtual LEXIC_STATES::E Evaluate(char character);
	virtual LEXIC_STATES::E Enter(char character, std::string string);
	virtual std::string Exit();
	bool m_bflagminmax;
	bool m_bchangeState;
	CLRelacionalOperators();
	~CLRelacionalOperators();
};