#include <iostream>

#include "weapon.h"

Weapon::Weapon()
	:m_type(static_cast<EType>(rand() % 4 + 2))
	, m_dropped(true)
	, m_owner(NULL)
	, m_currentProjectile(NULL)
	, m_team(m_owner->getTeam())
	, m_damage(5)
{

	setColour();

	if (MEMORY_CHECK_MODE)
	{
		std::cout << "Construction of Weapon at " << this << " (Weapon).\n";
	}
}

Weapon::~Weapon()
{
	if (MEMORY_CHECK_MODE)
	{
		std::cout << "Destruction of Weapon at " << this << " (Weapon).\n";
	}
}

Weapon::Weapon(Character* owner)
	:m_type(static_cast<EType>(rand() % 4 + 2))
	,m_dropped(false)
	, m_currentProjectile(NULL)
	, m_damage(5)
{

	setColour();

	m_owner = owner;
	m_team = m_owner->getTeam();

	if (MEMORY_CHECK_MODE)
	{
		std::cout << "Construction of Weapon at " << this << " (Weapon).\n";
	}
}

void Weapon::setColour()
{
	switch (m_type)
	{
	case EType::Earth:
		m_colour = PROD225Colours::LIGHTRED;
		break;
	case EType::Light:
		m_colour = PROD225Colours::YELLOW;
		break;
	case EType::Shadow:
		m_colour = PROD225Colours::LIGHTGRAY;
		break;
	case EType::Water:
		m_colour = PROD225Colours::LIGHTBLUE;
		break;
	default:
		m_colour = PROD225Colours::WHITE;
		break;
	}
}

void Weapon::tick()
{
	draw();
	if (m_currentProjectile != NULL)
	{
		m_currentProjectile->tick();
	}
}

void Weapon::attack()
{
	if (m_currentProjectile != NULL)
	{
		deleteProjectile();
	}
	m_currentProjectile = new Projectile(this);
}

void Weapon::draw()
{

	SetTextColour(m_colour, PROD225Colours::BLACK);
	if (m_dropped)
	{
		cursorToVector(m_position);
	}
	else
	{
		cursorToVector(*(m_owner->getHandPosition()));
	}

	std::cout << 'x';
	
}

void Weapon::deleteProjectile()
{
	delete m_currentProjectile;
	m_currentProjectile = NULL;
}

EAttackDirection Weapon::getDirection()
{
	return *(m_owner->getDirection());
}

Vector2D<int>* Weapon::getPosition()
{
	return m_owner->getHandPosition();
}

PROD225Colours* Weapon::getColour()
{
	return &m_colour;
}

Character* Weapon::getOwner()
{
	return m_owner;
}

EType Weapon::getType()
{
	return m_type;
}

ETeam Weapon::getTeam()
{
	return m_team;
}

int Weapon::getDamage()
{
	return m_damage;
}