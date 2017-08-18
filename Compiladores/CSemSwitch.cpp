#include "CSemSwitch.h"



SEMANTIC_STATES::E CSemSwitch::Evaluate(Token token, SEMANTIC_STATES::E oldState, std::string parent)
{
	token = NextToken();
	token = NextToken();
	if (token.itype == LEXIC_STATES::lID)
	{
		LocalNode localNode = m_nodes->isLocalVar(token.svalue, (*m_name));
		if (localNode.m_type != LEXIC_STATES::lNUMBERINT)
		{
			GlobalNode globalNode = m_nodes->isGlobalVar(token.svalue, (*m_name));
			if (globalNode.m_type != LEXIC_STATES::lNUMBERINT)
			{
				m_errorHandler->AddError(ERROR48, "Semantico", token.line);
			}
		}
	}
	token = NextToken();
	token = NextToken();
	token = NextToken();
	while (token.svalue != "}")
	{
		if (token.itype == LEXIC_STATES::lNUMBERINT || token.svalue == "default")
		{
			token = NextToken();
			(*m_States)[SEMANTIC_STATES::SBLOCK]->Evaluate(token, oldState, parent);
			token = NextToken();
		}
		else
		{
			token = NextToken();
			if (token.svalue == ":")
			{
				(*m_States)[SEMANTIC_STATES::SBLOCK]->Evaluate(token, oldState, parent);
				token = NextToken();
			}
		}
	}

	return SEMANTIC_STATES::E();
}

CSemSwitch::CSemSwitch()
{
}


CSemSwitch::~CSemSwitch()
{
}
