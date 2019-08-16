/***************************************************************************************************
Program name: Final Project
File: Gallery.hpp
Author: Kirsten Corrao
Date: 03/04/2019
Description: this is the header file of the Gallery class. It is a derived class of 
Room. The gallery contains Ghosts as enemies.
***************************************************************************************************/
#ifndef GALLERY_HPP
#define GALLERY_HPP

#include "room.hpp"
#include "phantom.hpp"

class Gallery : public Room
{
public:
	Gallery();
	~Gallery();
	void setRoomConnections(Room* room1, Room* room2) override;
	void printContents() override;
	Room* moveNewRoom(int row, int col) override;

private:

};

#endif 
