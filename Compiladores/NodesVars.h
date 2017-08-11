#pragma once
#include <string>
#include <vector>
#include "CErrorHandler.h"

namespace NODE_TYPES
{
	enum E
	{
		NODENULL,
		PROCESS,
		FUNCTION,
		MAIN,
		TYPES_MAX
	};
}
struct LocalNode {
	std::string m_name;
	std::string m_category;
	std::string m_type;
	int m_dimension;
	std::string m_parent;
	std::vector<std::string> m_values;
	LocalNode *m_next;
};
struct GlobalNode {
	std::string m_name;
	std::string m_category;
	std::string m_type;
	int m_dimension;
	std::vector<std::string> m_values;
	LocalNode *m_nextLocal;
	GlobalNode *m_nextGlobal;
};

class CNodesVars
{
public:
	CErrorHandler *m_errorHandler;
	std::vector<GlobalNode> Nodes;
	void Init();
	void addGlobalNode(GlobalNode globalNode, int line);
	void addLocalNode(LocalNode localNode, int line);
	void errorCategory(std::string category, int line);
	std::string GetNodes();
	NODE_TYPES::E GetType(std::string name);
	CNodesVars();
	~CNodesVars();
};

