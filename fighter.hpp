/**************************************************************************************************
Program Name: Final Project
File: Fighter.hpp
Author: Kirsten Corrao
Date: 02/28/2019
Description: this is the header file for Fighter, which is a derived class of Character. 
This is the hero--they start with a weak weapon and armor. They must defeat enemies and find 
Treasure to survive.
***************************************************************************************************/
#ifndef FIGHTER_HPP
#define FIGHTER_HPP

#include <string>
#include "character.hpp"

class Fighter : public Character
{
	private:

	public:
		Fighter(std::string n);
		~Fighter();
};

#endif
