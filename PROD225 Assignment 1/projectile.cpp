#include <iostream>

#include "projectile.h"

Projectile::Projectile(Weapon* weaponUsed)
	:m_weaponUsed(weaponUsed)
	, m_direction(weaponUsed->getDirection())
	, m_stepsLeft(3)
	, m_velocity(2)
{

	m_colour = m_weaponUsed->getColour();

	switch (m_direction)
	{
	case EAttackDirection::Left:
		m_position = *weaponUsed->getPosition() + LEFT_U_VEC;
	case EAttackDirection::Right:
		m_position = *weaponUsed->getPosition() + RIGHT_U_VEC;
	}

	if (MEMORY_CHECK_MODE)
	{
		std::cout << "Construction of Projectile at " << this << "\n";
	}
}

Projectile::~Projectile()
{
	if (MEMORY_CHECK_MODE)
	{
		std::cout << "Destruction of Projectile at " << this << "\n";
	}
}

void Projectile::tick()
{
	if (m_stepsLeft == 0)
	{
		m_weaponUsed->deleteProjectile();
	}
	else
	{
		move();
		draw();
	}
}

void Projectile::collisionDetect()
{

}

void Projectile::move()
{
	m_stepsLeft--;
	if (m_direction == EAttackDirection::Left)
	{
		m_position += LEFT_U_VEC * m_velocity;
	}
	else
	{
		m_position += RIGHT_U_VEC * m_velocity;
	}
}

void Projectile::draw()
{
	SetTextColour(PROD225Colours::RED, PROD225Colours::BLACK);
	cursorToVector(m_position);
	std::cout << char(254);
}
