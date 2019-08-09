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
	// make stairs
	room[0][3].setToStairs();
	room[9][3].setToStairs();

	// put hero in front of stairs 
	room[8][3].setToHero();
	heroRow = 8;
	heroCol = 3;

	//// create monsters
	//monster1 = new ChoirBoy;
	//monster2 = new ChoirBoy;
	//room[7][3].setToMonster(monster1, 'C');
	//room[1][3].setToMonster(monster2, 'C');

	//// add extra items to monsters
	//Inventory* monster1Inv{ monster1->getInventory() };
	//monster1Inv->add(new Treasure("Holy Water", 0, 0, 6, Type::holyWater));
	//
	//Inventory* monster2Inv{ monster2->getInventory() };
	//monster2Inv->add(new Treasure("Mace", 6, 0, 0, Type::weapon));
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
		below->setHeroRow(1);
		below->setHeroCol(3);

		return below;
	}
	// to bell tower
	else
	{
		above->setHeroRow(3);
		above->setHeroCol(2);
		return above;
	}
}