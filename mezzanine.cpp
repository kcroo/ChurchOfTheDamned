/***************************************************************************************************
Program name: Final Project
File: Sanctuary.cpp
Author: Kirsten Corrao
Date: 03/04/2019
Description: this is the implementation file of the Mezzanine class. It is a derived class of 
Room. The mezzanine contains Zombie Choir Boys as enemies.
***************************************************************************************************/
#include "mezzanine.hpp"

/************************************ constructor ****************************************************
The constructor calls the Room constructor. It creates Treasure and enemies to fight.
*****************************************************************************************************/
Mezzanine::Mezzanine()
	: Room(10, 6, "Mezzanine")
{
	const int monst1Row{ 7 };
	const int monst1Col{ 3 };
	const int monst2Row{ 1 };
	const int monst2Col{ 3 };

	const int treas1Row{ 2 };
	const int treas1Col{ 2 };
	const int treas2Row{ 2 };
	const int treas2Col{ 4 };

	// make stairs
	room[0][3].setToStairs();
	room[9][3].setToStairs();

	// put hero in front of stairs 
	heroRow = 8;
	heroCol = 3;
	room[heroRow][heroCol].setToHero();

	// create monsters and give them extra items
	room[monst1Row][monst1Col].setToMonster(std::make_unique<ChoirBoy>());
	room[monst1Row][monst1Col].getMonster()->addItem(std::make_unique<Treasure>("Sacramental Bread", 0, 0, 6, Type::bread));

	room[monst2Row][monst2Col].setToMonster(std::make_unique<ChoirBoy>());
	room[monst2Row][monst2Col].getMonster()->addItem(std::make_unique<Treasure>("Mace", 6, 0, 0, Type::weapon));

	// create treasure
	room[treas1Row][treas1Col].setToTreasure("Hatchet", 5, 0, 0, Type::weapon);
	room[treas2Row][treas2Col].setToTreasure("Sacramental Bread", 0, 0, 6, Type::bread);
}

/************************************ destructor ****************************************************
*****************************************************************************************************/
Mezzanine::~Mezzanine()
{
}

/************************************ setRoomConnections ********************************************
This function sets all of the doors/stairs to the rooms they lead to.
*****************************************************************************************************/
void Mezzanine::setRoomConnections(Room* room1, Room* room2)
{
	below = room1;
	above = room2;
}

/************************************ printRoomContents **********************************************
This function prints the room's contents.
*****************************************************************************************************/
void Mezzanine::printContents()
{
	std::cout << "\nThe mezzanine would have once been full of beautiful song, as the choir "
		<< "\nsang hymns for the congregation below. Now, its stone benches crumble, and although"
		<< "\nthe sun shone outside, no light penetrates the now filthy stained glass."
		<< "\nYou realize with dread that the glass' images of saints have been replaced by"
		<< "\ndemons and untold horrors. Arising from nowhere, two CHOIR BOYS (C) turn toward you,"
		<< "\nholding hymnals in their rotting hands. They begin chanting in deep, diaboliacal voices,"
		<< "\nand you have no desire to know what they are saying. The south STAIRCASE (s) leads back"
		<< "\ndown to the SANCTUARY, while the north STAIRCASE (s) leads up to the BELL TOWER.";
}

/************************************ moveNewRoom **********************************************
This function moves the hero to another room when they reach a door or stairs.
Parameters: 1 Character pointer (hero), int for current row, int for current column
*****************************************************************************************************/
Room* Mezzanine::moveNewRoom(int row, int col)
{
	// to sanctuary
	if (row == 9 && col == 3)
	{
		below->setHeroRowCol(1, 3);

		return below;
	}
	// to bell tower
	else
	{
		above->setHeroRowCol(3, 2);
		return above;
	}
}