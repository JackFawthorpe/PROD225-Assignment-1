#include <conio.h>
#include <iostream>

#include "player.h"
#include "tvector2d.h"
#include "tarray.h"



Player::Player()
{
	if (MEMORY_CHECK_MODE)
	{
		std::cout << "Construction of a Player at " << this << " (Player).\n";
	}
}

Player::~Player()
{
	if (MEMORY_CHECK_MODE)
	{
		std::cout << "Destruction of a Player at " << this << " (Character).\n";
	}
}

void Player::tick(char& keyPressed)
{
	evaluateKeyPress(keyPressed);
	draw();
	m_currentWeapon->tick();
}

void Player::evaluateKeyPress(char& keyPressed)
{
	EDirection direction = EDirection::Left;
	switch (keyPressed)
	{
	case LEFT_KEY:
		direction = EDirection::Left;
		Character::move(direction);
		break;
	case RIGHT_KEY:
		direction = EDirection::Right;
		Character::move(direction);
		break;
	case UP_KEY:
		direction = EDirection::Up;
		Character::move(direction);
		break;
	case DOWN_KEY:
		direction = EDirection::Down;
		Character::move(direction);
		break;
	case SPACE_BAR:
		Character::attack();
		break;
	}
	
}

void Player::draw()
{
	SetTextColour(PROD225Colours::WHITE, PROD225Colours::BLACK);
	cursorToVector(m_position + UP_U_VEC);
	std::cout << char(64);
	cursorToVector(m_position);
	std::cout << '|';
	cursorToVector(m_position + DOWN_U_VEC);
	std::cout << '^';
}

void Player::openDoor()
{

}
