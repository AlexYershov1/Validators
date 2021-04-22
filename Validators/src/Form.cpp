#pragma once
#include "Form.h"

Form::Form()
{
}

void Form::addField(BaseField* field)
{
	this->m_fields.push_back(field);
	this->m_errorMsg.push_back("");
}

void Form::addValidator(FormValidator* validator)
{
	this->m_validators.push_back(validator);
}

void Form::fillForm()
{
	for (auto field : this->m_fields)
		field->setContent();
}

bool Form::validateForm()
{
	auto formValid = true;
	auto Index = 0;
	for (auto field : this->m_fields)
	{
		if ((m_errorMsg[Index++] = field->IsValid()) != "")
			formValid = false;
	}
	for (auto validator : this->m_validators)
	{
		std::string formError;
		if ((formError = validator->IsValid()) != "")
		{
			m_errorMsg.push_back(formError);
			formValid = false;
		}
	}
	return formValid;
}

std::ostream& Form::printForm(std::ostream& os)
{
	auto error = m_errorMsg.begin();
	auto lastFieldError = error;

	for (auto field : m_fields)
	{
		os << "--------------------------------------\n" << field->getSentence();
		field->printContent(os);
		os << '\t' << *error << std::endl <<
			"--------------------------------------\n";
		lastFieldError = error;
		error++;
	}

	error = m_errorMsg.end() - 1;

	while (error != lastFieldError)
	{
		os << *error << std::endl;
		m_errorMsg.pop_back();
		error = m_errorMsg.end() - 1;
	}

	return os;
}

Form::~Form()
{
}

std::ostream& operator<< (std::ostream& os, Form& form)
{
	form.printForm(os);
	return os;
}