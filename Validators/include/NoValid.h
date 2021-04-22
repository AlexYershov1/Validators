#pragma once
#include <string>

class NoValid
{
public:
	NoValid();
	NoValid(const std::string&);
	const std::string getErrorMsg() const;
	~NoValid();

private:
	std::string m_error;
};