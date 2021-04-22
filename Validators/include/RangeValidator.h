#pragma once
#include "FieldValidator.h"

template < class T >
class RangeValidator : public FieldValidator<T>
{
public:
	RangeValidator(T, T);
	virtual void IsValid(const T&) const;
	~RangeValidator();

private:
	T m_min;
	T m_max;
};

template < class T >
RangeValidator<T>::RangeValidator(T min, T max) : m_min(min), m_max(max)
{
}

template<class T>
inline void RangeValidator<T>::IsValid(const T& birthYear) const
{
	if (birthYear < m_min || birthYear > m_max)
		throw NoValid("Age invalid- not in range");
}

template < class T >
RangeValidator<T>::~RangeValidator()
{
}