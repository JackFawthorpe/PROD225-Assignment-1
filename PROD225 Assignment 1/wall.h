#ifndef __WALL_H__
#define __WALL_H__

#include "tvector2d.h"
#include "actor.h"

class Wall
{
public:
	Wall(Vector2D<int> first, Vector2D<int> second);
	~Wall();

	void draw() const;
	Vector2D<int> getRandomPositionOnWall();

private:
	Vector2D<int> m_firstCorner;
	Vector2D<int> m_secondCorner;
	bool m_vert;
};

#endif /*__WALL_H__*/