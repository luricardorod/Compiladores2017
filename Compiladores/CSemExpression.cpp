#include "CSemExpression.h"


SEMANTIC_STATES::E CSemExpression::Evaluate(Token token, SEMANTIC_STATES::E oldState, std::string parent)
{
	std::vector<Token> expressionPosfija;
	std::vector<Token> operators;
	(*m_States)[SEMANTIC_STATES::STERM]->Evaluate(token, SEMANTIC_STATES::SEXPRESSION, "", &expressionPosfija, &operators);
	token = NextToken();

	if (isOperator(token))
	{
		operators.push_back(token);
		(*m_States)[SEMANTIC_STATES::SEXPRESSION]->Evaluate(token, SEMANTIC_STATES::SEXPRESSION, "", &expressionPosfija, &operators);
	}
	else
	{
		(*m_indexToken)--;
	}
	while (!(operators).empty())
	{
		if (!((operators).back().svalue == "(" || (operators).back().svalue == ")")) {
			(expressionPosfija).push_back((operators).back());
		};
		(operators).pop_back();
	}


	nodeExpresion root;
	nodeExpresion* apuntador = &root;

	while (!expressionPosfija.empty())
	{
		apuntador->m_token = expressionPosfija.back();
		expressionPosfija.pop_back();

		if (isOperator(apuntador->m_token))
		{
			addRigth(apuntador, &expressionPosfija);
			addLeft(apuntador, &expressionPosfija);
		}
		Evaluate(apuntador);
	}
	if (root.m_type == LEXIC_STATES::lSTATES_MAX)
	{
		return SEMANTIC_STATES::SPROGRAM;
	}
	if (root.m_type == LEXIC_STATES::lNUMBERFLOAT)
	{
		return SEMANTIC_STATES::SVAR;
	}
	if (root.m_type == LEXIC_STATES::lNUMBERINT)
	{
		return SEMANTIC_STATES::SPROCESS;
	}
	if (root.m_type == LEXIC_STATES::lBOOL)
	{
		return SEMANTIC_STATES::SFUNCTION;
	}
	return SEMANTIC_STATES::SSTATES_MAX;
}


SEMANTIC_STATES::E CSemExpression::Evaluate(Token token, SEMANTIC_STATES::E oldState, std::string parent, std::vector<Token>* expressionPosfija, std::vector<Token>* operators)
{
	(*m_States)[SEMANTIC_STATES::STERM]->Evaluate(token, SEMANTIC_STATES::SEXPRESSION, "", expressionPosfija, operators);
	token = NextToken();

	if (isOperator(token))
	{
		if (operators->empty())
		{
			operators->push_back(token);
		}
		else if (operators->back().svalue == "^")
		{
			expressionPosfija->push_back(operators->back());
			operators->pop_back();
			operators->push_back(token);
		}
		else if (operators->back().svalue == "/" || operators->back().svalue == "*" || operators->back().svalue == "%")
		{
			if (token.svalue == "^")
			{
				operators->push_back(token);
			}
			else
			{
				expressionPosfija->push_back(operators->back());
				operators->pop_back();
				operators->push_back(token);
			}
		}
		else if (operators->back().svalue == "+" || operators->back().svalue == "-")
		{
			if (token.svalue == "^" || token.svalue == "/" || token.svalue == "*" || token.svalue == "%")
			{
				operators->push_back(token);
			}
			else
			{
				expressionPosfija->push_back(operators->back());
				operators->pop_back();
				operators->push_back(token);
			}
		}
		else if (token.itype == LEXIC_STATES::lLOGICOPERATORS || token.itype == LEXIC_STATES::lRELACIONALOPERATORS)
		{
			expressionPosfija->push_back(operators->back());
			operators->pop_back();
			operators->push_back(token);
		}
		else
		{
			operators->push_back(token);
		}
		(*m_States)[SEMANTIC_STATES::SEXPRESSION]->Evaluate(token, SEMANTIC_STATES::SEXPRESSION, "", expressionPosfija, operators);
	}
	else
	{
		(*m_indexToken)--;
	}
	return SEMANTIC_STATES::E();
}

void CSemExpression::addRigth(nodeExpresion * father, std::vector<Token>* expressionPosfija)
{
	if (expressionPosfija->empty())
	{
		return;
	}
	father->m_hijoDerecha = new nodeExpresion();
	father->m_hijoDerecha->m_father = father;

	father->m_hijoDerecha->m_token = expressionPosfija->back();
	expressionPosfija->pop_back();
	if (isOperator(father->m_hijoDerecha->m_token))
	{
		addRigth(father->m_hijoDerecha, expressionPosfija);
		addLeft(father->m_hijoDerecha, expressionPosfija);
	}
	else
	{
		if (father->m_hijoDerecha->m_token.itype == LEXIC_STATES::lNUMBERFLOAT)
		{
			father->m_hijoDerecha->m_type = LEXIC_STATES::lNUMBERFLOAT;
		}
		else if (father->m_hijoDerecha->m_token.itype == LEXIC_STATES::lNUMBERINT)
		{
			father->m_hijoDerecha->m_type = LEXIC_STATES::lNUMBERINT;
		}
		else if (father->m_hijoDerecha->m_token.itype == LEXIC_STATES::lBOOL)
		{
			father->m_hijoDerecha->m_type = LEXIC_STATES::lBOOL;
		}
		else if (father->m_hijoDerecha->m_token.itype == LEXIC_STATES::lSTRING)
		{
			father->m_hijoDerecha->m_type = LEXIC_STATES::lSTRING;
		}
	}
}

void CSemExpression::addLeft(nodeExpresion * father, std::vector<Token>* expressionPosfija)
{
	if (expressionPosfija->empty())
	{
		return;
	}
	father->m_hijoIzquierda = new nodeExpresion();
	father->m_hijoIzquierda->m_father = father;

	father->m_hijoIzquierda->m_token = expressionPosfija->back();
	expressionPosfija->pop_back();
	if (isOperator(father->m_hijoIzquierda->m_token))
	{
		addRigth(father->m_hijoIzquierda, expressionPosfija);
		addLeft(father->m_hijoIzquierda, expressionPosfija);
	}
	else
	{
		if (father->m_hijoIzquierda->m_token.itype == LEXIC_STATES::lNUMBERFLOAT)
		{
			father->m_hijoIzquierda->m_type = LEXIC_STATES::lNUMBERFLOAT;
		}
		else if (father->m_hijoIzquierda->m_token.itype == LEXIC_STATES::lNUMBERINT)
		{
			father->m_hijoIzquierda->m_type = LEXIC_STATES::lNUMBERINT;
		}
		else if (father->m_hijoIzquierda->m_token.itype == LEXIC_STATES::lBOOL)
		{
			father->m_hijoIzquierda->m_type = LEXIC_STATES::lBOOL;
		}
		else if (father->m_hijoIzquierda->m_token.itype == LEXIC_STATES::lSTRING)
		{
			father->m_hijoIzquierda->m_type = LEXIC_STATES::lSTRING;
		}
		Evaluate(father);
	}
}

void CSemExpression::Evaluate(nodeExpresion * op)
{
	if(op->m_hijoDerecha == NULL || op->m_hijoIzquierda == NULL)
	{
		if (op->m_token.itype == LEXIC_STATES::lNUMBERFLOAT)
		{
			op->m_type = LEXIC_STATES::lNUMBERFLOAT;
		}
		else if (op->m_token.itype == LEXIC_STATES::lNUMBERINT)
		{
			op->m_type = LEXIC_STATES::lNUMBERINT;
		}
		else if (op->m_token.itype == LEXIC_STATES::lBOOL)
		{
			op->m_type = LEXIC_STATES::lBOOL;
		}
		else if (op->m_token.itype == LEXIC_STATES::lSTRING)
		{
			op->m_type = LEXIC_STATES::lSTRING;
		}
		else
		{
			op->m_type = LEXIC_STATES::lNONE;
		}
		return;
	}
	if (op->m_token.itype == LEXIC_STATES::lARITMETICOPERATORS)
	{
		if (!(op->m_hijoDerecha->m_type == LEXIC_STATES::lNUMBERINT || op->m_hijoDerecha->m_type == LEXIC_STATES::lNUMBERFLOAT)
			&&
			!(op->m_hijoIzquierda->m_type == LEXIC_STATES::lNUMBERINT || op->m_hijoIzquierda->m_type == LEXIC_STATES::lNUMBERFLOAT)
		)
		{
			std::string message;
			message = "Error en expresion se esperaban enteros o flotantes " + op->m_hijoIzquierda->m_token.svalue + " " + op->m_token.svalue + " " + op->m_hijoDerecha->m_token.svalue;
			m_errorHandler->AddError(message, "semantico", op->m_token.line);
		}
		if (op->m_hijoDerecha->m_type == LEXIC_STATES::lNUMBERINT && op->m_hijoIzquierda->m_type == LEXIC_STATES::lNUMBERINT)
		{
			op->m_type = LEXIC_STATES::lNUMBERINT;
		}
		else
		{
			op->m_type = LEXIC_STATES::lNUMBERFLOAT;
		}
	}
	else if (op->m_token.itype == LEXIC_STATES::lLOGICOPERATORS)
	{
		if (!(op->m_hijoDerecha->m_type == LEXIC_STATES::lBOOL)
			&&
			!(op->m_hijoIzquierda->m_type == LEXIC_STATES::lBOOL)
			)
		{
			std::string message;
			message = "Error en expresion se esperaban bool " + op->m_hijoIzquierda->m_token.svalue + " " + op->m_token.svalue + " " + op->m_hijoDerecha->m_token.svalue;
			m_errorHandler->AddError(message, "semantico", op->m_token.line);
		}
		op->m_type = LEXIC_STATES::lBOOL;
	}
	else if (op->m_token.svalue == "!=" || op->m_token.svalue == "==")
	{
		if (op->m_hijoDerecha->m_type != op->m_hijoIzquierda->m_type)
		{
			std::string message;
			message = "Error en expresion se esperaban mismos tipos " + op->m_hijoIzquierda->m_token.svalue + " " + op->m_token.svalue + " " + op->m_hijoDerecha->m_token.svalue;
			m_errorHandler->AddError(message, "semantico", op->m_token.line);
		}
		op->m_type = op->m_hijoDerecha->m_type;
	}
	else
	{
		if (!(op->m_hijoDerecha->m_type == LEXIC_STATES::lNUMBERINT || op->m_hijoDerecha->m_type == LEXIC_STATES::lNUMBERFLOAT)
			&&
			!(op->m_hijoIzquierda->m_type == LEXIC_STATES::lNUMBERINT || op->m_hijoIzquierda->m_type == LEXIC_STATES::lNUMBERFLOAT)
			)
		{
			std::string message;
			message = "Error en expresion se esperaban enteros o flotantes " + op->m_hijoIzquierda->m_token.svalue + " " + op->m_token.svalue + " " + op->m_hijoDerecha->m_token.svalue;
			m_errorHandler->AddError(message, "semantico", op->m_token.line);
		}
		if (op->m_hijoDerecha->m_type == LEXIC_STATES::lNUMBERINT && op->m_hijoIzquierda->m_type == LEXIC_STATES::lNUMBERINT)
		{
			op->m_type = LEXIC_STATES::lNUMBERINT;
		}
		else
		{
			op->m_type = LEXIC_STATES::lNUMBERFLOAT;
		}
	}
}

CSemExpression::CSemExpression()
{
}


CSemExpression::~CSemExpression()
{
}
