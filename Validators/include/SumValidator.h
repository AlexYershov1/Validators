#pragma once
#include "FormValidator.h"

class SumValidator : public FormValidator
{
public:
	using FormValidator::FormValidator;
	virtual const std::string IsValid();
	~SumValidator();

private:
	// m_fieldX is total people field
	// m_fieldY is kid amount field
	// m_fieldZ is adult amount field
};