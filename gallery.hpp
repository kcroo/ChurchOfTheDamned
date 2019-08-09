/***************************************************************************************************
Program name: Final Project
File: Gallery.hpp
Author: Kirsten Corrao
Date: 03/04/2019
Description: this is the header file of the Gallery class. It is a derived class of 
Space. The gallery contains Ghosts as enemies.
***************************************************************************************************/
#ifndef GALLERY_HPP
#define GALLERY_HPP

#include "Character.hpp"
#include "Space.hpp"

class Gallery : public Space
{
public:
	Gallery();
	~Gallery();
	void setRoomConnections(Space* room1, Space* room2) override;
	void printContents() override;
	Space* moveNewRoom(int row, int col) override;

private:

};

#endif 
