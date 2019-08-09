/***************************************************************************************************
Program name: Final Project
File: Gallery.cpp
Author: Kirsten Corrao
Date: 03/04/2019
Description: this is the implementation file of the Gallery class. It is a derived class of 
Space. The gallery contains Ghosts as enemies.
***************************************************************************************************/
#include "Gallery.hpp"
#include "Character.hpp"
#include "Ghost.hpp"

/************************************ constructor ****************************************************
The constructor calls the Space constructor to make the room, then creates Treasure and monsters.
*****************************************************************************************************/
Gallery::Gallery()
	: Space(5, 12, "Gallery")
{
	// make stairs and doors
	roomArray[0][1].setToStairs();			// down to dungeon
	roomArray[4][10].setToDoor();			// to sanctuary (unlocked)

	// put hero in front of door 
	roomArray[3][10].setToHero();
	heroRow = 3;
	heroCol = 10;

	// create monsters
	monster1 = new Ghost;
	monster2 = new Ghost;

	// set monsters to appropriate tiles
	roomArray[3][9].setToMonster(monster1, 'O');
	roomArray[3][3].setToMonster(monster2, 'O');

	// create treasure and move to appropriate tile
	treasure1 = new Treasure("Holy Water", 0, 0, 6, Type::holyWater);
	roomArray[2][8].setToTreasure(treasure1);
	
	treasure2 = new Treasure("Holy Water", 0, 0, 8, Type::holyWater);
	roomArray[2][8].setToTreasure(treasure1);
	
	// initialize inventories and add extra items
	Inventory* monster1Inv{ monster1->getInventory() };
	monster1Inv->add(new Treasure("Bastard Sword", 11, 0, 0, Type::weapon));
}

/************************************ deconstructor *************************************************
*****************************************************************************************************/
Gallery::~Gallery()
{
}

/************************************ setRoomConnections ********************************************
This function sets all of the doors/stairs to the rooms they lead to.
*****************************************************************************************************/
void Gallery::setRoomConnections(Space* room1, Space* room2)
{
	south = room1;
	below = room2;
}

/************************************ printContents **********************************************
Prints the room's contents.
*****************************************************************************************************/
void Gallery::printContents()
{
	std::cout << "\nOnce, the GALLERY would have been full of art celebrating the life and resurrection"
		<< "\nof Jesus Christ. Now, it is a testimony to the perversion and rot that has taken over"
		<< "\nthe church. The walls are lined with grotesque \"art\": rotting limbs of previous"
		<< "\nvictims, sculptures comprised of bone and skin, paintings of dark deeds that you"
		<< "\nlook away from in disgust. Rising out of the sculptures are two CORRUPTED GHOSTS,"
		<< "\nbut what were once their eyes glow with malice. Whoever they once were, they are"
		<< "\nservants of the LICH CARDINAL now.\n";
}

/************************************ moveNewRoom **********************************************
This function moves the hero to another room when they reach a door or stairs. In the Bell Tower,
the stairs lead back down to the mezzanine.
Parameters: 1 Character pointer (hero), int for current row, int for current column
*****************************************************************************************************/
Space* Gallery::moveNewRoom(int row, int col)
{
	// to sanctuary 
	if (row == 4 && col == 12)
	{
		south->setHeroRowCol(1, 12);
		return south;
	}
	// to dungeon 
	else
	{
		below->setHeroRowCol(1, 1);
		return below;
	}
}