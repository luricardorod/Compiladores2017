#pragma once
#include <string>
#include <vector>
#include "CErrorHandler.h"
namespace LEXIC_STATES
{
	enum E
	{
		lNONE,
		lID,			//a...z | A...Z | _ [<text>] done
		lNUMBERINT,		//0...9 [number] done
		lNUMBERFLOAT,	//[number] . [number] done
		lCOMMENTS,		///*....*/ done
		lLOGICOPERATORS, //&&, || , ! done
		lARITMETICOPERATORS,  // +, -, *, / , %, ^ done
		lRELACIONALOPERATORS, //<, >, <= , >= , == , != done
		lASSIGN,     //= done
		lCONSTANTALFANUMERIC, //"..." done
		lDELIMITERS, // , ; : done
		lGROUPOPERATORS, //(, ), { , } done
		lOPENDIMENSIONOPERATOR, // [ done
		lCLOSEDIMENSIONOPERATOR, // ] done
		lKEYWORD,
		lSTATES_MAX
	};
}
struct Token
{
	std::string svalue;
	int itype;
	int line;
};
class CTokenizer
{
public:
	CErrorHandler *m_errorHandler;
	std::vector<Token> m_listTokens;
	std::string m_tokens;
	void AddToken(std::string token, std::string typeString, int typeLexic);
	std::string GetTokens();
	void Initialize();
	CTokenizer();
	~CTokenizer();
};

