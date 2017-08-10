#pragma once
#include "CErrorHandler.h"
#include "CTokenizer.h"
#include "NodesVars.h"

namespace SYNTACTIC_STATES
{
	enum E
	{
		SPROGRAM,
		SVAR,
		SPROCESS,
		SFUNCTION,
		SMAIN,
		SBLOCK,
		SEXPRESSION,
		STERM,
		SFOR,
		SSWITCH,
		SASSINGCALL,
		SIF,
		SCONDITIONAL,
		SSTATES_MAX
	};
}

class CSyntacticStates
{
public:
	virtual SYNTACTIC_STATES::E Evaluate(Token token, SYNTACTIC_STATES::E, std::string parent = "") = 0;
	//virtual SYNTACTIC_STATES::E Enter(char character, std::string string) = 0;
	//virtual void Exit() = 0;
	CErrorHandler* m_errorHandler;
	CTokenizer* m_tokenaizer;
	CNodesVars* m_nodes;
	std::vector<CSyntacticStates*>* m_States;

	int* m_indexToken;
	virtual ~CSyntacticStates() {};
	Token NextToken() {
		int size = m_tokenaizer->m_listTokens.size() - 1;
		if (*m_indexToken < size)
		{
			(*m_indexToken)++;
			return m_tokenaizer->m_listTokens[(*m_indexToken)];
		}
		Token tempo;
		tempo.svalue = "NULL";
		return tempo;
	}
	int ProcessDimension() {
		Token temp = NextToken();
		int dimension = 0;
		if (temp.itype != LEXIC_STATES::lNUMBERINT)
		{
			return -1;
		}
		else
		{
			dimension = std::stoi(temp.svalue);
		}
		temp = NextToken();
		if (temp.svalue != "]")
		{
			return -2;
		}
		return dimension;
	}

	std::string ProcessType(int line) {
		Token temp = NextToken();

		if (temp.svalue == "int" ||
			temp.svalue == "float" ||
			temp.svalue == "string" ||
			temp.svalue == "bool")
		{
			return temp.svalue;
		}
		m_errorHandler->AddError(ERROR11, "Sintactico", line);
		return "error";
	}

	bool IsAType() {
		Token temp = NextToken();

		return temp.svalue == "int" ||
			temp.svalue == "float" ||
			temp.svalue == "string" ||
			temp.svalue == "bool";
	}
	int GroupIds() {
		Token token = NextToken();

		while (token.itype == LEXIC_STATES::lID)
		{
			token = NextToken();
			if (token.svalue == ",")
			{
				token = NextToken();
			}
		}
		if (token.svalue != ")")
		{
			return 1;
		}
		return 0;
	}
	int GroupParams(std::string parent, std::vector<std::string> * typesParams) {
		Token token = NextToken();
		
		std::vector<LocalNode> localnodes;
		while (token.itype == LEXIC_STATES::lID)
		{
			LocalNode tempLocalNode;
			tempLocalNode.m_name = token.svalue;
			tempLocalNode.m_category = "var";
			tempLocalNode.m_parent = parent;
			tempLocalNode.m_dimension = 1;
			token = NextToken();
			if (token.svalue == ",")
			{
				token = NextToken();
				localnodes.push_back(tempLocalNode);
			}
			else if (token.svalue == ":")
			{
				if (!IsAType())
				{
					return 2;
				}
				localnodes.push_back(tempLocalNode);
				(*m_indexToken)--;
				std::string type = ProcessType(token.line);

				for (auto i = localnodes.begin(); i != localnodes.end(); i++)
				{
					i->m_type = type;
					m_nodes->addLocalNode(*i, token.line);
					(*typesParams).push_back(type);
				}
				localnodes.clear();
				token = NextToken();

				if (token.svalue == ";")
				{
					token = NextToken();
					if (token.itype != LEXIC_STATES::lID)
					{
						return 3;
					}
				}
			}
			else
			{
				return 1;
			}
		}
		if (token.svalue != ")")
		{
			return 4;
		}
		return 0;
	}
	bool isOperator() {
		Token token = NextToken();
		return token.itype == LEXIC_STATES::lARITMETICOPERATORS || token.itype == LEXIC_STATES::lLOGICOPERATORS || token.itype == LEXIC_STATES::lRELACIONALOPERATORS;
	}
};

