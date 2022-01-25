#ifndef __DOOR_H__
#define __DOOR_H__

#include "room.h"
#include "tvector2d.h"
#include "wall.h"

class Room;

class Door
{
public:
	Door(Room* startRoom);
	~Door();

	void draw() const;

private:
	Room* m_firstRoom;
	Room* m_secondRoom;
	Vector2D<int> m_firstPosition;
	Vector2D<int> m_secondPosition;
};

#endif /*__DOOR_H__*/