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
	MoveCursorTo(2, 25);
	SetTextColour(PROD225Colours::YELLOW, PROD225Colours::BLACK);
	std::cout << "Health: ";
	for (int i = 0; i < player->getHealth(); i++)
	{
		std::cout << char(219);
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

int main()
{

	srand((int)time(0));

	Player player;
	player.setPosition(10, 10);

	Room* room = new Room;

	//TArray<Enemy*> enemies;
	//
	//for (int i = 0; i < 5; i++)
	//{
	//	Enemy* testEnemy = new (Enemy);
	//	testEnemy->SetPosition(rand() % 118 + 1, rand() % 28 + 1);
	//	enemies.addElement(testEnemy);
	//}
	char keyPressed = '\0';

	// Input keypress and check its not q
	while (keyPressed = _getch(), toupper(keyPressed) != 'Q')
	{
		ClearScreen();
		PrintUI(&player);
		room->tick();
		keyPressed = toupper(keyPressed);
		player.tick(keyPressed);
		MoveCursorTo(49, 29);
		SetTextColour(PROD225Colours::BLACK, PROD225Colours::WHITE);
		std::cout << " The key pressed was " << keyPressed << " ";
		MoveCursorTo(119, 29);
	}

}