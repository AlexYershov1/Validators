#pragma once
#include <vector>
#include "FormValidator.h"

class Form
{
public:
	Form();
	void addField(BaseField*);
	void addValidator(FormValidator*);
	void fillForm();
	bool validateForm();
	std::ostream& printForm(std::ostream&);
	~Form();

private:
	std::vector<BaseField*> m_fields;
	std::vector<FormValidator*> m_validators;
	std::vector<std::string> m_errorMsg;
};

std::ostream& operator<< (std::ostream& os, Form& form);