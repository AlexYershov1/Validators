#pragma once
#include "Field.h"

class FormValidator
{
public:
	FormValidator(const std::string&, Field<int>*, Field<int>*, Field<int>*);
	virtual const std::string IsValid() = 0;
	~FormValidator();

protected:
	std::string m_errorMsg;
	Field<int>* m_fieldX;
	Field<int>* m_fieldY;
	Field<int>* m_fieldZ;
};