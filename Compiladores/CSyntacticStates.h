#pragma once
#include "CErrorHandler.h"
#include "CTokenizer.h"
#include <string>
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

	std::string ProcessType() {
		Token temp = NextToken();

		if (temp.svalue == "int" ||
			temp.svalue == "float" ||
			temp.svalue == "string" ||
			temp.svalue == "bool")
		{
			return temp.svalue;
		}
		m_errorHandler->AddError(ERROR11, "Sintactico");
		return "error";
	}

	bool IsAType() {
		Token temp = NextToken();

		return temp.svalue == "int" ||
			temp.svalue == "float" ||
			temp.svalue == "string" ||
			temp.svalue == "bool";
	}
	int GroupParams() {
		Token token = NextToken();

		while (token.itype == LEXIC_STATES::lID)
		{
			token = NextToken();
			if (token.svalue == ",")
			{
				token = NextToken();
			}
			else if (token.svalue == ":")
			{
				if (!IsAType())
				{
					return 2;
				}
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
};

