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
		globalNode.m_values.resize(globalNode.m_dimension);
		Nodes.push_back(globalNode);
	}
	else
	{
		if (node->m_category == "var" && node->m_category == globalNode.m_category)
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
		temp.m_category = "indef";
		temp.m_dimension = 0;
		temp.m_nextGlobal = NULL;
		temp.m_type = "indef";
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

std::string CNodesVars::GetNodes()
{
	Nodes;
	return "";
}


CNodesVars::CNodesVars()
{
}


CNodesVars::~CNodesVars()
{
}