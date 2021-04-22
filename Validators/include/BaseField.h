#pragma once

class BaseField
{
public:
	BaseField() {}
	virtual void setContent() = 0;
	virtual const std::string IsValid()= 0;
	virtual std::string getSentence() const = 0;
	virtual void printContent(std::ostream&) const = 0;
	~BaseField() {}

private:

};