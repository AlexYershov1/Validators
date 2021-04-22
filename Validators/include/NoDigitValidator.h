#pragma once
#include "FieldValidator.h"
#include "NoValid.h"

class NoDigitValidator : public FieldValidator<std::string>
{
public:
	NoDigitValidator();
	virtual void IsValid(const std::string&) const;
	~NoDigitValidator();

private:

};

NoDigitValidator::NoDigitValidator()
{
}

inline void NoDigitValidator::IsValid(const std::string& str) const
{
	for (auto ch : str)
	{
		if (isdigit(ch))
			throw NoValid("Contains digit");
	}
}

NoDigitValidator::~NoDigitValidator()
{
}