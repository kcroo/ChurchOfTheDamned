/***************************************************************************************************
Program name: Final Project
File: Gallery.cpp
Author: Kirsten Corrao
Date: 03/04/2019
Description: this is the implementation file of the Gallery class. It is a derived class of 
Room. The gallery contains Ghosts as enemies.
***************************************************************************************************/
#include "gallery.hpp"

/************************************ constructor ****************************************************
The constructor calls the Room constructor to make the room, then creates Treasure and monsters.
*****************************************************************************************************/
Gallery::Gallery()
	: Room(5, 12, "Gallery")
{
	const int monst1Row{ 3 };
	const int monst1Col{ 9 };
	const int monst2Row{ 3 };
	const int monst2Col{ 3 };

	const int treas1Row{ 2 };
	const int treas1Col{ 8 };
	const int treas2Row{ 3 };
	const int treas2Col{ 8 };

	// make stairs and doors
	room[0][1].setToStairs();			// down to dungeon
	room[4][10].setToDoor();			// to sanctuary (unlocked)

	// put hero in front of door 
	room[3][10].setToHero();
	heroRow = 3;
	heroCol = 10;

	// create monsters
	room[monst1Row][monst1Col].setToMonster(std::make_unique<Phantom>());
	room[monst1Row][monst1Col].getMonster()->addItem(std::make_unique<Treasure>("Bastard Sword", 11, 0, 0, Type::weapon));

	room[monst2Row][monst2Col].setToMonster(std::make_unique<Phantom>());
	room[monst2Row][monst2Col].getMonster()->addItem(std::make_unique<Treasure>("Sacramental Bread", 0, 0, 4, Type::bread));

	// create treasure and move to appropriate tile
	room[treas1Row][treas1Col].setToTreasure("Sacramental Bread", 0, 0, 6, Type::bread);
	room[treas2Row][treas2Col].setToTreasure("Sacramental Bread", 0, 0, 8, Type::bread);
}

/************************************ deconstructor *************************************************
*****************************************************************************************************/
Gallery::~Gallery()
{
}

/************************************ setRoomConnections ********************************************
This function sets all of the doors/stairs to the rooms they lead to.
*****************************************************************************************************/
void Gallery::setRoomConnections(Room* room1, Room* room2)
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
Room* Gallery::moveNewRoom(int row, int col)
{
	// to sanctuary 
	if (row == 4 && col == 10)
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