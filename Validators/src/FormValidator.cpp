#pragma once
#include "FormValidator.h"

FormValidator::FormValidator(const std::string& errorMsg, Field<int>* fieldX, Field<int>* fieldY, Field<int>* fieldZ)
	: m_errorMsg(errorMsg), m_fieldX(fieldX), m_fieldY(fieldY), m_fieldZ(fieldZ)
{
}

FormValidator::~FormValidator()
{
}