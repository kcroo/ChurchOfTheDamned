/***************************************************************************************************
Program name: Final Project
File: Gallery.hpp
Author: Kirsten Corrao
Date: 03/04/2019
Description: this is the header file of the Dungeon class. It is a derived class of 
Space. The dungeon contains Ghoul Tormentors as enemies.
***************************************************************************************************/
#ifndef DUNGEON_HPP
#define DUNGEON_HPP

#include "Character.hpp"
#include "Space.hpp"

class Dungeon : public Space
{
public:
	Dungeon();
	~Dungeon();
	void setRoomConnections(Space* room1, Space* room2) override;
	void printContents() override;
	Space* moveNewRoom(int row, int col) override;

private:

};

#endif 
