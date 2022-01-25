#include <iostream>

#include "door.h"
#include "prod225cursorwrapper.h"

Door::Door(Room* startRoom)
	:m_firstRoom(startRoom)
	//,m_secondRoom(new Room)
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
	cursorToVector(m_firstPosition);
	std::cout << char(241);
}