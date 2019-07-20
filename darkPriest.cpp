/**************************************************************************************************
Program Name: Final Project
File: DarkPriest.cpp
Author: Kirsten Corrao
Date: 03/14/2019
Description: this is the implementation file for DarkPriest, which is a derived class of Character.
***************************************************************************************************/
#include "darkPriest.hpp"

/********************************* constructor ****************************************************
Uses the Character base class constructor to create a derived class object. Creates a weapon and 
armor in the Character's inventory and sets the Character's currentWeapon and currentArmor to them.
***************************************************************************************************/
DarkPriest::DarkPriest() 
	: Character(10, "Dark Priest", "", 'P')		// HP, type, name
{
	inventory.add(std::make_unique<Treasure>("Devil's Staff", 3, 0, 0, Type::weapon));
	inventory.add(std::make_unique<Treasure>("Unholy Robes", 0, 4, 0, Type::armor));

	currentWeapon = inventory.getTreasure(0);
	currentArmor = inventory.getTreasure(1);
}

/********************************* destructor *****************************************************
New inventory items deleted in Character destructor.
***************************************************************************************************/
DarkPriest::~DarkPriest()
{
}