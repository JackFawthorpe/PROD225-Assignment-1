#ifndef __PROJECTILE_H__
#define __PROJECTILE_H__

#include "tvector2d.h"
#include "prod225cursorwrapper.h"

#include "actor.h"
#include "weapon.h"

class Weapon;

class Projectile : public Actor
{
public:
	Projectile(Weapon* weaponUsed);
	~Projectile();
	virtual void tick() override;
	virtual void collisionDetect();
	virtual void move();
	virtual void draw();

protected:
	Weapon* m_weaponUsed;
	uint8_t m_velocity;
	uint8_t m_stepsLeft;
	Vector2D<int> m_position;
	EAttackDirection m_direction;
	PROD225Colours* m_colour;
};

#endif /*__PROJECTILE_H__*/