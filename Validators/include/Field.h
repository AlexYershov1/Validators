#pragma once
#include "FieldValidator.h"
#include "BaseField.h"
#include "NoValid.h"
#include <string>
#include <iostream>
#include <vector>

template < class T >
class Field : public BaseField
{
public:
	Field(const std::string&);
	void addValidator(FieldValidator<T>*);

	virtual void setContent();
	virtual const std::string IsValid();

	// get and set functions
	T getContent() const { return this->m_content; }
	virtual std::string getSentence() const { return this->m_sentence; }
	virtual void printContent(std::ostream& os) const { os << " = " << m_content; }
	void makeInvalid() { m_valid = false; }

	~Field();

private:
	std::string m_sentence;
	std::vector<FieldValidator<T>*> m_Validator;
	T m_content;
	bool m_valid;
};

template < class T >
Field<T>::Field(const std::string& request) : m_sentence(request), m_valid(false)
{}

template < class T >
inline void Field<T>::addValidator(FieldValidator<T>* validator)
{
	m_Validator.push_back(validator);
}

template < class T >
inline void Field<T>::setContent()
{
	if (!m_valid)
	{
		fflush(stdin);
		std::cout << m_sentence << std::endl;
		if constexpr (std::is_same_v<T, std::string>)
		{
			std::getline(std::cin, m_content);
			if (m_content == "")	// in case of unclear buffer - redo 
				std::getline(std::cin, m_content);
		}
		else
			std::cin >> m_content;
		std::cout << "--------------------------------------" << std::endl;
	}
}

template<class T>
inline const std::string Field<T>::IsValid()
{
	try
	{
		for (auto validator : m_Validator)
			validator->IsValid(m_content);
	}
	catch (const NoValid& invalidField) 
	{
		m_valid = false;
		return invalidField.getErrorMsg();
	}

	m_valid = true;
	return "";
}

template < class T >
Field<T>::~Field()
{}