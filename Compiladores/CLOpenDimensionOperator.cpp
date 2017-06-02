#include "CLOpenDimensionOperator.h"



LEXIC_STATES::E CLOpenDimensionOperator::Evaluate(char character)
{
	return LEXIC_STATES::E();
}

LEXIC_STATES::E CLOpenDimensionOperator::Enter(char character, std::string string)
{
	m_tokenaizer->AddToken("[", "Open Dimension Operator");
	return LEXIC_STATES::lNONE;
}

std::string CLOpenDimensionOperator::Exit()
{
	return std::string();
}

CLOpenDimensionOperator::CLOpenDimensionOperator()
{
}


CLOpenDimensionOperator::~CLOpenDimensionOperator()
{
}
