#pragma once
#include "RoomValidator.h"

const std::string RoomValidator::IsValid()
{
	if (FAMILY_ROOM_SIZE * m_fieldY->getContent() + PAIR_ROOM_SIZE * m_fieldX->getContent() < m_fieldZ->getContent())
	{
		m_fieldX->makeInvalid();
		m_fieldY->makeInvalid();
		m_fieldZ->makeInvalid();
		return m_errorMsg;
	}

	return "";
}

RoomValidator::~RoomValidator()
{
}