#pragma once
#include <vector>
#include "CTokenizer.h"
#include "CErrorHandler.h"
#include "CSyntacticStates.h"
#include "NodesVars.h"
class CSyntacticAnalysis
{
public:
	CTokenizer* m_tokenaizer;
	CErrorHandler* m_errorHandler;
	CNodesVars* m_nodes;
	int m_indexToken;
	SYNTACTIC_STATES::E m_iActiveState;
	std::vector<CSyntacticStates*> m_States;

	void Compile(CTokenizer* tokenaizer, CErrorHandler* errorHandler, CNodesVars* nodes);
	CSyntacticAnalysis();
	~CSyntacticAnalysis();
};

