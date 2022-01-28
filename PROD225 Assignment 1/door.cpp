#include <iostream>

#include "door.h"
#include "prod225cursorwrapper.h"

Door::Door(Room* startRoom)
	:m_firstRoom(startRoom)
	, m_currentRoom(startRoom)
	, m_currentPosition(&m_firstPosition)
	, m_completed(false)
{
	int wallIndex = rand() % m_firstRoom->getWalls()->num();
	m_firstPosition = m_firstRoom->getWalls()->getElement(wallIndex)->getRandomPositionOnWall();
	m_secondPosition = Vector2D<int>(1, 0);
	if (MEMORY_CHECK_MODE)
	{
		std::cout << "Construction of door at " << this << "(Door)\n";
	}
}

Door::~Door()
{
	if (MEMORY_CHECK_MODE)
	{
		std::cout << "Destruction of door at " << this << "(Door)\n";
	}
}

void Door::draw() const
{
	cursorToVector(*m_currentPosition);
	if (m_completed)
	{
		std::cout << "O";
	}
	else
	{
		std::cout << char(241);
	}
}

Vector2D<int> Door::getPosition() const
{
	return *m_currentPosition;
}

void Door::generateSecondRoom()
{
	if (m_firstPosition.x == 0)
	{
		m_secondPosition.x = 119;
		m_secondPosition.y = m_firstPosition.y;
	}
	else if (m_firstPosition.x == 119)
	{
		m_secondPosition.x = 0;
		m_secondPosition.y = m_firstPosition.y;
	}
	else if (m_firstPosition.y == 0)
	{
		m_secondPosition.x = m_firstPosition.x;
		m_secondPosition.y = 22;
	}
	else
	{
		m_secondPosition.x = m_firstPosition.x;
		m_secondPosition.y = 0;
	}
	m_secondRoom = new Room(this);
	m_offRoom = m_secondRoom;
	m_offPosition = &m_secondPosition;
	m_completed = true;
}

bool Door::isCompleted()
{
	return m_completed;
}

void Door::swapRoom(Character* character)
{
	Room* temp = m_currentRoom;
	m_currentRoom = m_offRoom;
	m_offRoom = temp;
	Vector2D<int> playerOffset = *m_currentPosition + *character->getPosition() * -1;
	Vector2D<int>* posTemp = m_currentPosition;
	m_currentPosition = m_offPosition;
	m_offPosition = posTemp;
	playerOffset += *m_currentPosition;
	character->setPosition(playerOffset.x, playerOffset.y);
	character->setRoom(m_currentRoom);

}