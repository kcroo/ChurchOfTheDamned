/***************************************************************************************************
Program name: Church of the Damned
File: Room.cpp
Author: Kirsten Corrao
Date: 07/12/2019
***************************************************************************************************/
#include "room.hpp"
#include <assert.h>

/************************************ constructor ****************************************************
The constructor creates a 2D array made of Tile objects, then creates a border around the room.
Parameters: # of rows in room, # of columns in room, string for name of room
*****************************************************************************************************/
Room::Room(int rows, int cols, std::string n)
	: roomRows{ rows }, roomCols{ cols }, name{ n },
	heroRow{ -1 }, heroCol{ -1 },
	north{ nullptr }, south{ nullptr }, east{ nullptr }, west{ nullptr }, above{ nullptr }, below{ nullptr }
	/*treasure1{ nullptr }, treasure2{ nullptr },
	monster1{ nullptr }, monster2{ nullptr }, monster3{ nullptr }, monster4{ nullptr }, monster5{ nullptr }, 
	monster6{ nullptr }, bellRung{ false }*/
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

	//// delete treasure and monsters in room
	//delete treasure1;
	//treasure1 = nullptr;
	//delete treasure2;
	//treasure2 = nullptr;

	//delete monster1;
	//monster1 = nullptr;
	//delete monster2;
	//monster2 = nullptr;
	//delete monster3;
	//monster3 = nullptr;
	//delete monster4;
	//monster4 = nullptr;
	//delete monster5;
	//monster5 = nullptr;
	//delete monster6;
	//monster6 = nullptr;
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
			if (row == heroRow && col == heroCol)
			{
				std::cout << 'H';
			}
			else
			{
				std::cout << room[row][col].getSymbol();
			}
		}

		std::cout << std::endl;
	}
}

/************************************ moveCharacter *************************************************
This function moves a character in the room.
Parameters: none
Returns: void
*****************************************************************************************************/
int Room::moveCharacter(std::unique_ptr<Character>& c, char direction, std::shared_ptr<Room>& currentRoom)
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
		room[heroRow][heroCol].setToEmpty();
		room[newRow][newCol].setToHero();

		//// if hero is leaving tile with no treasure, set to empty
		//if (room[heroRow][heroCol].getTreasure() == nullptr)
		//{
		//	room[heroRow][heroCol].setToEmpty();
		//}
		//// if hero is leaving tile with treasure they didn't take, set symbol to T
		//else
		//{
		//	room[heroRow][heroCol].setSymbol('T');
		//}

		heroRow = newRow;
		heroCol = newCol;
		return 1;
	}
	//// if tile has monster, fight monster
	//else if (room[newRow][newCol].getMonster() != nullptr)
	//{
	//	room[newRow][newCol].setToHero();
	//	room[heroRow][heroCol].setToEmpty();
	//	heroRow = newRow;
	//	heroCol = newCol;

	//	return 2;
	//}
	// if tile has treasure, pick up treasure
	else if (room[newRow][newCol].getTreasure() != nullptr)
	{
		room[newRow][newCol].setToHero();
		room[heroRow][heroCol].setToEmpty();
		std::cout << "\nTreasure on tile " << newRow << " " << newCol << ":\n";

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
	// invalid move
	else
	{
		return 6;
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
	assert(t != nullptr);
	return t;
}

std::unique_ptr<Treasure> Room::moveTreasure(int row, int col)
{
	std::unique_ptr<Treasure> t = room[row][col].moveTreasure();
	return std::move(t);
}

///************************************ getMonster *************************************************
//This function returns a pointer to the monster at a certain row and column
//Parameters: int for row, int for column
//Returns: Treasure pointer
//*****************************************************************************************************/
//Character* Room::getMonster(int row, int col)
//{
//	return room[row][col].getMonster();
//}
//
///************************************ setTileToEmpty ************************************************
//This function sets a tile to empty (for example, after treasure has been taken, or an enemy has been
//fought.)
//Parameters: int for row, int for column
//Returns: void 
//*****************************************************************************************************/
//void Room::setTileToEmpty(int row, int col)
//{
//	room[row][col].setToEmpty();
//}
//
///************************************ setTileToHero ************************************************
//This function sets a tile to hero (sets hero pointer and character to H)
//Parameters: int for row, int for column
//Returns: void
//*****************************************************************************************************/
//void Room::setTileToHero(int row, int col)
//{
//	room[row][col].setToHero();
//	room[row][col].removeTreasure();
//	room[row][col].removeMonster();
//}
//
//
//
///************************************ setTileToMonster ************************************************
//This function fills a room with monsters. It is overridden by Sanctuary, because that room must be filled
//with monsters if the player rings the bell in the bell tower.
//Parameters: none
//Returns: void
//*****************************************************************************************************/
//void Room::fillRoomMonsters()
//{
//}
//

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

// bellRung
bool Room::getBellRung()
{
	return bellRung;
}