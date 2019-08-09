/***************************************************************************************************
Program name: Final Project
File: Sanctuary.cpp
Author: Kirsten Corrao
Date: 03/04/2019
Description: this is the header file of the Mezzanine class. It is a derived class of 
Room. The mezzanine contains Zombie Choir Boys as enemies.
***************************************************************************************************/
#ifndef MEZZANINE_HPP
#define MEZZANINE_HPP

#include "room.hpp"
//#include "ChoirBoy.hpp"

class Mezzanine : public Room
{
	private:

	public:
		Mezzanine();
		~Mezzanine();
		void setRoomConnections(Room* room1, Room* room2) override;
		void printContents() override;
		Room* moveNewRoom(int row, int col) override;
};

#endif
