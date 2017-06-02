#include "CLexicalAnalysis.h"
#include "CLNone.h"
#include "CLId.h"
#include "CLNumberInt.h"
#include "CLNumberFloat.h"
#include "CLComments.h"
#include "CLLogicOperators.h"
#include "CLAritmeticOperators.h"
#include "CLRelacionalOperators.h"
#include "CLAssign.h"
#include "CLConstantAlfanumeric.h"
#include "CLDelimiters.h"
#include "CLGroupOperators.h"
#include "CLOpenDimensionOperator.h"
#include "CLCloseDimensionOperator.h"

void CLexicalAnalysis::Compile(std::string * file)
{
	m_errorHandler.Initialize();
	m_tokenaizer.Initialize();
	for (int i = 0; i < file->length(); i++)
	{
		LEXIC_STATES::E previousState = m_iActiveState;
		m_iActiveState = m_States[m_iActiveState]->Evaluate((*file)[i]);
		if (previousState != m_iActiveState)
		{
			std::string temp = m_States[previousState]->Exit();
			if (m_iActiveState == LEXIC_STATES::lNONE)
			{
				m_iActiveState = m_States[m_iActiveState]->Evaluate((*file)[i]);
			}
			m_iActiveState = m_States[m_iActiveState]->Enter((*file)[i], temp);
		}
	}
	m_iActiveState = m_States[m_iActiveState]->Evaluate(' ');
	if (m_iActiveState == LEXIC_STATES::lCOMMENTS)
	{
		m_errorHandler.AddError(ERROR2, "lexico");
	}
	if (m_iActiveState == LEXIC_STATES::lCONSTANTALFANUMERIC)
	{
		m_errorHandler.AddError(ERROR3, "lexico");
	}

}
CLexicalAnalysis::CLexicalAnalysis()
{
	m_iActiveState = LEXIC_STATES::lNONE;
	//decalracion deestados
	m_States.resize(LEXIC_STATES::lSTATES_MAX);
	m_States[LEXIC_STATES::lNONE] = new CLNone;
	m_States[LEXIC_STATES::lID] = new CLId;
	m_States[LEXIC_STATES::lNUMBERINT] = new CLNumberInt;
	m_States[LEXIC_STATES::lNUMBERFLOAT] = new CLNumberFloat;
	m_States[LEXIC_STATES::lCOMMENTS] = new CLComments;
	m_States[LEXIC_STATES::lLOGICOPERATORS] = new CLLogicOperators;
	m_States[LEXIC_STATES::lARITMETICOPERATORS] = new CLAritmeticOperators;
	m_States[LEXIC_STATES::lRELACIONALOPERATORS] = new CLRelacionalOperators;
	m_States[LEXIC_STATES::lASSIGN] = new CLAssign;
	m_States[LEXIC_STATES::lCONSTANTALFANUMERIC] = new CLConstantAlfanumeric;
	m_States[LEXIC_STATES::lDELIMITERS] = new CLDelimiters;
	m_States[LEXIC_STATES::lGROUPOPERATORS] = new CLGroupOperators;
	m_States[LEXIC_STATES::lOPENDIMENSIONOPERATOR] = new CLOpenDimensionOperator;
	m_States[LEXIC_STATES::lCLOSEDIMENSIONOPERATOR] = new CLCloseDimensionOperator;


	for (auto state = m_States.begin(); state != m_States.end(); state++)
	{
		(*state)->m_tokenaizer = &m_tokenaizer;
		(*state)->m_errorHandler = &m_errorHandler;
	}
}


CLexicalAnalysis::~CLexicalAnalysis()
{
}