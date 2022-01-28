#include <conio.h>
#include <iostream>

#include "player.h"
#include "tvector2d.h"
#include "tarray.h"



Player::Player()
	:playerDead(false)
	, m_keyCount(0)
	, m_moreKeysNeeded(rand() % 10 + 8)
	, m_heartsOfTerror(0)
{
	m_team = ETeam::Player;
	m_healthTick = 30;
	m_currentWeapon = new Weapon(this);
	m_weaponInventory.addElement(m_currentWeapon);

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
	m_currentRoom->setPlayer(this);
	draw();
	m_currentWeapon->tick();
	m_healthTick--;
	if (!m_healthTick)
	{
		int health = 0;
		heal(health);
		m_healthTick = 30;
	}
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
	case 'E':
		Player::openDoor();
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
	TArray<Door*>* doors = m_currentRoom->getDoors();
	for (int i = 0; i < doors->num(); i++)
	{
		const Vector2D<int> doorPosition = doors->getElement(i)->getPosition();
		int distance = m_position.distance(doorPosition);
		if (distance < 3)
		{
			
			if (getKeys() != 0 || doors->getElement(i)->isCompleted())
			{
				if (!doors->getElement(i)->isCompleted())
				{
					doors->getElement(i)->generateSecondRoom();
					removeKey();
					m_moreKeysNeeded--;
				}

				if (!m_moreKeysNeeded && m_heartsOfTerror >= 3)
				{
					playerWon = true;
				}

				MoveCursorTo(41, 28);
				std::cout << "You are opening the door";
				doors->getElement(i)->swapRoom(this);

				return;
			}
			else
			{
				MoveCursorTo(41, 28);
				std::cout << "You don't have a key to open the door";
				return;
			}
		}
	}

	MoveCursorTo(41, 28);
	std::cout << "Dumbass, you ain't even close to a door";
}

void Player::hitCharacter(int& damage)
{
	Character::hitCharacter(damage);
	MoveCursorTo(48, 25);
	std::cout << "Player hit! Lost " << damage << " health";
}

void Player::die()
{
	playerDead = true;
}

int Player::getKeys()
{
	return m_keyCount;
}

void Player::addKey()
{
	m_keyCount++;
}

void Player::removeKey()
{
	m_keyCount--;
}

void Player::addHeart()
{
	m_heartsOfTerror++;
}

int Player::getHearts()
{
	return m_heartsOfTerror;
}

void Player::addHealth(int amount)
{
	m_health = std::min(25, m_health + amount);
}