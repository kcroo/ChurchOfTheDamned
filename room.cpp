/***************************************************************************************************
Program name: Church of the Damned
File: Room.cpp
Author: Kirsten Corrao
Date: 07/12/2019
***************************************************************************************************/
#include "room.hpp"

/************************************ constructor ****************************************************
The constructor creates a 2D array made of Tile objects, then creates a border around the room.
Parameters: # of rows in room, # of columns in room, string for name of room
*****************************************************************************************************/
Room::Room(int rows, int cols, std::string n)
	: roomRows{ rows }, roomCols{ cols }, name{ n }, heroRow{ -1 }, heroCol{ -1 }, north{ nullptr },
	south{ nullptr }, east{ nullptr }, west{ nullptr }, above{ nullptr }, below{ nullptr }
{
	// create 2D array of Tile objs
	room = new Tile*[roomRows];						// rows 

	for (int i = 0; i < roomRows; i++)
	{
		room[i] = new Tile[roomCols];				// cols
	}

	// make borders around room
	makeBorders(roomRows, roomCols);
}


/************************************ destructor *****************************************************
The destructor releases the memory of the 2D Tile array and deletes any treasure and monsters in room.
*****************************************************************************************************/
Room::~Room()
{
	// delete Tile array
	for (int row = 0; row < roomRows; row++)
	{
		delete[] room[row];
	}

	// delete room
	delete[] room;
	room = nullptr;
}

/************************************ printRoom *****************************************************
This function prints the room. It has asterisks for walls. The hero is represented by H. Monsters 
are represented by different characters according to their type.
Parameters: none
Returns: void
*****************************************************************************************************/
void Room::printRoom()
{
	std::cout << "\n\n***********************************************************************************************\n";
	std::cout << name << "\n";

	for (int row = 0; row < roomRows; row++)
	{
		for (int col = 0; col < roomCols; col++)
		{
			std::cout << room[row][col].getSymbol();
		}

		std::cout << std::endl;
	}
}

/************************************ moveCharacter *************************************************
This function moves a character in the room.
Parameters: none
Returns: void
*****************************************************************************************************/
Movement Room::moveCharacter(std::unique_ptr<Character>& c, char direction, Room*& currentRoom)
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
		// if hero is leaving tile with treasure they didn't take, set symbol to T
		else
		{
			room[heroRow][heroCol].setSymbol('T');
		}

		heroRow = newRow;
		heroCol = newCol;
		return Movement::move;
	}
	// if tile has monster, fight monster
	else if (room[newRow][newCol].getMonster() != nullptr)
	{
		room[newRow][newCol].setToHero();
		room[heroRow][heroCol].setToEmpty();
		heroRow = newRow;
		heroCol = newCol;

		return Movement::combat;
	}
	// if tile has treasure, pick up treasure
	else if (room[newRow][newCol].getTreasure() != nullptr)
	{
		room[newRow][newCol].setToHero();
		room[heroRow][heroCol].setToEmpty();

		heroRow = newRow;
		heroCol = newCol;

		return Movement::treasure;
	}
	// if door is locked
	else if (room[newRow][newCol].getIsStairsOrDoor() == true && room[newRow][newCol].getIsLocked() == true)
	{
		return Movement::lockedDoor;
	}
	// if stairs/door and unlocked, go to new room
	else if (room[newRow][newCol].getIsStairsOrDoor() == true)
	{
		room[heroRow][heroCol].setToEmpty();
		heroRow = newRow;
		heroCol = newCol;
		return Movement::stairsOrDoor;
	}

	// hero rings bell in bell tower
	else if (room[newRow][newCol].getSymbol() == 'B')
	{
		int choice{ utility::getInt("\nRing the BELL? \n1. Yes \n2. No \n", 1, 2) };
		if (choice == 1)
		{
			std::cout << "\nThe ringing of the BELL is louder than you predicted."
				<< "\nAs its peals slowly fade, you hear an EVIL CACKLE below . . . ";

			//bellRung = true;
			return Movement::ringBell;
		}

		return Movement::move;
	}
	// invalid move
	else
	{
		return Movement::invalid;
	}
}

/************************************ getTreasure *************************************************
This function returns a pointer to the Treasure object at a certain row and column.
Parameters: int for row, int for column
Returns: Treasure pointer 
*****************************************************************************************************/
Treasure* Room::getTreasure(int row, int col)
{
	Treasure* t = room[row][col].getTreasure();			// returns address of smart pointer 
	return t;
}

/************************************ moveTreasure ***************************************************
This function moves the unique_ptr to Treasure object from the tile to the function, then returns that 
moved unique_ptr.
Parameters: int for row, int for column
Returns: moved unique_ptr<Treasure>
*****************************************************************************************************/
std::unique_ptr<Treasure> Room::moveTreasure(int row, int col)
{
	std::unique_ptr<Treasure> t = room[row][col].moveTreasure();
	return std::move(t);
}

/************************************ getMonster *************************************************
This function returns a pointer to the monster at a certain row and column
Parameters: int for row, int for column
Returns: Treasure pointer
*****************************************************************************************************/
Character* Room::getMonster(int row, int col)
{
	return room[row][col].getMonster();
}


/************************************ fillRoomMonsters ************************************************
This function fills a room with monsters. It is overridden by Sanctuary, because that room must be filled
with monsters if the player rings the bell in the bell tower. It does nothing for every other room.
Parameters: none
Returns: void
*****************************************************************************************************/
void Room::fillRoomMonsters()
{
}


/************************************ makeborders ******************************************************
this function fills a room with monsters. it is overridden by sanctuary, because that room must be filled
with monsters if the player rings the bell in the bell tower.
parameters: none
returns: void
*****************************************************************************************************/
void Room::makeBorders(int roomRows, int roomCols)
{
	for (int row = 0; row < roomRows; row++)
	{
		for (int col = 0; col < roomCols; col++)
		{
			if (row == 0 || row == roomRows - 1)
			{
				room[row][col].setSymbol('-');
				room[row][col].setEmpty(false);
			}
			else if (col == 0 || col == roomCols - 1)
			{
				room[row][col].setSymbol('|');
				room[row][col].setEmpty(false);
			}
			else
			{
				room[row][col].setSymbol(' ');
			}
		}
	}
}

/************************************ getters and setters  *******************************************/
//heroRow and heroCol
void Room::setHeroRowCol(int r, int c)
{
	heroRow = r;
	heroCol = c;
	room[r][c].setToHero();
}

// heroRow
int Room::getHeroRow()
{
	return heroRow;
}

void Room::setHeroRow(int r)
{
	heroRow = r;
}

// heroCol
int Room::getHeroCol()
{
	return heroCol;
}

void Room::setHeroCol(int c)
{
	heroCol = c;
}