#ifndef __ROOM_H__
#define __ROOM_H__

#include "tarray.h"
#include "actor.h"
#include "character.h"
#include "player.h"
#include "enemy.h"
#include "boss.h"
#include "wall.h"
#include "door.h"

class Door;
class Enemy;
class Player;
class Wall;
class Boss;

class Room
{
public:
	Room();
	~Room();
	Room(Door* door);

	void tick();
	void draw() const;
	virtual void setPlayer(Player* player);
	TArray<Wall*>* getWalls();
	TArray<Door*>* getDoors();
	TArray<Enemy*>* getEnemies();
	Player* getPlayer();
	PROD225Colours getColour();
	Boss* getBoss();


private:
	TArray<Wall*> m_walls;
	TArray<Enemy*> m_enemies;
	TArray<Door*> m_doors;
	Player* m_player;
	PROD225Colours m_colour;
	Boss* m_roomBoss;

};

#endif /*__ROOM_H__*/