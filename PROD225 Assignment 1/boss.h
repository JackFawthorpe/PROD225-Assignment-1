#ifndef __BOSS_H__
#define __BOSS_H__

#include "character.h"

/*  Originally this was meant to be part of Enemy, however after
*	losing alot of time trying to foward declare and attempts to initialise
*	enemy first, I substituted character */

class Boss : public Character
{
public:
	Boss();
	~Boss();

	virtual void tick() override;
	virtual void draw() override;
	virtual void die() override;
	virtual void move();
	virtual void attack() override;
	virtual void setPosition(int x, int y) override;
	bool isDead;
	virtual EType getType();

protected:
	int m_moveTick;
	EType m_type;
	PROD225Colours m_colour;
	bool m_shootFlag;
	Weapon* m_leftWeapon;
	Weapon* m_rightWeapon;
};

#endif /*__BOSS_H__*/