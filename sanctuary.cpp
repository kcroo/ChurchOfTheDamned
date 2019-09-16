/***************************************************************************************************
Program name: Final Project
File: Sanctuary.cpp
Author: Kirsten Corrao
Date: 03/04/2019
Description: this is the implementation file of the Sanctuary class. It is a derived class of 
Room. The sanctuary contains Dark Priests as enemies.
***************************************************************************************************/
#include "sanctuary.hpp"


/************************************ constructor ****************************************************
The constructor calls the Room constructor. It creates Treasure and enemies to fight.
*****************************************************************************************************/
Sanctuary::Sanctuary()
	: Room(9, 14, "Sanctuary")
{
	const int monst1Row{ 6 };
	const int monst1Col{ 8 };

	const int monst2Row{ 2 };
	const int monst2Col{ 11 };

	// make door and stairs
	room[8][8].setToDoor(true);			// door to outside (but is locked and can't leave)
	room[0][3].setToStairs();			// to mezzanine
	room[0][12].setToDoor(true);		// door LOCKED to gallery

	// put hero in front of door 
	heroRow = 7;
	heroCol = 8;
	room[heroRow][heroCol].setToHero();

	// create monsters and give them extra items
	room[monst1Row][monst1Col].setToMonster(std::make_unique<DarkPriest>());
	room[monst1Row][monst1Col].getMonster()->addItem(std::make_unique<Treasure>("Sacramental Bread", 0, 0, 8, 0, Type::bread));
	
	room[monst2Row][monst2Col].setToMonster(std::make_unique<DarkPriest>());
	room[monst2Row][monst2Col].getMonster()->addItem(std::make_unique<Treasure>("Sacramental Wine", 0, 0, 0, 4, Type::wine));

	// create treasure
	room[6][10].setToTreasure("Leather Armor", 0, 8, 0, 0, Type::armor);
	room[7][2].setToTreasure("Sacramental Bread", 0, 0, 10, 0, Type::bread);
}

/************************************ destructor *****************************************************
Room base  class deletes monsters and treasure
*****************************************************************************************************/
Sanctuary::~Sanctuary()
{
	/*delete monster3;
	monster3 = nullptr;
	delete monster4;
	monster4 = nullptr;
	delete monster5;
	monster5 = nullptr;
	delete monster6;
	monster6 = nullptr;*/
}

/************************************ setRoomConnections ********************************************
This function sets all of the doors/stairs to the rooms they lead to.
*****************************************************************************************************/
void Sanctuary::setRoomConnections(Room* room1, Room* room2)
{
	above = room1;
	north = room2;
}

/************************************ printRoomContents **********************************************
This function prints that the Sanctuary contains 2 Dark Priests, 1 Treasure, and 2 staircases (1 up 
and 1 down).
*****************************************************************************************************/
void Sanctuary::printContents()
{
	std::cout << "\nThe church SANCTUARY reeks of decay. Tapestries rot on the walls,"
		<< "\nand the pews have disintegrated into lumpy piles of wood."
		<< "\nTwo DARK PRIESTS (P) stand motionless at the altar, as if in prayer."
		<< "\nTheir low chanting fills the SANCTUARY with an evil presence."
		<< "\nOne TREASURE box (T) is nestled amongst the rotting pews."
		<< "\nThe DOOR (d) behind you leads outside of the church, but it appears to be locked by"
		<< "\nthe dark powers abiding within."
		<< "\nThe left STAIRCASE (s) in the left corner leads up to the MEZZANINE."
		<< "\nThe right door (d) is closed and conceals the church's mysteries behind it . . .\n";
}

/************************************ moveNewRoom **********************************************
This function moves the hero to another room when they reach a door or stairs.
Parameters: 1 Character pointer (hero), int for current row, int for current column
*****************************************************************************************************/
Room* Sanctuary::moveNewRoom(int row, int col)
{
	// go to mezzanine
	if (row == 0 && col == 3)
	{
		above->setHeroRowCol(8, 3);
		return above;
	}
	
	// go to gallery
	else
	{
		north->setHeroRowCol(3, 10);
		return north;
	}
}

/************************************ fillRoomMonsters **********************************************
This function fills the room with new monsters. It overrides the Room base class function. It makes 
4 new monsters and puts them in front of doors/stairs, so the hero must fight at least two of them.
It also sets bellRung to false, so that the sanctuary doesn't fill again with monsters later if the 
hero leaves and returns to the sanctuary.
Parameters: none
Returns: void
*****************************************************************************************************/
void Sanctuary::fillRoomMonsters()
{
	// create monsters and give them extra items
	room[1][12].setToMonster(std::make_unique<DarkPriest>());
	room[1][12].getMonster()->addItem(std::make_unique<Treasure>("Chain Mail", 0, 11, 0, 0, Type::armor));

	room[1][2].setToMonster(std::make_unique<Phantom>());
	room[1][2].getMonster()->addItem(std::make_unique<Treasure>("Sacramental Bread", 0, 0, 4, 0, Type::bread));

	room[2][3].setToMonster(std::make_unique<ChoirBoy>());
	room[2][3].getMonster()->addItem(std::make_unique<Treasure>("Sacramental Wine", 0, 0, 0, 6, Type::wine));

	room[1][4].setToMonster(std::make_unique<Ghoul>());
	room[1][4].getMonster()->addItem(std::make_unique<Treasure>("Bastard Sword", 10, 0, 0, 0, Type::weapon));
	room[1][4].getMonster()->addItem(std::make_unique<Treasure>("Sacramental Bread", 0, 0, 8, 0, Type::bread));
}