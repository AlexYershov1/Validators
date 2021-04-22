#pragma once
#include "NoValid.h"

NoValid::NoValid() : m_error("")
{
}

NoValid::NoValid(const std::string& errorMsg) : m_error(errorMsg)
{
}

const std::string NoValid::getErrorMsg() const
{
	return this->m_error;
}


NoValid::~NoValid()
{
}