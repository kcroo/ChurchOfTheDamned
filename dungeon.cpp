/***************************************************************************************************
Program name: Final Project
File: Dungeon.cpp
Author: Kirsten Corrao
Date: 03/04/2019
Description: this is the implementation file of the Dungeon class. It is a derived class of 
Room. The dungeon contains Ghoul Tormentors as enemies.
***************************************************************************************************/
#include "dungeon.hpp"
#include "character.hpp"
//#include "GhoulTormenter.hpp"

/************************************ constructor ****************************************************
The constructor calls the Room constructor to make the room, then creates Treasure and monsters.
*****************************************************************************************************/
Dungeon::Dungeon()
	: Room(8, 8, "Dungeon")
{
	// make stairs and doors
	room[7][6].setToStairs();			// to crypt
	room[0][1].setToStairs();			// to gallery

	// put hero in front of door 
	heroRow = 1;
	heroCol = 1;
	room[heroRow][heroCol].setToHero();

	// create monsters
	//monster1 = new GhoulTormenter;
	//monster2 = new GhoulTormenter;

	//// set monsters to appropriate tiles
	//room[1][2].setToMonster(monster1, 'G');
	//room[2][1].setToMonster(monster2, 'G');

	// create treasure and move to appropriate tile
	room[4][6].setToTreasure("Holy Water", 0, 0, 5, Type::holyWater);
	
	room[5][6].setToTreasure("Partial Plate", 0, 12, 0, Type::armor);
	
	//// initialize inventories and add extra items
	//Inventory* monster1Inv{ monster1->getInventory() };
	//monster1Inv->add(new Treasure("Holy Water", 0, 0, 10, Type::holyWater));
	//
	//Inventory* monster2Inv{ monster2->getInventory() };
	//monster2Inv->add(new Treasure("Long Sword", 10, 0, 0, Type::weapon));
}

/************************************ deconstructor *************************************************
*****************************************************************************************************/
Dungeon::~Dungeon()
{
}

/************************************ setRoomConnections ********************************************
This function sets all of the doors/stairs to the rooms they lead to.
*****************************************************************************************************/
void Dungeon::setRoomConnections(Room* room1, Room* room2)
{
	above = room1;
	below = room2;
}

/************************************ printContents **********************************************
Prints the room's contents.
*****************************************************************************************************/
void Dungeon::printContents()
{
	std::cout << "\nThe DUNGEON is dark, except for the single beam of light entering through the stairway"
		<< "\nto the gallery. Cages line one wall, each of them holding a crumbling set of bones."
		<< "\nSomething tells you they were once people from your village. Tables line the other side,"
		<< "\nof the room, covered with shackles, chains, and dried blood. Various devices of torture"
		<< "\nline the wall. You mourn what must have happened here. Out of thin air, two GHOUL TORMENTERS appear"
		<< "\nin front of you, their ghastly grins a testament to the horrific acts they inflicted on"
		<< "\npeople in the DUNGEON. You know in your soul that if you can defeat them, you will be"
		<< "\nvery close to facing the ULTIMATE EVIL that invaded this church.\n";
}

/************************************ moveNewRoom **********************************************
This function moves the hero to another room when they reach a door or stairs. 
Parameters: 1 Character pointer (hero), int for current row, int for current column
*****************************************************************************************************/
Room* Dungeon::moveNewRoom(int row, int col)
{
	// to gallery 
	if (row == 0 && col == 1)
	{
		above->setHeroRowCol(1, 1);
		return above;
	}
	// to crypt 
	else
	{
		below->setHeroRowCol(1, 1);
		return below;
	}
}