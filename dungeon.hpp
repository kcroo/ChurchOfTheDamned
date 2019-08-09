/***************************************************************************************************
Program name: Final Project
File: Gallery.hpp
Author: Kirsten Corrao
Date: 03/04/2019
Description: this is the header file of the Dungeon class. It is a derived class of 
Room. The dungeon contains Ghoul Tormentors as enemies.
***************************************************************************************************/
#ifndef DUNGEON_HPP
#define DUNGEON_HPP

#include "character.hpp"
#include "room.hpp"

class Dungeon : public Room
{
public:
	Dungeon();
	~Dungeon();
	void setRoomConnections(Room* room1, Room* room2) override;
	void printContents() override;
	Room* moveNewRoom(int row, int col) override;

private:

};

#endif 
