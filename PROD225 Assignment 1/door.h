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
	Vector2D<int> getPosition() const;
	void generateSecondRoom();
	bool isCompleted();
	void swapRoom(Character* character);

private:
	Room* m_firstRoom;
	Room* m_secondRoom;
	Room* m_currentRoom;
	Room* m_offRoom;
	Vector2D<int>* m_currentPosition;
	Vector2D<int>* m_offPosition;
	Vector2D<int> m_firstPosition;
	Vector2D<int> m_secondPosition;
	bool m_completed;
};

#endif /*__DOOR_H__*/