#ifndef __ROOM_H__
#define __ROOM_H__

#include "character.h"
#include "tarray.h"
#include "wall.h"
#include "actor.h"
#include "enemy.h"
#include "door.h"

class Door;
class Enemy;

class Room
{
public:
	Room();
	~Room();
	Room(Door* door);

	void tick();
	void draw() const;

	TArray<Wall*>* getWalls();
	TArray<Door*>* getDoors();
private:
	TArray<Wall*> m_walls;
	TArray<Enemy*> m_enemies;
	TArray<Door*> m_doors;

};

#endif /*__ROOM_H__*/