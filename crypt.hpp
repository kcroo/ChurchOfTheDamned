/***************************************************************************************************
Program name: Final Project
File: Crypt.hpp
Author: Kirsten Corrao
Date: 03/04/2019
Description: this is the header file of the Crypt class. It is a derived class of 
Room. The crypt contains the Lich Cardinal, who is the final boss of the game. The game ends if the 
hero defeats the Lich Cardinal (or dies).
***************************************************************************************************/
#ifndef CRYPT_HPP
#define CRYPT_HPP

#include "room.hpp"
#include "lich.hpp"

class Crypt : public Room
{
public:
	Crypt();
	~Crypt();
	void setRoomConnections(Room* room1, Room* room2);
	void printContents() override;
	Room* moveNewRoom(int row, int col) override;

private:
};

#endif 