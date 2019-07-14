/***************************************************************************************************
Program name: Final Project
File: Sanctuary.hpp
Author: Kirsten Corrao
Date: 03/04/2019
Description: this is the header file of the Sanctuary class. It is a derived class of 
Room. The sanctuary contains Dark Priests as enemies.
***************************************************************************************************/
#ifndef SANCTUARY_HPP
#define SANCTUARY_HPP

#include "character.hpp"
//#include "Inventory.hpp"
#include "room.hpp"

class Sanctuary : public Room
{
	public:
		Sanctuary();
		~Sanctuary();
		//void setRoomConnections(Room* room1, Room* room2) override;
		void printContents() override;
		//Room* moveNewRoom(int row, int col) override;
		//void fillRoomMonsters() override;

	private:
};

#endif 
