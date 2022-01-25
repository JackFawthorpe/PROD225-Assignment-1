#ifndef __ENEMY_H__
#define __ENEMY_H__


#include "character.h"


class Enemy : public Character
{
public:
	Enemy();
	~Enemy();
	virtual void tick() override;
	virtual void draw() override;
	virtual void move();
	virtual void setPosition(int x, int y) override;
private:
	int m_moveTick;
	EType m_type;
	PROD225Colours m_colour;
};

#endif /*__ENEMY_H__*/