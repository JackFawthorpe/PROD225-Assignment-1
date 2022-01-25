#ifndef __WEAPON_H__
#define __WEAPON_H__

#include <stdbool.h>

#include "actor.h"
#include "character.h"
#include "prod225cursorwrapper.h"
#include "prod225colour.h"
#include "projectile.h"


class Character;
class Projectile;

class Weapon : public Actor
{
public:

	Weapon();
	Weapon(Character* owner);
	~Weapon();


	virtual void attack();
	virtual void draw();
	virtual void tick();

	virtual void deleteProjectile();

	virtual EAttackDirection getDirection();
	virtual Vector2D<int>* getPosition();
	virtual PROD225Colours* getColour();

	virtual EType getType();

protected:
	bool m_dropped; // Distinguish between a held and dropped weapon
	EType m_type;
	Character* m_owner;
	Vector2D<int> m_position; // Only used when dropped
	PROD225Colours m_colour;
	Projectile* m_currentProjectile;

private:
	void setColour();
};

#endif /*__WEAPON_H__*/