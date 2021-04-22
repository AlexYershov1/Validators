#pragma once
#include "FormValidator.h"

const int FAMILY_ROOM_SIZE = 5;
const int PAIR_ROOM_SIZE = 2;

class RoomValidator : public FormValidator
{
public:
	using FormValidator::FormValidator;
	virtual const std::string IsValid();
	~RoomValidator();
	
private:
	// m_fieldX is pair rooms field
	// m_fieldY is family rooms field
	// m_fieldZ is total people field
};