#include "CSVar.h"
#include <string>
#include <vector>



SYNTACTIC_STATES::E CSVar::Evaluate(Token token, SYNTACTIC_STATES::E oldState, std::string parent)
{
	std::vector<GlobalNode> globalNodes;
	std::vector<LocalNode> localNodes;
	do
	{
		token = NextToken();
		if (token.itype != LEXIC_STATES::lID)
		{
			m_errorHandler->AddError(ERROR7, "Sintactico", token.line);
			while (token.svalue != ";" && token.svalue != "NULL")
			{
				token = NextToken();
			}
			return SYNTACTIC_STATES::SPROGRAM;
		}
		else
		{
			std::string name = token.svalue;
			token = NextToken();
			int dim = 1;

			if (token.svalue == "[")
			{
				dim = ProcessDimension();
				if (dim == -1)
				{
					m_errorHandler->AddError(ERROR8, "Sintactico", token.line);
					while (token.svalue != ";" && token.svalue != "NULL")
					{
						token = NextToken();
					}
					return SYNTACTIC_STATES::SPROGRAM;
				}
				else if (dim == -2)
				{
					m_errorHandler->AddError(ERROR12, "Sintactico", token.line);
					while (token.svalue != ";" && token.svalue != "NULL")
					{
						token = NextToken();
					}
					return SYNTACTIC_STATES::SPROGRAM;
				}
				token = NextToken();
			}

			if (oldState == SYNTACTIC_STATES::SPROGRAM)
			{
				GlobalNode tempGlobalNode;
				tempGlobalNode.m_category = "var";
				tempGlobalNode.m_name = name;
				tempGlobalNode.m_dimension = dim;
				globalNodes.push_back(tempGlobalNode);
			}
			else
			{
				LocalNode tempLocalNode;
				tempLocalNode.m_name = name;
				tempLocalNode.m_category = "var";
				tempLocalNode.m_dimension = dim;
				tempLocalNode.m_parent = parent;
				localNodes.push_back(tempLocalNode);
			}
		}
	} while (token.svalue == ",");

	if (token.svalue != ":") {
		m_errorHandler->AddError(ERROR9, "Sintactico", token.line);
		while (token.svalue != ";" && token.svalue != "NULL")
		{
			token = NextToken();
		}
		return SYNTACTIC_STATES::SPROGRAM;
	}
	std::string type = ProcessType(token.line);
	token = NextToken();
	if (token.svalue != ";") {
		m_errorHandler->AddError(ERROR10, "Sintactico", token.line);
		while (token.svalue != ";" && token.svalue != "NULL")
		{
			token = NextToken();
		}
		return SYNTACTIC_STATES::SPROGRAM;
	}
	if (oldState == SYNTACTIC_STATES::SPROGRAM)
	{
		for (int i = 0; i < globalNodes.size(); i++)
		{
			globalNodes[i].m_type = type;
			m_nodes->addGlobalNode(globalNodes[i], token.line);
		}
	}
	else
	{
		for (int i = 0; i < localNodes.size(); i++)
		{
			localNodes[i].m_type = type;
			m_nodes->addLocalNode(localNodes[i], token.line);
		}
	}

	return SYNTACTIC_STATES::SPROGRAM;
}

CSVar::CSVar()
{
}


CSVar::~CSVar()
{
}
