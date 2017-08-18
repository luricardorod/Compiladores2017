#include "CSemBlock.h"


SEMANTIC_STATES::E CSemBlock::Evaluate(Token token, SEMANTIC_STATES::E oldState, std::string parent)
{
	bool flagReturn = false;
	token = NextToken();
	if (token.svalue != "{")
	{
		while (token.svalue != "}" && token.svalue != "NULL")
		{
			token = NextToken();
		}
		return SEMANTIC_STATES::E();
	}

	token = NextToken();
	while (token.svalue != "}" && token.svalue != "NULL")
	{
		if (token.svalue == ";") {

		}
		else if (token.svalue == "var")
		{
			if (oldState == SEMANTIC_STATES::SPROCESS || oldState == SEMANTIC_STATES::SFUNCTION || oldState == SEMANTIC_STATES::SPROGRAM)
			{
				(*m_States)[SEMANTIC_STATES::SVAR]->Evaluate(token, oldState, parent);
			}
			else
			{
				while (token.svalue != ";" && token.svalue != "NULL")
				{
					token = NextToken();
				}
			}
		}
		else if (token.svalue == "if" || token.svalue == "while")
		{
			(*m_States)[SEMANTIC_STATES::SIF]->Evaluate(token, SEMANTIC_STATES::SBLOCK);
		}
		else if (token.svalue == "for")
		{
			(*m_States)[SEMANTIC_STATES::SFOR]->Evaluate(token, SEMANTIC_STATES::SBLOCK);
		}
		else if (token.svalue == "switch")
		{
			(*m_States)[SEMANTIC_STATES::SSWITCH]->Evaluate(token, SEMANTIC_STATES::SBLOCK);
		}
		else if (token.itype == LEXIC_STATES::lID)
		{
			(*m_States)[SEMANTIC_STATES::SASSINGCALL]->Evaluate(token, SEMANTIC_STATES::SBLOCK);
		}
		else if (token.svalue == "return")
		{
			flagReturn = true;
			GlobalNode funProc = m_nodes->isFunctionProcedureAndNotVar((*m_name), (*m_name));
			if (funProc.m_category != CATEGORIES_EXPRESSION::FUNCTION)
			{
				m_errorHandler->AddError(ERROR37, "semantico", token.line);
			}
			else
			{
				LEXIC_STATES::E temp = transformSemToType((*m_States)[SEMANTIC_STATES::SEXPRESSION]->Evaluate(token, SEMANTIC_STATES::SBLOCK));

				if (temp != funProc.m_type)
				{
					m_errorHandler->AddError(ERROR46, "semantico", token.line);

				}
			}
			token = NextToken();
			if (token.svalue != ";")
			{
				(*m_indexToken)--;
			}
		}
		token = NextToken();
	}

	if (oldState == SEMANTIC_STATES::SFUNCTION)
	{
		NODE_TYPES::E nodeType = m_nodes->GetCategory(*m_name);
		if (nodeType == NODE_TYPES::FUNCTION)
		{
			if (!flagReturn)
			{
				m_errorHandler->AddError(ERROR38, "semantico", token.line);
			}
		}
	}
	return SEMANTIC_STATES::E();
}

CSemBlock::CSemBlock()
{
}


CSemBlock::~CSemBlock()
{
}
