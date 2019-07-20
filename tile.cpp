/***************************************************************************************************
Program name: Final Project
File: Tile.cpp
Author: Kirsten Corrao
Date: 03/04/2019
Description: this is the implementation file for the Tile class. This class composes the 2D array 
for each room. Each tile can contain the hero; a pointer to a monster; a pointer to a treasure; stairs
to another room; door to another room; or in the bell tower, a bell.
***************************************************************************************************/

#include <assert.h>
#include "tile.hpp"

/*********************************** constructor ****************************************************
Sets all member variables to null or empty. 
*****************************************************************************************************/
Tile::Tile()
	: symbol{ ' ' }, empty{ true },
	isStairsOrDoor{ false }, isLocked{ false }, treasure{ nullptr }
	//monster{ nullptr }
{
}

/************************************ destructor *****************************************************
*****************************************************************************************************/
Tile::~Tile()
{
}

/************************************ setToHero *****************************************************
This function sets the Tile object's attributes to the hero. This includes the hero pointer and the 
character (H).
*****************************************************************************************************/
void Tile::setToHero()
{
	symbol = 'H';
	empty = false;
}

/************************************ setToMonster ***************************************************
This function sets the Tile object's attributes to a monster. This includes the monster pointer and the
appropriate character. (Ex: P for dark priest)
*****************************************************************************************************/
void Tile::setToMonster(std::unique_ptr<Character> m)
{
	monster = std::move(m);
	symbol = monster->getSymbol();
	empty = false;
}

/************************************ setToTreasure ***************************************************
This function sets the Tile object's attributes to a treasure. The tile now "owns" that treasure, and it 
can be transferred to the player's inventory.
*****************************************************************************************************/
void Tile::setToTreasure(std::string name, int att, int def, int hp, Type t)
{
	treasure = std::make_unique<Treasure>(name, att, def, hp, t);
	symbol = 'T';
	empty = false;
}

/************************************ setToEmpty ******************************************************
This function sets the Tile object's attributes to an empty tile. It can be used after a space becomes 
empty from the hero moving; a monster being defeated; or treasure being taken.
*****************************************************************************************************/
void Tile::setToEmpty()
{
	// do nothing if stairs or door
	if (!isStairsOrDoor)
	{
		//monster = nullptr;
		treasure = nullptr;
		symbol = ' ';
		empty = true;
	}
	
}

/************************************ setToStairs ******************************************************
This function sets the Tile object's attributes to stairs. It sets the character to s and the Space 
stairs pointer to the room the stairs go to.
*****************************************************************************************************/
void Tile::setToStairs()
{
	symbol = 's';
	empty = false;
	isStairsOrDoor = true;
}

/************************************ setToDoor ******************************************************
This function sets the Tile object's attributes to stairs. It sets the character to s and the Space
stairs pointer to the room the stairs go to.
*****************************************************************************************************/
void Tile::setToDoor(bool locked)
{
	symbol = 'd';
	empty = false;
	isStairsOrDoor = true;
	isLocked = locked;
}

/************************************ setToBell ******************************************************
This function sets the Tile object's attributes to a bell (used in the bell tower).
*****************************************************************************************************/
void Tile::setToBell()
{
	symbol = 'B';
	empty = false;
}

///************************************ removeMonster ***************************************************
//This function deletes the monster and sets the pointer to null. This should be used after the hero defeats
//a monster. 
//*****************************************************************************************************/
//void Tile::removeMonster()
//{
//	delete monster;
//	monster = nullptr;
//}
//
///************************************ removeTreasure ***************************************************
//This sets the treasure pointer to null. The room is responsible for deleting the object.
//*****************************************************************************************************/
//void Tile::removeTreasure()
//{
//	treasure = nullptr;
//}

///************************************ getters & setters **********************************************/
//
// monster
Character* Tile::getMonster()
{
	return monster.get();
}

//void Tile::setMonster(Character* m)
//{
//	monster = m;
//}

// treasure
Treasure* Tile::getTreasure()
{
	return treasure.get();
}

std::unique_ptr<Treasure> Tile::moveTreasure()
{
	return std::move(treasure);
}

//void Tile::setTreasure(Treasure* t)
//{
//	treasure = t;
//}

// symbol
char Tile::getSymbol()
{
	return symbol;
}

void Tile::setSymbol(char c)
{
	symbol = c;
}

// empty
void Tile::setEmpty(bool isEmpty)
{
	empty = isEmpty;
}

bool Tile::getEmpty()
{
	return empty;
}

// is stairs or door
void Tile::setIsStairsOrDoor(bool isSD)
{
	isStairsOrDoor = isSD;
}

bool Tile::getIsStairsOrDoor()
{
	return isStairsOrDoor;
}

// isUnlocked
void Tile::setIsLocked(bool locked)
{
	isLocked = locked;
}

bool Tile::getIsLocked()
{
	return isLocked;
}