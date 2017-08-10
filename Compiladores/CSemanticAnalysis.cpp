#include "CSemanticAnalysis.h"
#include "CSemVar.h"
#include "CSemProcess.h"
#include "CSemFunction.h"
#include "CSemProgram.h"
#include "CSemBlock.h"
#include "CSemExpression.h"
#include "CSemTerm.h"
#include "CSemFor.h"
#include "CSemSwitch.h"
#include "CSemAssign.h"
#include "CSemIf.h"
#include "CSemCondition.h"


void CSemanticAnalysis::Compile(CTokenizer * tokenaizer, CErrorHandler* errorHandler, CNodesVars* nodes)
{
	m_tokenaizer = tokenaizer;
	m_errorHandler = errorHandler;
	m_nodes = nodes;
	m_name = "NULL";
	for (auto state = m_States.begin(); state != m_States.end(); state++)
	{
		(*state)->m_errorHandler = m_errorHandler;
		(*state)->m_tokenaizer = m_tokenaizer;
		(*state)->m_indexToken = &m_indexToken;
		(*state)->m_States = &m_States;
		(*state)->m_nodes = m_nodes;
		(*state)->m_name = &m_name;
	}
	Token tempToken = m_States[m_iActiveState]->NextToken();
	m_States[m_iActiveState]->Evaluate(tempToken, SEMANTIC_STATES::SPROGRAM);
}

CSemanticAnalysis::CSemanticAnalysis()
{
	m_iActiveState = SEMANTIC_STATES::SPROGRAM;
	//decalracion deestados
	m_States.resize(SEMANTIC_STATES::SSTATES_MAX);

	m_States[SEMANTIC_STATES::SPROGRAM] = new CSemProgram;
	m_States[SEMANTIC_STATES::SVAR] = new CSemVar;
	m_States[SEMANTIC_STATES::SPROCESS] = new CSemProcess;
	m_States[SEMANTIC_STATES::SFUNCTION] = new CSemFunction;
	m_States[SEMANTIC_STATES::SBLOCK] = new CSemBlock;
	m_States[SEMANTIC_STATES::SEXPRESSION] = new CSemExpression;
	m_States[SEMANTIC_STATES::STERM] = new CSemTerm;
	m_States[SEMANTIC_STATES::SASSINGCALL] = new CSemAssign;
	m_States[SEMANTIC_STATES::SFOR] = new CSemFor;
	m_States[SEMANTIC_STATES::SSWITCH] = new CSemSwitch;
	m_States[SEMANTIC_STATES::SIF] = new CSemIf;
	m_States[SEMANTIC_STATES::SCONDITIONAL] = new CSemCondition;
	m_indexToken = -1;
}


CSemanticAnalysis::~CSemanticAnalysis()
{
}
