#include "CErrorHandler.h"

void CErrorHandler::AddError(std::string error, std::string phase)
{
	m_numberErrors++;
	m_Errors += error + "\t" + phase + "\t" + std::to_string(line) + "\n";
}

void CErrorHandler::AddError(std::string error, std::string phase, int line)
{
	m_numberErrors++;
	m_Errors += error + "\t" + phase + "\t" + std::to_string(line) + "\n";
}

int CErrorHandler::GetNumberError()
{
	return m_numberErrors;
}

void CErrorHandler::Nextline()
{
	line++;
}

void CErrorHandler::Initialize()
{
	line = 1;
	m_Errors = "";
	m_numberErrors = 0;
}

std::string CErrorHandler::GetErrors()
{
	return m_Errors;
}

LEXIC_STATES::E CErrorHandler::SetType(std::string type)
{
	if (type == "float")
	{
		return LEXIC_STATES::lNUMBERFLOAT;
	}
	if (type == "string")
	{
		return LEXIC_STATES::lSTRING;
	}
	if (type == "bool")
	{
		return LEXIC_STATES::lBOOL;
	}
	if (type == "int")
	{
		return LEXIC_STATES::lNUMBERINT;
	}

	return LEXIC_STATES::lNONE;
}

CErrorHandler::CErrorHandler()
{
	
	Initialize();

}


CErrorHandler::~CErrorHandler()
{
}
