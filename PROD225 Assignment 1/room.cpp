#include <iostream>

#include "room.h"
#include "prod225colour.h"


Room::Room()
	:m_colour(static_cast<PROD225Colours> (rand() % 15 + 1))
{
	Wall* tempWall = new Wall(Vector2D<int>(0, 0), Vector2D<int>(119, 0), this);
	m_walls.addElement(tempWall);
	tempWall = new Wall(Vector2D<int>(119, 0), Vector2D<int>(119, 22), this);
	m_walls.addElement(tempWall);
	tempWall = new Wall(Vector2D<int>(0, 0), Vector2D<int>(0, 22), this);
	m_walls.addElement(tempWall);
	tempWall = new Wall(Vector2D<int>(0, 22), Vector2D<int>(119, 22), this);
	m_walls.addElement(tempWall);

	for (int i = 0; i < 3; i++)
	{
		Enemy* roomEnemy = new (Enemy);
		roomEnemy->setPosition(rand() % 115 + 3, rand() % 15 + 3);
		roomEnemy->addToRoom(this);
		m_enemies.addElement(roomEnemy);
	}

	int doors = rand() % 3 + 1;

	for (int i = 0; i < doors; i++)
	{
		Door* newDoor = new Door(this);
		m_doors.addElement(newDoor);
		Enemy* roomEnemy = new (Enemy);
		roomEnemy->setPosition(rand() % 115 + 3, rand() % 15 + 3);
		roomEnemy->giveKey();
		roomEnemy->addToRoom(this);
		m_enemies.addElement(roomEnemy);
	}

	m_roomBoss = new (Boss);
	m_roomBoss->setPosition(rand() % 115 + 3, rand() % 15 + 3);
	m_roomBoss->addToRoom(this);

	if (MEMORY_CHECK_MODE)
	{
		std::cout << "Room Constructed at " << this << "\n";
	}
}

Room::~Room()
{

	for (int i = 0; i < m_walls.num(); i++)
	{
		delete m_walls.getElement(i);
	}

	delete[] &m_walls;

	if (MEMORY_CHECK_MODE)
	{
		std::cout << "Room Destructed at " << this << "\n";
	}
}

Room::Room(Door* door)
	: Room()
{
	for (int i = 0; i < m_doors.num(); i++)
	{
		if (door->getPosition() == m_doors.getElement(i)->getPosition())
		{
			delete m_doors.getElement(i);
			m_doors.removeElement(i);
			m_doors.addElement(door);
			return;
		}
	}
	m_doors.addElement(door);
}
void Room::tick()
{
	for (int i = 0; i < m_enemies.num(); i++)
	{
		m_enemies.getElement(i)->tick();
	}
	draw();
	for (int i = 0; i < m_doors.num(); i++)
	{
		m_doors.getElement(i)->draw();
	}
	if (!m_roomBoss->isDead)
	{
		m_roomBoss->tick();
	}
}

void Room::draw() const
{
	SetTextColour(m_colour, PROD225Colours::BLACK);
	for (int i = 0; i < m_walls.num(); i++)
	{
		m_walls.getElement(i)->draw();
	}
}

void Room::setPlayer(Player* player)
{
	m_player = player;
}

TArray<Wall*>* Room::getWalls()
{
	return &m_walls;
}

TArray<Door*>* Room::getDoors()
{
	return &m_doors;
}

TArray<Enemy*>* Room::getEnemies()
{
	return &m_enemies;
}

Player* Room::getPlayer()
{
	return m_player;
}

PROD225Colours Room::getColour()
{
	return m_colour;
}

Boss* Room::getBoss()
{
	return m_roomBoss;
}