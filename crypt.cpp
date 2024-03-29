/***************************************************************************************************
Program name: Final Project
File: Crypt.cpp
Author: Kirsten Corrao
Date: 03/04/2019
Description: this is the implementation file of the Crypt class. It is a derived class of 
Room. The crypt contains the Lich Cardinal, who is the final boss of the game. The game ends if the 
hero defeats the Lich Cardinal (or dies).
***************************************************************************************************/
#include "crypt.hpp"

/************************************ constructor ****************************************************
The constructor calls the Room constructor to make the room, then creates Treasure and monsters.
*****************************************************************************************************/
Crypt::Crypt()
	: Room(10, 8, "Crypt")
{
	const int monst1Row{ 5 };
	const int monst1Col{ 5 };

	// make stairs and doors
	room[0][1].setToStairs();			// up to dungeon

	// put hero in front of door 
	heroRow = 1;
	heroCol = 1;
	room[heroRow][heroCol].setToHero();

	// create monsters
	room[monst1Row][monst1Col].setToMonster(std::make_unique<Lich>());

	// create treasure and move to appropriate tile
	room[4][6].setToTreasure("Sacramental Bread", 0, 0, 10, 0, Type::bread);
	
	room[2][1].setToTreasure("Sacramental Wine", 0, 0, 0, 6, Type::wine);
}

/************************************ destructor *****************************************************
*****************************************************************************************************/
Crypt::~Crypt()
{
}

/************************************ setRoomConnections ********************************************
This function sets all of the doors/stairs to the rooms they lead to.
*****************************************************************************************************/
void Crypt::setRoomConnections(Room* room1, Room* room2)
{
	above = room1;
}

/************************************ printRoomContents **********************************************
This function prints the contents of the room.
*****************************************************************************************************/
void Crypt::printContents()
{
	std::cout << "\nAll is darkness in the CRYPT. The stagnant air is filled with the stench of decay."
		<< "\nYou realize that you didn't remember to bring a torch, but then lone flame appears,"
		<< "\nhovering above a transparent hand. With horror, you take in the stone coffin, the "
		<< "\nspiders scurrying away from the apparation, and the lone figure's towering papal cap."
		<< "\nThis is it. This is the LICH CARDINAL, whose evil prayers have gifted him life immortal."
		<< "\nYou suspect he has used his unnaturally long life to perfect his dark incantations."
		<< "\nAlthough every instinct tells you to turn back, you know your quest will not be complete"
		<< "\nuntil you defeat the LICH CARDINAL. Be sure to take the treasure and equip your best"
		<< "\nweapons and armor. You're going to need them.\n";
}

/************************************ moveNewRoom **********************************************
This function moves the hero to another room when they reach a door or stairs.
Parameters: 1 Character pointer (hero), int for current row, int for current column
*****************************************************************************************************/
Room* Crypt::moveNewRoom(int row, int col)
{
	above->setHeroRowCol(6, 6);
	return above;
}
