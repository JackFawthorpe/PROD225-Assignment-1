#include <iostream>

#include "enemy.h"

Enemy::Enemy()
	:m_moveTick(0)
{

	m_type = static_cast<EType> (rand() % 4 + 2);

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
}

void Enemy::setPosition(int x, int y)
{
	m_position.x = x;
	m_position.y = y;
	
	m_leftHand = m_position + Vector2D<int>(-2, 0);
	m_rightHand = m_position + Vector2D<int>(2, 0);
}