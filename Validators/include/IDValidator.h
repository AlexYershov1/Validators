#pragma once
#include "FieldValidator.h"
#include "NoValid.h"
#include <stack>

int const DIGIT_DIV = 10;
int const ID_SIZE = 9;

class IDValidator : public FieldValidator<uint32_t>
{
public:
	IDValidator();
	virtual void IsValid(const uint32_t&) const;
	~IDValidator();

private:

};