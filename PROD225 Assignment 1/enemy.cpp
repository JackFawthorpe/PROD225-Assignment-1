#include <iostream>

#include "enemy.h"

Enemy::Enemy()
	:m_moveTick(0)
	, m_holdKey(false)
{

	m_type = static_cast<EType> (rand() % 4 + 2);

	m_currentWeapon = new Weapon(this);
	m_weaponInventory.addElement(m_currentWeapon);

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
		std::cout << "Construction of a Enemy at " << this << " (Enemy).\n";
	}
}

Enemy::~Enemy()
{
	if (MEMORY_CHECK_MODE)
	{
		std::cout << "Destruction of a Enemy at " << this << " (Enemy).\n";
	}
}

void Enemy::tick()
{
	m_moveTick++;
	if (m_moveTick >= 2)
	{
		m_moveTick = 0;
		move();
	}
	draw();

	m_currentWeapon->tick();
}


void Enemy::draw()
{
	SetTextColour(PROD225Colours::BLACK, m_colour);
	cursorToVector(m_position + UP_U_VEC + LEFT_U_VEC);
	std::cout << "/-\\";
	cursorToVector(m_position + LEFT_U_VEC);
	std::cout << "|+|";
	cursorToVector(m_position + LEFT_U_VEC + DOWN_U_VEC);
	std::cout << "\\-/";
}

void Enemy::move()
{
	EDirection direction = static_cast<EDirection>(rand() % 4);
	Character::move(direction);
	if (m_shootFlag)
	{
		Character::attack();
		m_shootFlag = 0;
	}
	else
	{
		m_shootFlag = 1;
	}
}

void Enemy::setPosition(int x, int y)
{
	m_position.x = x;
	m_position.y = y;
	
	m_leftHand = m_position + Vector2D<int>(-2, 0);
	m_rightHand = m_position + Vector2D<int>(2, 0);
}


void Enemy::hitCharacter(int& damage)
{
	Character::hitCharacter(damage);
	MoveCursorTo(46, 24);
	std::cout << "Hit enemy! They lost " << damage << " health";
}

void Enemy::die()
{
	MoveCursorTo(53, 25);
	std::cout << "The enemy died!";
	MoveCursorTo(48, 26);
	std::cout << "You picked up their weapon";
	m_currentRoom->getPlayer()->getInventory()->addElement(m_currentWeapon);
	m_currentRoom->getPlayer()->addHealth(5);
	if (hasKey())
	{
		MoveCursorTo(51, 27);
		std::cout << "They carried a key!";
		m_currentRoom->getPlayer()->addKey();
	}
	else
	{
		MoveCursorTo(48, 27);
		std::cout << "The enemy didnt have a key";
	}
	for (int i = 0; i < m_currentRoom->getEnemies()->num(); i++)
	{
		if (m_currentRoom->getEnemies()->getElement(i) == this)
		{
			m_currentRoom->getEnemies()->removeElement(i);
			delete this;
			break;
		}
	}
}

void Enemy::giveKey()
{
	m_holdKey = true;
}

bool Enemy::hasKey()
{
	return m_holdKey;
}

EType Enemy::getType()
{
	return m_type;
}