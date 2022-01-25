#ifndef __PLAYER_H__
#define __PLAYER_H__

#include "character.h"

#define LEFT_KEY 65
#define RIGHT_KEY 68
#define UP_KEY 87
#define DOWN_KEY 83
#define SPACE_BAR 32

class Player : public Character
{
public:
	Player();
	~Player();


	virtual void tick(char& keyPressed);
	virtual	void evaluateKeyPress(char& direction);
	virtual void draw() override;
	void openDoor();

};

#endif /*__PLAYER_H__*/