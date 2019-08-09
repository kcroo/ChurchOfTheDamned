/***************************************************************************************************
Program name: Final Project
File: Crypt.hpp
Author: Kirsten Corrao
Date: 03/04/2019
Description: this is the header file of the Crypt class. It is a derived class of 
Space. The crypt contains the Lich Cardinal, who is the final boss of the game. The game ends if the 
hero defeats the Lich Cardinal (or dies).
***************************************************************************************************/
#ifndef CRYPT_HPP
#define CRYPT_HPP

#include "Character.hpp"
#include "room.hpp"

class Crypt : public Space
{
public:
	Crypt();
	~Crypt();
	void setRoomConnections(Space* room1, Space* room2);
	void printContents() override;
	Space* moveNewRoom(int row, int col) override;

private:
};

#endif 