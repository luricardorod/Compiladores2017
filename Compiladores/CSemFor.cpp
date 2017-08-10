#include "CSemFor.h"

SEMANTIC_STATES::E CSemFor::Evaluate(Token token, SEMANTIC_STATES::E oldState, std::string parent)
{
	token = NextToken();
	if (token.svalue != "(")
	{
		m_errorHandler->AddError(ERROR19, "sintactico", token.line);
	}
	token = NextToken();
	(*m_States)[SEMANTIC_STATES::SASSINGCALL]->Evaluate(token, SEMANTIC_STATES::SFOR);

	(*m_States)[SEMANTIC_STATES::SCONDITIONAL]->Evaluate(token, SEMANTIC_STATES::SFOR);

	(*m_States)[SEMANTIC_STATES::SEXPRESSION]->Evaluate(token, SEMANTIC_STATES::SFOR);
	token = NextToken();
	if (token.svalue != ")")
	{
		m_errorHandler->AddError(ERROR25, "sintactico", token.line);
	}
	(*m_States)[SEMANTIC_STATES::SBLOCK]->Evaluate(token, SEMANTIC_STATES::SBLOCK);
	return SEMANTIC_STATES::E();
}

CSemFor::CSemFor()
{
}


CSemFor::~CSemFor()
{
}
