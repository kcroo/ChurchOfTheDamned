/***************************************************************************************************
Program name: Final Project
File: bellTower.hpp
Author: Kirsten Corrao
Date: 03/04/2019
Description: this is the header file of the BellTower class. It is a derived class of 
Room. The bell tower contains a Dark Priest as an enemy.
***************************************************************************************************/
#ifndef BELLTOWER_HPP
#define BELLTOWER_HPP

#include "character.hpp"
#include "room.hpp"

class BellTower : public Room
{
	public:
		BellTower();
		~BellTower();
		void setRoomConnections(Room* room1, Room* room2) override;
		void printContents() override;
		Room* moveNewRoom(int row, int col) override;
		int moveCharacter(std::unique_ptr<Character>& c, char direction, Room*& currentRoom) override;
		bool getBellRung();

	private:
};

#endif 

