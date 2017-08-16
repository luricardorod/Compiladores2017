#include "CSemFor.h"

SEMANTIC_STATES::E CSemFor::Evaluate(Token token, SEMANTIC_STATES::E oldState, std::string parent)
{
	token = NextToken();
	
	token = NextToken();
	(*m_States)[SEMANTIC_STATES::SASSINGCALL]->Evaluate(token, SEMANTIC_STATES::SFOR);
	
	LEXIC_STATES::E temp = transformSemToType((*m_States)[SEMANTIC_STATES::SEXPRESSION]->Evaluate(token, SEMANTIC_STATES::SEXPRESSION));
	if (temp != LEXIC_STATES::lBOOL)
	{
		m_errorHandler->AddError(ERROR47, "semantico", token.line);
	}

	(*m_States)[SEMANTIC_STATES::SEXPRESSION]->Evaluate(token, SEMANTIC_STATES::SFOR);
	token = NextToken();
	
	(*m_States)[SEMANTIC_STATES::SBLOCK]->Evaluate(token, SEMANTIC_STATES::SBLOCK);
	return SEMANTIC_STATES::E();
}

CSemFor::CSemFor()
{
}


CSemFor::~CSemFor()
{
}
