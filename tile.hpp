/***************************************************************************************************
Program name: Final Project
File: Tile.hpp
Author: Kirsten Corrao
Date: 03/04/2019
Description: this is the header file for the Tile class. This class composes the 2D array 
for each room. Each tile can contain the hero; a pointer to a monster; a pointer to a treasure; stairs
to another room; door to another room; or in the bell tower, a bell.
***************************************************************************************************/
#ifndef TILE_HPP
#define TILE_HPP

#include "character.hpp"
#include "treasure.hpp"

#include <memory>

class Tile
{
private:
	//Character* monster;

	char symbol;
	bool empty;
	bool isStairsOrDoor;							// used to see if hero goes to other room
	bool isLocked;									// used to see if hero can open door
	std::unique_ptr<Treasure> treasure;

public:
	Tile();
	~Tile();
	char test;
	void setToHero();
	//void setToMonster(Character* monst, char c);
	void setToTreasure(std::string name, int att, int def, int hp, Type t);
	void setToEmpty();			
	void setToStairs();
	void setToDoor(bool locked = false);			// doors default to unlocked
	void setToBell();
	//void removeMonster();							// sets monster ptr to null
	void removeTreasure();							// sets treasure ptr to null

	// getters and setters
	// Character* getMonster();
	// void setMonster(Character* m);
	Treasure* getTreasure();
	std::unique_ptr<Treasure> moveTreasure();
	void setTreasure(std::unique_ptr<Treasure> t);

	char getSymbol();
	void setSymbol(char c);
	void setEmpty(bool isEmpty);
	bool getEmpty();
	void setIsStairsOrDoor(bool isSD);
	bool getIsStairsOrDoor();
	void setIsLocked(bool locked);
	bool getIsLocked();
};

#endif 
