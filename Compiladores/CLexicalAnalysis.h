#pragma once
#include <string>
#include <vector>
#include "CLexicalStates.h"
 #include "CTokenizer.h"
#include "CErrorHandler.h"

class CLexicalAnalysis
{
public:
	CTokenizer* m_tokenaizer;
	CErrorHandler* m_errorHandler;
	void Compile(std::string* file, CTokenizer* tokenaizer, CErrorHandler* errorHandler);
	std::vector<CLexicalStates*> m_States;
	LEXIC_STATES::E m_iActiveState;
	CLexicalAnalysis();
	~CLexicalAnalysis();
};