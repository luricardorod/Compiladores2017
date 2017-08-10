#pragma once
#include <vector>
#include "CTokenizer.h"
#include "CErrorHandler.h"
#include "CSemanticStates.h"
#include "NodesVars.h"
#include <string>

class CSemanticAnalysis
{
public:
	CTokenizer* m_tokenaizer;
	CErrorHandler* m_errorHandler;
	CNodesVars* m_nodes;
	int m_indexToken;
	std::string m_name;

	SEMANTIC_STATES::E m_iActiveState;
	std::vector<CSemanticStates*> m_States;

	void Compile(CTokenizer* tokenaizer, CErrorHandler* errorHandler, CNodesVars* nodes);
	CSemanticAnalysis();
	~CSemanticAnalysis();
};

