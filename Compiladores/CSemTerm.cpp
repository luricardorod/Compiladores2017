#include "CSemTerm.h"



SEMANTIC_STATES::E CSemTerm::Evaluate(Token token, SEMANTIC_STATES::E oldState, std::string parent, std::vector<Token>* expressionPosfija, std::vector<Token>* operators)
{
	token = NextToken();
	if (token.svalue == "(")
	{
		(*operators).push_back(token);
		(*m_States)[SEMANTIC_STATES::SEXPRESSION]->Evaluate(token, SEMANTIC_STATES::SEXPRESSION, "", expressionPosfija, operators);
		token = NextToken();
		(*operators).push_back(token);
		while (!(*operators).empty())
		{
			if (!((*operators).back().svalue == "(" || (*operators).back().svalue == ")")) {
				(*expressionPosfija).push_back((*operators).back());
			};
			(*operators).pop_back();
		}
		
	}
	else if (token.svalue == "true" || token.svalue == "false" || token.itype == LEXIC_STATES::lNUMBERINT || token.itype == LEXIC_STATES::lNUMBERFLOAT || token.itype == LEXIC_STATES::lSTRING)
	{
		(*expressionPosfija).push_back(token);
		return SEMANTIC_STATES::E();
	}
	else if (token.itype == LEXIC_STATES::lID)
	{
		Token tempToken = token;
		token = NextToken();
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
				tempToken.itype = localNode.m_type;
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
					tempToken.itype = globalNode.m_type;
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
		}
		else if (token.svalue == "(")
		{
			token = NextToken();
			GlobalNode funProc = m_nodes->isFunctionProcedureAndNotVar(tempToken.svalue, (*m_name));
			std::vector<LEXIC_STATES::E> typesVars;
			if (token.svalue != ")") {
				(*m_indexToken)--;
				do
				{
					SEMANTIC_STATES::E temp = (*m_States)[SEMANTIC_STATES::SEXPRESSION]->Evaluate(token, SEMANTIC_STATES::SBLOCK);
					typesVars.push_back(transformSemToType(temp));
					token = NextToken();
				} while (token.svalue == ",");
				if (token.svalue != ")")
				{
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
			(*m_indexToken)--;
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
		}
		(*expressionPosfija).push_back(tempToken);
	}
	else if (token.svalue == "!")
	{
		LEXIC_STATES::E temp = transformSemToType((*m_States)[SEMANTIC_STATES::SEXPRESSION]->Evaluate(token, SEMANTIC_STATES::SEXPRESSION));
		if (temp != LEXIC_STATES::lBOOL)
		{
			m_errorHandler->AddError(ERROR50, "semantico", token.line);
		}
		token.itype = LEXIC_STATES::lBOOL;
		(*expressionPosfija).push_back(token);
	}
	else if (token.svalue == "-")
	{
		LEXIC_STATES::E temp = transformSemToType((*m_States)[SEMANTIC_STATES::SEXPRESSION]->Evaluate(token, SEMANTIC_STATES::SEXPRESSION));
		if (!(temp == LEXIC_STATES::lNUMBERFLOAT || temp == LEXIC_STATES::lNUMBERINT))
		{
			m_errorHandler->AddError(ERROR49, "semantico", token.line);
		}
		token.itype = LEXIC_STATES::lNUMBERFLOAT;
		(*expressionPosfija).push_back(token);

	}
	else
	{
		token = NextToken();
		if (token.svalue == "(" || (token.itype == LEXIC_STATES::lID) || (token.itype == LEXIC_STATES::lNUMBERINT || token.itype == LEXIC_STATES::lNUMBERFLOAT || token.itype == LEXIC_STATES::lSTRING) || (token.svalue == "!")) {
			(*m_indexToken)--;
			(*m_States)[SEMANTIC_STATES::STERM]->Evaluate(token, SEMANTIC_STATES::STERM, "", expressionPosfija, NULL);
		}
		else
		{
			(*m_indexToken)--;
			(*m_indexToken)--;
		}

	}
	return SEMANTIC_STATES::E();
}

SEMANTIC_STATES::E CSemTerm::Evaluate(Token token, SEMANTIC_STATES::E oldState, std::string parent)
{
	return SEMANTIC_STATES::E();
}

CSemTerm::CSemTerm()
{
}


CSemTerm::~CSemTerm()
{
}
