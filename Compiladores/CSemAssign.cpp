#include "CSemAssign.h"

SEMANTIC_STATES::E CSemAssign::Evaluate(Token token, SEMANTIC_STATES::E oldState, std::string parent)
{
	Token tempToken = token;
	
	token = NextToken();
	if (token.svalue == "(")
	{
		token = NextToken();

		GlobalNode funProc = m_nodes->isFunctionProcedureAndNotVar(tempToken.svalue, (*m_name));
		std::vector<int> typesVars;
		if (token.svalue != ")") {
			(*m_indexToken)--;
			do
			{
				SEMANTIC_STATES::E temp = (*m_States)[SEMANTIC_STATES::SEXPRESSION]->Evaluate(token, SEMANTIC_STATES::SBLOCK);
				typesVars.push_back(transformSemToType(temp));
				token = NextToken();
			} while (token.svalue == ",");
			if (token.svalue == ")")
			{
				token = NextToken();
			}
			if (token.svalue != ";")
			{
				while (token.svalue != ";" && token.svalue != "}" && token.svalue != "NULL")
				{
					token = NextToken();
				}
				(*m_indexToken)--;
			}
		}
		if (funProc.m_category == CATEGORIES_EXPRESSION::FUNCTION || funProc.m_category == CATEGORIES_EXPRESSION::PROCEDURE)
		{
			tempToken.itype = funProc.m_type;
			if (typesVars.size() != funProc.m_dimension)
			{
				//error de numero de parametros
				m_errorHandler->AddError(ERROR40, "semantico", token.line);
			}
			else
			{
				bool flag = true;
				for (int i = 0; i < typesVars.size(); i++)
				{
					if (typesVars[i] != m_errorHandler->SetType(funProc.m_values[i]))
					{
						flag = false;
					}
				}
				if (!flag)
				{
					//error en parametro esperadoprocedure
					m_errorHandler->AddError(ERROR41, "semantico", token.line);
				}
			}
		}
		else
		{
			m_errorHandler->AddError(ERROR39, "semantico", token.line);
		}
	}
	else
	{
		if (token.svalue == "[") 
		{
			LEXIC_STATES::E temp = transformSemToType((*m_States)[SEMANTIC_STATES::SEXPRESSION]->Evaluate(token, SEMANTIC_STATES::SEXPRESSION));
			token = NextToken();

			if (token.svalue != "]")
			{
				while (token.svalue != ")" && token.svalue != "NULL")
				{
					token = NextToken();
				}
				return SEMANTIC_STATES::SPROGRAM;
			}
			if (temp != LEXIC_STATES::lNUMBERINT)
			{
				m_errorHandler->AddError(ERROR44, "Semantico", tempToken.line);
			}

			LocalNode localNode = m_nodes->isLocalVar(tempToken.svalue, (*m_name));
			if (localNode.m_category == CATEGORIES_EXPRESSION::VAR)
			{
				if (localNode.m_dimension < 2)
				{
					m_errorHandler->AddError(ERROR43, "Semantico", tempToken.line);
				}
			}
			else
			{
				GlobalNode globalNode = m_nodes->isGlobalVar(tempToken.svalue, (*m_name));
				if (globalNode.m_category == CATEGORIES_EXPRESSION::VAR)
				{
					if (globalNode.m_dimension < 2)
					{
						m_errorHandler->AddError(ERROR43, "Semantico", tempToken.line);
					}
				}
				else
				{
					m_errorHandler->AddError(ERROR42, "Semantico", tempToken.line);
				}
			}

			token = NextToken();
		}

		if (token.svalue == "=")
		{

			LEXIC_STATES::E temp = transformSemToType((*m_States)[SEMANTIC_STATES::SEXPRESSION]->Evaluate(token, SEMANTIC_STATES::SEXPRESSION));

			LocalNode localNode = m_nodes->isLocalVar(tempToken.svalue, (*m_name));
			if (localNode.m_category == CATEGORIES_EXPRESSION::VAR)
			{
				tempToken.itype = localNode.m_type;
			}
			else
			{
				GlobalNode globalNode = m_nodes->isGlobalVar(tempToken.svalue, (*m_name));
				if (globalNode.m_category == CATEGORIES_EXPRESSION::VAR)
				{
					tempToken.itype = globalNode.m_type;
				}
				else
				{
					m_errorHandler->AddError(ERROR42, "Semantico", tempToken.line);
				}
			}

			if (tempToken.itype != temp)
			{
				m_errorHandler->AddError(ERROR45, "Semantico", tempToken.line);

			}
			token = NextToken();
		}
	}

	
	return SEMANTIC_STATES::E();
}

CSemAssign::CSemAssign()
{
}


CSemAssign::~CSemAssign()
{
}
