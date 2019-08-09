/***************************************************************************************************
Program name: Final Project
File: Sanctuary.cpp
Author: Kirsten Corrao
Date: 03/04/2019
Description: this is the header file of the Mezzanine class. It is a derived class of 
Space. The mezzanine contains Zombie Choir Boys as enemies.
***************************************************************************************************/
#ifndef MEZZANINE_HPP
#define MEZZANINE_HPP

#include "Space.hpp"

class Mezzanine : public Space
{
	private:

	public:
		Mezzanine();
		~Mezzanine();
		void setRoomConnections(Space* room1, Space* room2) override;
		void printContents() override;
		Space* moveNewRoom(int row, int col) override;
};

#endif
