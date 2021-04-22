#pragma once
#include "FieldValidator.h"

template < class T >
class NonNegativeValidator : public FieldValidator<T>
{
public:
	NonNegativeValidator();
	virtual void IsValid(const T&) const;
	~NonNegativeValidator();

private:

};

template < class T >
NonNegativeValidator<T>::NonNegativeValidator()
{
}

template<class T>
inline void NonNegativeValidator<T>::IsValid(const T& number) const
{
	if (number < 0)
		throw NoValid("Negative number");
}

template < class T >
NonNegativeValidator<T>::~NonNegativeValidator()
{
}