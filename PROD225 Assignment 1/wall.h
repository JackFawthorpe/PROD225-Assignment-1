#ifndef __WALL_H__
#define __WALL_H__

#include "tvector2d.h"
#include "actor.h"
#include "room.h"

class Room;

class Wall
{
public:
	Wall(Vector2D<int> first, Vector2D<int> second, Room* room);
	~Wall();

	void draw() const;
	Vector2D<int> getRandomPositionOnWall();

private:
	Vector2D<int> m_firstCorner;
	Vector2D<int> m_secondCorner;
	Room* m_room;
	bool m_vert;
};

#endif /*__WALL_H__*/