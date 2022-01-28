#include <iostream>

#include "projectile.h"

Projectile::Projectile(Weapon* weaponUsed)
	:m_weaponUsed(weaponUsed)
	, m_direction(weaponUsed->getDirection())
	, m_stepsLeft(3)
	, m_velocity(2)
	, m_team(weaponUsed->getTeam())
	, m_toDie(false)
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
		collisionDetect();
		draw();
		if (m_toDie)
		{
			m_weaponUsed->deleteProjectile();
		}
	}
}

int Projectile::calculateEnemyDamage(Enemy* enemy)
{
	int baseDamage = m_weaponUsed->getDamage();
	EType weaponType = m_weaponUsed->getType();
	EType enemyType = enemy->getType();
	if (weaponType == enemyType)
	{
		return 0;
	}
	if (weaponType == EType::Shadow)
	{
		if (enemyType == EType::Earth) { return baseDamage * 2;}
		if (enemyType == EType::Light) { return baseDamage / 2;}
		return baseDamage;
	}

	if (weaponType == EType::Light)
	{
		if (enemyType == EType::Shadow) { return baseDamage * 2; }
		if (enemyType == EType::Water) { return baseDamage / 2; }
		return baseDamage;
	}

	if (weaponType == EType::Water)
	{
		if (enemyType == EType::Earth) { return baseDamage / 2; }
		if (enemyType == EType::Light) { return baseDamage * 2; }
		return baseDamage;
	}

	if (weaponType == EType::Earth)
	{
		if (enemyType == EType::Water) { return baseDamage * 2; }
		if (enemyType == EType::Shadow) { return baseDamage / 2; }
		return baseDamage;
	}
	return baseDamage;
}

int Projectile::calculateBossDamage(Boss* boss)
{
	int baseDamage = m_weaponUsed->getDamage();
	EType weaponType = m_weaponUsed->getType();
	EType enemyType = boss->getType();
	if (weaponType == enemyType)
	{
		return 0;
	}
	if (weaponType == EType::Shadow)
	{
		if (enemyType == EType::Earth) { return baseDamage * 2; }
		if (enemyType == EType::Light) { return baseDamage / 2; }
		return baseDamage;
	}

	if (weaponType == EType::Light)
	{
		if (enemyType == EType::Shadow) { return baseDamage * 2; }
		if (enemyType == EType::Water) { return baseDamage / 2; }
		return baseDamage;
	}

	if (weaponType == EType::Water)
	{
		if (enemyType == EType::Earth) { return baseDamage / 2; }
		if (enemyType == EType::Light) { return baseDamage * 2; }
		return baseDamage;
	}

	if (weaponType == EType::Earth)
	{
		if (enemyType == EType::Water) { return baseDamage * 2; }
		if (enemyType == EType::Shadow) { return baseDamage / 2; }
		return baseDamage;
	}
	return baseDamage;
}

void Projectile::collisionDetect()
{
	Room* currentRoom = m_weaponUsed->getOwner()->getRoom();
	if (m_team == ETeam::Player)
	{
		TArray<Enemy*>* enemies = currentRoom->getEnemies();
		for (int i = 0; i < enemies->num(); i++)
		{
			if (m_position.distance(*enemies->getElement(i)->getPosition()) <= 1)
			{
				int damage = calculateEnemyDamage(enemies->getElement(i));
				enemies->getElement(i)->hitCharacter(damage);
 				m_toDie = true;
				break;
			}
		}

		if (m_position.distance(*currentRoom->getBoss()->getPosition()) <= 1 && !currentRoom->getBoss()->isDead)
		{
			int damage = calculateBossDamage(currentRoom->getBoss());
			currentRoom->getBoss()->hitCharacter(damage);
			m_toDie = true;
			
		}

	}
	else
	{
		Player* player = currentRoom->getPlayer();
		if (m_position == *player->getPosition() || m_position == *player->getPosition() + UP_U_VEC || m_position == *player->getPosition() + DOWN_U_VEC)
		{
			int damage = m_weaponUsed->getDamage();
			player->hitCharacter(damage);
		}
	}
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
