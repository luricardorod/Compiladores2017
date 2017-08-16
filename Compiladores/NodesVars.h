#pragma once
#include <string>
#include <vector>
#include "CErrorHandler.h"
#include "CTokenizer.h"
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
	CATEGORIES_EXPRESSION::E m_category = CATEGORIES_EXPRESSION::NULLCATEGORY;
	LEXIC_STATES::E m_type = LEXIC_STATES::lNONE;
	int m_dimension;
	std::string m_parent;
	std::vector<std::string> m_values;
	LocalNode *m_next;
};
struct GlobalNode {
	std::string m_name;
	CATEGORIES_EXPRESSION::E m_category = CATEGORIES_EXPRESSION::NULLCATEGORY;
	LEXIC_STATES::E m_type = LEXIC_STATES::lNONE;
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
	std::string GetType(std::string name, std::string environment);
	GlobalNode isFunctionProcedureAndNotVar(std::string name, std::string environment);
	std::string CategoriesToString(CATEGORIES_EXPRESSION::E category);
	std::string TypeToString(LEXIC_STATES::E type);
	std::string localNodeToText(LocalNode localnode);
	NODE_TYPES::E GetCategory(std::string name);
	GlobalNode isGlobalVar(std::string name, std::string environment);
	LocalNode isLocalVar(std::string name, std::string environment);

	CNodesVars();
	~CNodesVars();
};

