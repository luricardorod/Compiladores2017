#include "CLCloseDimensionOperator.h"



LEXIC_STATES::E CLCloseDimensionOperator::Evaluate(char character)
{
	return LEXIC_STATES::E();
}

LEXIC_STATES::E CLCloseDimensionOperator::Enter(char character, std::string string)
{
	m_tokenaizer->AddToken("]", "Close Dimension Operator");
	return LEXIC_STATES::lNONE;
}

std::string CLCloseDimensionOperator::Exit()
{
	return std::string();
}

CLCloseDimensionOperator::CLCloseDimensionOperator()
{
}


CLCloseDimensionOperator::~CLCloseDimensionOperator()
{
}
