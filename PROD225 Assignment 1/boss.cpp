#include <iostream>

#include "boss.h"


Boss::Boss()
	:m_moveTick(0)
	,isDead(false)
{
	m_type = static_cast<EType> (rand() % 4 + 2);

	m_leftWeapon = new Weapon(this);
	m_weaponInventory.addElement(m_leftWeapon);
	m_rightWeapon = new Weapon(this);
	m_weaponInventory.addElement(m_rightWeapon);

	switch (m_type)
	{
	case EType::Shadow:
		m_colour = PROD225Colours::LIGHTGRAY;
		break;
	case EType::Light:
		m_colour = PROD225Colours::YELLOW;
		break;
	case EType::Earth:
		m_colour = PROD225Colours::LIGHTRED;
		break;
	case EType::Water:
		m_colour = PROD225Colours::LIGHTBLUE;
		break;
	default:
		m_colour = PROD225Colours::WHITE;
		break;
	}

	if (MEMORY_CHECK_MODE)
	{
		std::cout << "Constructing boss at " << this << "(BOSS)";
	}
}

Boss::~Boss()
{
	if (MEMORY_CHECK_MODE)
	{
		std::cout << "Destructing boss at " << this << "(BOSS)";
	}
}

void Boss::tick()
{
	m_moveTick++;
	if (m_moveTick >= 2)
	{
		move();
	}
	draw();
	m_currentHand = &m_leftHand;
	m_leftWeapon->tick();
	m_currentHand = &m_rightHand;
	m_rightWeapon->tick();
}

void Boss::draw()
{
	SetTextColour(PROD225Colours::BLACK, m_colour);
	cursorToVector(m_position + UP_U_VEC + LEFT_U_VEC);
	std::cout << "X^X";
	cursorToVector(m_position + LEFT_U_VEC);
	std::cout << ">X<";
	cursorToVector(m_position + LEFT_U_VEC + DOWN_U_VEC);
	std::cout << "XvX";
}

void Boss::move()
{
	EDirection direction = static_cast<EDirection>(rand() % 4);
	Character::move(direction);
	if (m_shootFlag)
	{
		Boss::attack();
		m_shootFlag = 0;
	}
	else
	{
		m_shootFlag = 1;
	}
}

void Boss::attack()
{
	m_currentHand = &m_leftHand;
	m_weaponDirection = EAttackDirection::Left;
	m_leftWeapon->attack();
	m_currentHand = &m_rightHand;
	m_weaponDirection = EAttackDirection::Right;
	m_rightWeapon->attack();
}


void Boss::setPosition(int x, int y)
{
	m_position.x = x;
	m_position.y = y;

	m_leftHand = m_position + Vector2D<int>(-2, 0);
	m_rightHand = m_position + Vector2D<int>(2, 0);
}

void Boss::die()
{
	MoveCursorTo(48, 25);
	std::cout << "This room's boss has died!";
	MoveCursorTo(43, 26);
	std::cout << "You grab the jewel out of his chest";
	m_currentRoom->getPlayer()->addHeart();
	m_currentRoom->getPlayer()->addHealth(10);
	isDead = true;
	
}

EType Boss::getType()
{
	return m_type;
}