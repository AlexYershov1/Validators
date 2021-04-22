#pragma once
#include "SumValidator.h"

const std::string SumValidator::IsValid()
{
	if (m_fieldY->getContent() + m_fieldZ->getContent() != m_fieldX->getContent())
	{
		m_fieldX->makeInvalid();
		m_fieldY->makeInvalid();
		m_fieldZ->makeInvalid();
		return m_errorMsg;
	}

	return "";
}

SumValidator::~SumValidator()
{
}