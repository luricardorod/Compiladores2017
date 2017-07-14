#include "CLNone.h"


LEXIC_STATES::E CLNone::Evaluate(char character)
{
	if (character == 10)
	{
		m_errorHandler->Nextline();
		return LEXIC_STATES::lNONE;
	}
	else if (character == 32 || character == 9)
	{
		return LEXIC_STATES::lNONE;
	}
	else if (IsLetter(character) || Is_(character))
	{
		return LEXIC_STATES::lID;
	}
	else if (IsNumber(character))
	{
		return LEXIC_STATES::lNUMBERINT;
	}
	else if (character == 91)
	{
		return LEXIC_STATES::lOPENDIMENSIONOPERATOR;
	}
	else if (character == 93)
	{
		return LEXIC_STATES::lCLOSEDIMENSIONOPERATOR;
	}
	else if (IsAritmeticOperator(character))
	{
		return LEXIC_STATES::lARITMETICOPERATORS;
	}
	else if (IsDelimiter(character))
	{
		return LEXIC_STATES::lDELIMITERS;
	}
	else if (IsGroupOperators(character))
	{
		return LEXIC_STATES::lGROUPOPERATORS;
	}
	else if(isLogicOperators(character))
	{
		return LEXIC_STATES::lLOGICOPERATORS;
	}
	else if (character == '"')
	{
		return LEXIC_STATES::lCONSTANTALFANUMERIC;
	}
	else if (character == '=')
	{
		return LEXIC_STATES::lASSIGN;
	}
	else if (isRelacionalOperators(character))
	{
		return LEXIC_STATES::lRELACIONALOPERATORS;
	}
	else
	{
		m_errorHandler->AddError(ERROR1, "Lexico");
		//error caracteres invalidos
	}
	return LEXIC_STATES::lNONE;
}

LEXIC_STATES::E CLNone::Enter(char character, std::string string)
{
	return LEXIC_STATES::lNONE;
}

std::string CLNone::Exit()
{
	return std::string();
}

CLNone::CLNone()
{
}


CLNone::~CLNone()
{
}
