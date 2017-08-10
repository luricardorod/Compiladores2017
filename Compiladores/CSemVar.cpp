#include "CSemVar.h"
#include <string>
#include <vector>



SEMANTIC_STATES::E CSemVar::Evaluate(Token token, SEMANTIC_STATES::E oldState, std::string parent)
{
	while (token.svalue != ";" && token.svalue != "NULL")
	{
		token = NextToken();
	}
	return SEMANTIC_STATES::SPROGRAM;
}

CSemVar::CSemVar()
{
}


CSemVar::~CSemVar()
{
}
