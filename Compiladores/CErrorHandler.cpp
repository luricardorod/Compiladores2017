#include "CErrorHandler.h"

void CErrorHandler::AddError(std::string error, std::string phase)
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
	line = 0;
	m_Errors = "";
	m_numberErrors = 0;
}

std::string CErrorHandler::GetErrors()
{
	return m_Errors;
}

CErrorHandler::CErrorHandler()
{
	
	Initialize();

}


CErrorHandler::~CErrorHandler()
{
}
