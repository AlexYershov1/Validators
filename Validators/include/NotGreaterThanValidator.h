#pragma once
#include "FieldValidator.h"

template < class T >
class NotGreaterThanValidator : public FieldValidator<T>
{
public:
	NotGreaterThanValidator(T);
	virtual void IsValid(const T&) const;
	~NotGreaterThanValidator();

private:
	const T m_limit;
};

template < class T >
NotGreaterThanValidator<T>::NotGreaterThanValidator(T limit) : m_limit(limit)
{
}

template<class T>
inline void NotGreaterThanValidator<T>::IsValid(const T& content) const
{
	if (content > m_limit)
		throw NoValid("Out of range");
}

template < class T >
NotGreaterThanValidator<T>::~NotGreaterThanValidator()
{
}