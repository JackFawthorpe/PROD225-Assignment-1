#include <iostream>

#include "character.h"
#include "prod225colour.h"
#include "tvector2d.h"


Character::Character()
	:m_position(1, 1)
	, m_weaponDirection(EAttackDirection::Right)
	, m_leftHand(0, 1)
	, m_rightHand(2, 1)
	, m_currentHand(&m_rightHand)
	, m_health(25)
{
	m_currentWeapon = new Weapon(this);
	m_weaponInventory.addElement(m_currentWeapon);

	if (MEMORY_CHECK_MODE)
	{
		std::cout << "Construction of a character at " << this << " (Character).\n";
	}
}


Character::~Character()
{

	if (MEMORY_CHECK_MODE)
	{
		std::cout << "Destruction of a character at " << this << " (Character).\n";
	}
}


void Character::draw()
{
	cursorToVector(m_position);
	std::cout << "C";
}

void Character::move(EDirection direction)
{
	switch (direction)
	{
	case EDirection::Left:
		if (m_position.x != 2)
		{
			m_position += LEFT_U_VEC;
			m_leftHand += LEFT_U_VEC;
			m_rightHand += LEFT_U_VEC;
			m_currentHand = &m_leftHand;
			m_weaponDirection = EAttackDirection::Left;
		}
		break;
	case EDirection::Right:
		if (m_position.x != 117)
		{
			m_position += RIGHT_U_VEC;
			m_leftHand += RIGHT_U_VEC;
			m_rightHand += RIGHT_U_VEC;
			m_currentHand = &m_rightHand;
			m_weaponDirection = EAttackDirection::Right;
		}
		break;
	case EDirection::Up:
		if (m_position.y != 2)
		{
			m_position += UP_U_VEC;
			m_leftHand += UP_U_VEC;
			m_rightHand += UP_U_VEC;
		}
		break;
	case EDirection::Down:
		if (m_position.y != 20)
		{
			m_position += DOWN_U_VEC;
			m_leftHand += DOWN_U_VEC;
			m_rightHand += DOWN_U_VEC;
		}
		break;
	}
}

void Character::attack()
{
	m_currentWeapon->attack();
}

void Character::setPosition(int x, int y)
{
	m_position.x = x;
	m_position.y = y;
	m_leftHand = m_position + LEFT_U_VEC;
	m_rightHand = m_position + RIGHT_U_VEC;
}

Vector2D<int>* Character::getPosition() 
{
	return &m_position;
}

EAttackDirection* Character::getDirection()
{
	return &m_weaponDirection;
}

Vector2D<int>* Character::getHandPosition()
{
	return m_currentHand;
}

int Character::getHealth() const
{
	return m_health;
}

TArray<Weapon*>* Character::getInventory()
{
	return &m_weaponInventory;
}

void Character::setRoom(Room* currentRoom)
{
	m_currentRoom = currentRoom;
}

Room* Character::getRoom() const
{
	return m_currentRoom;
}