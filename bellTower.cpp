/***************************************************************************************************
Program name: Final Project
File: bellTower.cpp
Author: Kirsten Corrao
Date: 03/04/2019
Description: this is the implementation file of the BellTower class. It is a derived class of 
Room. The bell tower contains a Dark Priest as an enemy.
***************************************************************************************************/
#include "bellTower.hpp"

/************************************ constructor ****************************************************
The constructor calls the Room constructor. It initializes roomRows to 12, roomCols to 22, and room
name to Bell Tower. It then creates the border of * around the room.
*****************************************************************************************************/
BellTower::BellTower()
	: Room(5, 5, "Bell Tower")
{
	// make stairs
	room[2][2].setToStairs();			// to mezzanine

	// put hero in front of door 
	heroRow = 3;
	heroCol = 2;
	room[heroRow][heroCol].setToHero();

	// set bell 
	room[1][1].setToBell();

	// create treasure and move to appropriate tile
	room[3][3].setToTreasure("Key", 0, 0, 0, 0, Type::key);
}

/************************************ destructor *****************************************************
Room base class deletes monsters and treasure
*****************************************************************************************************/
BellTower::~BellTower()
{
}

/************************************ setRoomConnections ********************************************
This function sets all of the doors/stairs to the rooms they lead to.
*****************************************************************************************************/
void BellTower::setRoomConnections(Room* room1, Room* room2)
{
	below = room1;
}

/************************************ printContents **********************************************
This function prints that the Sanctuary contains 2 Dark Priests, 1 Treasure, and 2 staircases (1 up
and 1 down).
*****************************************************************************************************/
void BellTower::printContents()
{
	std::cout << "\nAfter the gloom inside the church, the sunlight in the BELL TOWER is shocking."
		<< "\nThe stairs back down to the GALLERY are the only way out of the BELL TOWER.\n"
		<< "\nA ROPE hangs from the bell . . . would ringing the bell bring in help from the village?";
}

/************************************ moveNewRoom ****************************************************
This function moves the hero to another room when they reach a door or stairs. In the Bell Tower, 
the stairs lead back down to the mezzanine.
Parameters: 1 Character pointer (hero), int for current row, int for current column
*****************************************************************************************************/
Room* BellTower::moveNewRoom(int row, int col)
{
	below->setHeroRowCol(1, 3);
	return below;
}