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
	room[3][3].setToTreasure("Key", 0, 0, 0, Type::key);
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

/************************************ moveCharacter ****************************************************
This function overrides the Room moveCharacter function. It adds functionality for ringing the bell 
in the bell tower. If the player rings it, it sets bellRung to true. When the player goes back down 
to the sanctuary, it will be full of monsters.
Parameters: 1 Character pointer by reference, 1 char for direction, and 1 Room pointer by reference
Returns: integer
*****************************************************************************************************/
int BellTower::moveCharacter(std::unique_ptr<Character>& c, char direction, Room*& currentRoom)
{
	int newRow{ heroRow };
	int newCol{ heroCol };

	switch (direction)
	{
	case 'w':		// north
	{
		newRow--;
		break;
	}
	case 'd':		// east
	{
		newCol++;
		break;
	}
	case 's':		// south
	{
		newRow++;
		break;
	}
	case 'a':		// west
	{
		newCol--;
		break;
	}
	}

	// if tile is empty, move there 
	if (room[newRow][newCol].getEmpty())
	{
		room[newRow][newCol].setToHero();

		// if hero is leaving tile with no treasure, set to empty
		if (room[heroRow][heroCol].getTreasure() == nullptr)
		{
			room[heroRow][heroCol].setToEmpty();
		}
		// if hero is leaving tile with treasure they didn't take, set symbol to T and hero ptr to null
		else
		{
			room[heroRow][heroCol].setSymbol('T');
		}

		heroRow = newRow;
		heroCol = newCol;
		return 1;
	}
	// if tile has monster, fight monster
	else if (room[newRow][newCol].getMonster() != nullptr)
	{
		room[newRow][newCol].setToHero();
		room[heroRow][heroCol].setToEmpty();
		heroRow = newRow;
		heroCol = newCol;

		return 2;
	}
	// if tile has treasure, pick up treasure
	else if (room[newRow][newCol].getTreasure() != nullptr)
	{
		room[newRow][newCol].setToHero();
		room[heroRow][heroCol].setToEmpty();
		heroRow = newRow;
		heroCol = newCol;

		return 3;
	}
	// if door is locked
	else if (room[newRow][newCol].getIsStairsOrDoor() == true && room[newRow][newCol].getIsLocked() == true)
	{
		return 4;
	}
	// if stairs/door and unlocked, go to new room
	else if (room[newRow][newCol].getIsStairsOrDoor() == true)
	{
		room[heroRow][heroCol].setToEmpty();
		heroRow = newRow;
		heroCol = newCol;
		return 5;
	}

	// if hero rings bell, sanctuary fills with monsters
	else if (room[newRow][newCol].getSymbol() == 'B')
	{
		int choice{ utility::getInt("\nRing the BELL? \n1. Yes \n2. No \n", 1, 2) };
		if (choice == 1)
		{
			std::cout << "\nThe ringing of the BELL is louder than you predicted."
				<< "\nAs its peals slowly fade, you hear an EVIL CACKLE below . . . ";

			bellRung = true;
		}

		return 1;		// does nothing in Game
	}

	// invalid move
	else
	{
		return 6;
	}
}

/************************************ getters / setters ***********************************************
*****************************************************************************************************/
bool BellTower::getBellRung()
{
	return bellRung;
}