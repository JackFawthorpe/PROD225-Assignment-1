#ifndef __CHARACTER_H__
#define __CHARACTER_H__

#include "tvector2d.h"
#include "tarray.h"
#include "prod225cursorwrapper.h"
#include "actor.h"
#include "weapon.h"

class Weapon;
class Room;

class Character : private Actor
{
public:

	Character();
	~Character();

	virtual void draw();
	virtual void move(EDirection direction);
	virtual void attack();


	virtual void setPosition(int x, int y);

	virtual Vector2D<int>* getPosition();
	virtual EAttackDirection* getDirection();
	virtual Vector2D<int>* getHandPosition();
	virtual int getHealth() const;
	virtual TArray<Weapon*>* getInventory();
	virtual void setRoom(Room* currentRoom);
	virtual Room* getRoom() const;

protected:
	Vector2D<int> m_leftHand;
	Vector2D<int> m_rightHand;
	Vector2D<int> m_position;
	Vector2D<int>* m_currentHand;
	TArray<Weapon*> m_weaponInventory;
	Weapon* m_currentWeapon;
	EAttackDirection m_weaponDirection;
	int m_health;
	Room* m_currentRoom;
};


/*	The reason this is down here is because it was calling
*	room to be defined which called Enemy to be defined which
*	needed Character to be defined and I tried forward declarating
*	and It didnt work so I succumbed to a bad practice for a simple
*	solution, my guilt is immense and this day of coding is ruined */
#include "room.h"

#endif /*__CHARACTER_H__*/