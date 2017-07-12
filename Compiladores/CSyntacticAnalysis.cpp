#include "CSyntacticAnalysis.h"
#include "CSVar.h"
#include "CSProcess.h"
#include "CSFunction.h"
#include "CSProgram.h"
#include "CSMain.h"


void CSyntacticAnalysis::Compile(CTokenizer * tokenaizer, CErrorHandler* errorHandler, CNodesVars* nodes)
{
	m_tokenaizer = tokenaizer;
	m_errorHandler = errorHandler;
	m_nodes = nodes;
	for (auto state = m_States.begin(); state != m_States.end(); state++)
	{
		(*state)->m_errorHandler = m_errorHandler;
		(*state)->m_tokenaizer = m_tokenaizer;
		(*state)->m_indexToken = &m_indexToken;
		(*state)->m_States = &m_States;
		(*state)->m_nodes = m_nodes;
	}
	Token tempToken = m_States[m_iActiveState]->NextToken();
	m_States[m_iActiveState]->Evaluate(tempToken, SYNTACTIC_STATES::SPROGRAM);
}

CSyntacticAnalysis::CSyntacticAnalysis()
{
	m_iActiveState = SYNTACTIC_STATES::SPROGRAM;
	//decalracion deestados
	m_States.resize(SYNTACTIC_STATES::SSTATES_MAX);
	m_States[SYNTACTIC_STATES::SPROGRAM] = new CSProgram;
	m_States[SYNTACTIC_STATES::SVAR] = new CSVar;
	m_States[SYNTACTIC_STATES::SPROCESS] = new CSProgram;
	m_States[SYNTACTIC_STATES::SFUNCTION] = new CSFunction;
	m_States[SYNTACTIC_STATES::SMAIN] = new CSMain;
	m_indexToken = -1;
}


CSyntacticAnalysis::~CSyntacticAnalysis()
{
}
