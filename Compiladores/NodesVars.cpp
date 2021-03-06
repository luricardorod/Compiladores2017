#include "NodesVars.h"

void CNodesVars::Init() {
	Nodes.clear();
}

void CNodesVars::addGlobalNode(GlobalNode globalNode, int line) {
	std::vector<GlobalNode>::iterator node;

	for (node = Nodes.begin(); node != Nodes.end(); node++)
	{
		if (node->m_name == globalNode.m_name)
		{
			break;
		}
	}

	if (node == Nodes.end())
	{
		globalNode.m_nextGlobal = NULL;
		globalNode.m_nextLocal = NULL;
		if (globalNode.m_values.size() == 0)
		{
			globalNode.m_values.resize(globalNode.m_dimension);
		}
		Nodes.push_back(globalNode);
	}
	else
	{
		if (node->m_category == CATEGORIES_EXPRESSION::NULLCATEGORY)
		{
			(*node).m_category = globalNode.m_category;
			(*node).m_dimension = globalNode.m_dimension;
			(*node).m_type = globalNode.m_type;
			(*node).m_values = globalNode.m_values;
			return;
		}
		if (node->m_category == CATEGORIES_EXPRESSION::VAR && node->m_category == globalNode.m_category)
		{
			m_errorHandler->AddError(ERROR13, "sintactico", line);
			return;
		}
		if ((*node).m_nextGlobal != NULL || node->m_name == globalNode.m_name)
		{
			m_errorHandler->AddError(ERROR18, "sintactico", line);
			return;
		}


		(*node).m_nextGlobal = new GlobalNode;
		(*node).m_nextGlobal->m_name = globalNode.m_name;
		(*node).m_nextGlobal->m_category = globalNode.m_category;
		(*node).m_nextGlobal->m_dimension = globalNode.m_dimension;
		(*node).m_nextGlobal->m_nextGlobal = NULL;
		(*node).m_nextGlobal->m_nextLocal = NULL;
		(*node).m_nextGlobal->m_type = globalNode.m_type;
		(*node).m_nextGlobal->m_values.resize((*node).m_nextGlobal->m_dimension);
	}
};


void CNodesVars::addLocalNode(LocalNode localNode, int line) {
	std::vector<GlobalNode>::iterator node;

	for (node = Nodes.begin(); node != Nodes.end(); node++)
	{
		if (node->m_name == localNode.m_name)
		{
			break;
		}
	}
	if (node == Nodes.end())
	{
		GlobalNode temp;
		temp.m_name = localNode.m_name;
		temp.m_category = CATEGORIES_EXPRESSION::NULLCATEGORY;
		temp.m_dimension = 0;
		temp.m_nextGlobal = NULL;
		temp.m_type = LEXIC_STATES::lNONE;
		temp.m_values.clear();

		temp.m_nextLocal = new LocalNode();
		
		temp.m_nextLocal->m_name = localNode.m_name;
		temp.m_nextLocal->m_category = localNode.m_category;
		temp.m_nextLocal->m_type = localNode.m_type;
		temp.m_nextLocal->m_dimension = localNode.m_dimension;
		temp.m_nextLocal->m_parent = localNode.m_parent;
		temp.m_nextLocal->m_values.resize(localNode.m_dimension);
		temp.m_nextLocal->m_next = NULL;

		Nodes.push_back(temp);
	}
	else
	{
		if (node->m_nextLocal == NULL)
		{
			node->m_nextLocal = new LocalNode();

			node->m_nextLocal->m_name = localNode.m_name;
			node->m_nextLocal->m_category = localNode.m_category;
			node->m_nextLocal->m_type = localNode.m_type;
			node->m_nextLocal->m_dimension = localNode.m_dimension;
			node->m_nextLocal->m_parent = localNode.m_parent;
			node->m_nextLocal->m_values.resize(localNode.m_dimension);
			node->m_nextLocal->m_next = NULL;
		}
		else
		{
			LocalNode* temp = node->m_nextLocal;
			if (temp->m_parent == localNode.m_parent)
			{
				m_errorHandler->AddError(ERROR16, "sintactico", line);
				return;
			}
			while (temp->m_next != NULL)
			{
				if (temp->m_parent == localNode.m_parent)
				{
					m_errorHandler->AddError(ERROR16, "sintactico", line);
					return;
				}
				temp = temp->m_next;
			}
			temp->m_next = new LocalNode();

			temp->m_next->m_name = localNode.m_name;
			temp->m_next->m_category = localNode.m_category;
			temp->m_next->m_type = localNode.m_type;
			temp->m_next->m_dimension = localNode.m_dimension;
			temp->m_next->m_parent = localNode.m_parent;
			temp->m_next->m_values.resize(localNode.m_dimension);
			temp->m_next->m_next = NULL;
		}
	}
}

void CNodesVars::errorCategory(std::string category, int line)
{
	if (category == "var")
	{
		m_errorHandler->AddError(ERROR13, "Sintactico", line);
	}
	else if ("function")
	{
		m_errorHandler->AddError(ERROR14, "Sintactico", line);
	}
	else
	{
		m_errorHandler->AddError(ERROR15, "Sintactico", line);
	}
}


std::string CNodesVars::localNodeToText(LocalNode localnode) {
	std::string text;
	
	text += localnode.m_category + "," + TypeToString(localnode.m_type) + "," + localnode.m_parent + "," + std::to_string(localnode.m_dimension) + ",[";
	for (int i = 0; i < localnode.m_values.size(); i++)
	{
		text += localnode.m_values[i];
		if (i + 1 < localnode.m_values.size())
		{
			text += ",";
		}
	}
	text += "]{";
	if (localnode.m_next != NULL)
	{
		text += localNodeToText(*localnode.m_next);
	}
	text += "}";
	return text;
}
std::string CNodesVars::GetNodes()
{
	Nodes;
	std::string text = "";
	for (auto globalNode = Nodes.begin(); globalNode != Nodes.end(); globalNode++)
	{
		text += globalNode->m_name + "," + CategoriesToString(globalNode->m_category) + "," + TypeToString(globalNode->m_type) + ",";
		text += std::to_string(globalNode->m_dimension) + ",[";
		for (int i = 0; i < globalNode->m_values.size(); i++)
		{
			text += globalNode->m_values[i];
			if (i + 1 < globalNode->m_values.size())
			{
				text += ",";
			}
		}
		text += "],{";
		if (globalNode->m_nextLocal != NULL)
		{
			text += localNodeToText(*globalNode->m_nextLocal);
		}
		text += "},0;\n";
	}
	return text;
}

std::string CNodesVars::GetType(std::string name, std::string environment)
{
	std::vector<GlobalNode>::iterator node;
	for (node = Nodes.begin(); node != Nodes.end(); node++)
	{
		if (node->m_name == name)
		{
			break;
		}
	}
	
	return "NULL";
}

GlobalNode CNodesVars::isFunctionProcedureAndNotVar(std::string name, std::string environment)
{
	std::vector<GlobalNode>::iterator node;
	for (node = Nodes.begin(); node != Nodes.end(); node++)
	{
		if (node->m_name == name)
		{
			break;
		}
	}
	if (node == Nodes.end())
	{
		return GlobalNode();
	}
	LocalNode* temp = node->m_nextLocal;
	while (temp != NULL)
	{
		if (temp->m_parent == environment && temp->m_category == CATEGORIES_EXPRESSION::VAR)
		{
			return GlobalNode();
		}
		temp = temp->m_next;
	}
	if ((node->m_category == CATEGORIES_EXPRESSION::PROCEDURE) || (node->m_category == CATEGORIES_EXPRESSION::FUNCTION))
	{
		return (*node);
	}
	return GlobalNode();
}

std::string CNodesVars::CategoriesToString(CATEGORIES_EXPRESSION::E category)
{
	if (category == CATEGORIES_EXPRESSION::FUNCTION)
	{
		return "funtion";
	}
	else if (category == CATEGORIES_EXPRESSION::MAIN)
	{
		return "main";
	}
	else if (category == CATEGORIES_EXPRESSION::NULLCATEGORY)
	{
		return "indef";
	}
	else if (category == CATEGORIES_EXPRESSION::PROCEDURE)
	{
		return "procedure";
	}
	else if (category == CATEGORIES_EXPRESSION::VAR)
	{
		return "var";
	}
	return "";
}

std::string CNodesVars::TypeToString(LEXIC_STATES::E type)
{
	if (type == LEXIC_STATES::lBOOL)
	{
		return "bool";
	}
	else if (type == LEXIC_STATES::lNUMBERFLOAT)
	{
		return "float";
	}
	else if (type == LEXIC_STATES::lNUMBERINT)
	{
		return "int";
	}
	else if (type == LEXIC_STATES::lNONE)
	{
		return "null";
	}
	else if (type == LEXIC_STATES::lSTRING)
	{
		return "string";
	}

	return std::string();
}

NODE_TYPES::E CNodesVars::GetCategory(std::string name)
{
	std::vector<GlobalNode>::iterator node;
	NODE_TYPES::E value = NODE_TYPES::NODENULL;
	if (name == "main")
	{
		return NODE_TYPES::MAIN;
	}
	for (node = Nodes.begin(); node != Nodes.end(); node++)
	{
		if (node->m_name == name)
		{
			if (node->m_category == CATEGORIES_EXPRESSION::PROCEDURE)
			{
				return NODE_TYPES::PROCESS;
			}
			else if (node->m_category == CATEGORIES_EXPRESSION::FUNCTION)
			{
				return NODE_TYPES::FUNCTION;
			}
		}
	}

	return value;
}

GlobalNode CNodesVars::isGlobalVar(std::string name, std::string environment)
{
	std::vector<GlobalNode>::iterator node;
	for (node = Nodes.begin(); node != Nodes.end(); node++)
	{
		if (node->m_name == name)
		{
			break;
		}
	}
	if (node == Nodes.end() || node->m_category != CATEGORIES_EXPRESSION::VAR)
	{
		return GlobalNode();
	}
	return (*node);
}

LocalNode CNodesVars::isLocalVar(std::string name, std::string environment)
{
	std::vector<GlobalNode>::iterator node;
	for (node = Nodes.begin(); node != Nodes.end(); node++)
	{
		if (node->m_name == name)
		{
			break;
		}
	}
	if (node == Nodes.end())
	{
		return LocalNode();
	}
	LocalNode* temp = node->m_nextLocal;
	while (temp != NULL)
	{
		if (temp->m_parent == environment && temp->m_category == CATEGORIES_EXPRESSION::VAR)
		{
			return (*temp);
		}
		temp = temp->m_next;
	}

	return LocalNode();
}

CNodesVars::CNodesVars()
{
}


CNodesVars::~CNodesVars()
{
}
