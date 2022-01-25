#include <iostream>
#include <cmath>

#include "wall.h"
#include "prod225cursorwrapper.h"


Wall::Wall(Vector2D<int> first, Vector2D<int> second)
{

	m_vert = first.y != second.y;
	double a = sqrt(first.x * first.x + first.y * first.y);
	double b = sqrt(second.x * second.x + second.y * second.y);
	if (a < b)
	{
		m_firstCorner = first;
		m_secondCorner = second;
	}
	else
	{
		m_firstCorner = second;
		m_secondCorner = first;
	}

	if (MEMORY_CHECK_MODE)
	{
		std::cout << "Construction of a Wall at " << this << "\n";
	}

}

Wall::~Wall()
{
	if (MEMORY_CHECK_MODE)
	{
		std::cout << "Destruction of a Wall at " << this << '\n';
	}
}

void Wall::draw() const
{
	Vector2D<int> increment;
	if (m_vert)
	{
		increment = DOWN_U_VEC;
	}
	else
	{
		increment = RIGHT_U_VEC;
	}

	for (Vector2D<int> i = m_firstCorner; i != m_secondCorner; i += increment)
	{
		cursorToVector(i);
		std::cout << char(178);
	}cursorToVector(m_secondCorner);
	std::cout << char(178);
}

Vector2D<int> Wall::getRandomPositionOnWall()
{
	Vector2D<int> newVector = m_firstCorner;
	if (m_vert)
	{
		newVector += Vector2D<int>(0, rand() % ((m_secondCorner.y - m_firstCorner.y) - 2) + 1) ;
	}
	else
	{
		newVector += Vector2D<int>(rand() % ((m_secondCorner.x - m_firstCorner.x) - 2) + 1, 0);
	}
	return newVector;
}