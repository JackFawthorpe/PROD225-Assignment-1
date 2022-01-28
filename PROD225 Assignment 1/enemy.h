#ifndef __ENEMY_H__
#define __ENEMY_H__


#include "character.h"

class Character;

class Enemy : public Character
{
public:
	Enemy();
	~Enemy();
	virtual void tick() override;
	virtual void draw() override;
	virtual void move();
	virtual void setPosition(int x, int y) override;
	virtual void hitCharacter(int& damage) override;
	virtual void die() override;
	virtual void giveKey();
	virtual bool hasKey();
	virtual EType getType();

protected:
	int m_moveTick;
	EType m_type;
	PROD225Colours m_colour;
	bool m_shootFlag;
	bool m_holdKey;
};



#endif /*__ENEMY_H__*/