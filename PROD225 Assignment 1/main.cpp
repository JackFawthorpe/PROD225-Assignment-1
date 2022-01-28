#include <iostream>
#include <conio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>

#include "tvector2d.h"
#include "tarray.h"
#include "prod225colour.h"
#include "character.h"
#include "player.h"
#include "enemy.h"
#include "room.h"


void ClearScreen()
{
	SetTextColour(PROD225Colours::WHITE, PROD225Colours::BLACK);
	system("cls");
}

std::string TypeToString(EType type)
{
	switch (type)
	{
	case EType::Earth:
		return "Earth";
	case EType::Water:
		return "Water";
	case EType::Light:
		return "Light";
	case EType::None:
		return "None";
	case EType::Shadow:
		return "Shadow";
	case EType::Life:
		return "Life";
	default:
		return "None";
	}
}

void PrintUI(Player* player)
{
	MoveCursorTo(0, 23);
	std::cout << std::string(120, '-');
	for (int i = 24; i < 30; i++)
	{
		MoveCursorTo(40, i);
		std::cout << "|";
		MoveCursorTo(80, i);
		std::cout << "|";
	}
	SetTextColour(PROD225Colours::YELLOW, PROD225Colours::BLACK);
	MoveCursorTo(2, 25);
	std::cout << "Health: ";
	for (int i = 0; i < player->getHealth(); i++)
	{
		std::cout << char(219);
	}
	MoveCursorTo(2, 27);
	std::cout << "Keys: ";

	for (int i = 0; i < player->getKeys(); i++)
	{
		std::cout << char(219) << " ";
	}

	if (player->getKeys() == 0)
	{
		std::cout << "X";
	}

	MoveCursorTo(2, 28);
	std::cout << "Hearts of terror: ";
	for (int i = 0; i < player->getHearts(); i++)
	{
		std::cout << char(219) << char(219) << " ";
	}

	MoveCursorTo(82, 24);
	SetTextColour(PROD225Colours::CYAN, PROD225Colours::BLACK);
	std::cout << "Inventory:";
	MoveCursorTo(98, 25);
	std::cout << "Range     Damage";
	
	for (int i = 0; i < player->getInventory()->num(); i++)
	{
		MoveCursorTo(82, 26 + i);
		Weapon* playerWeapon = (player->getInventory()->getElement(i));
		std::cout << TypeToString(playerWeapon->getType()) << " Shuriken";
	}

}

void gameLost()
{
	ClearScreen();
	MoveCursorTo(0,0);

	for (int i = 0; i < 200; i++)
	{
		SetTextColour(static_cast<PROD225Colours>(rand() % 10), PROD225Colours::BLACK);
		std::cout << "YOU ARE A LOSER ";
	}

	for (int i = 0; i < 5; i++)
	{
		char holdScreen = _getch();
	}
}

void gameWon()
{
	ClearScreen();
	MoveCursorTo(0, 0);
	std::cout << "You win";
	for (int i = 0; i < 5; i++)
	{
		char holdScreen = _getch();
	}
}

int main()
{

	srand((int)time(0));

	Player player;
	player.setPosition(10, 10);

	Room* currentRoom = new Room;
	player.setRoom(currentRoom);
	char keyPressed = '\0';

	while (keyPressed = _getch(), toupper(keyPressed) != 'Q')
	{
		ClearScreen();
		PrintUI(&player);
		keyPressed = toupper(keyPressed);
		player.tick(keyPressed);
		if (player.playerWon)
		{
			gameWon();
			break;
		}
		currentRoom = player.getRoom();
		currentRoom->setPlayer(&player);
		currentRoom->tick();
		if (player.playerDead)
		{
			gameLost();
			break;
		}
		MoveCursorTo(49, 29);
		SetTextColour(PROD225Colours::BLACK, PROD225Colours::WHITE);
		std::cout << " The key pressed was " << keyPressed << " ";
		MoveCursorTo(119, 29);
	}

}