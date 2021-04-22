#pragma once
#include <string>

template < class T >
class FieldValidator
{
public:
	FieldValidator();
	virtual void IsValid(const T&) const = 0;
	~FieldValidator();

private:

};

template < class T >
FieldValidator<T>::FieldValidator()
{
}

template < class T >
FieldValidator<T>::~FieldValidator()
{
}
