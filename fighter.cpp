/**************************************************************************************************
Program Name: Final Project
File: Fighter.cpp
Author: Kirsten Corrao
Date: 03/14/2019
Description: this is the implementation file for Fighter, which is a derived class of Character. 
This is the hero--they start with a weak weapon and armor. They must defeat enemies and find 
Treasure to survive.
***************************************************************************************************/
#include "fighter.hpp"

/********************************* constructor ****************************************************
Uses the Character base class constructor to create a derived class object. Creates a weapon and 
armor in the Character's inventory and sets the Character's currentWeapon and currentArmor to them.
***************************************************************************************************/
Fighter::Fighter(std::string n)
	: Character(12, "Fighter", n)		// HP, type, name
{
	/*inventory.add(new Treasure("Wooden Mallet", 4, 0, 0, Type::weapon));
	inventory.add(new Treasure("Wool Clothing", 0, 5, 0, Type::armor));
	
	currentWeapon = inventory.getTreasure(0);
	currentArmor = inventory.getTreasure(1);*/
}

/********************************* destructor *****************************************************
New inventory items deleted in Character destructor.
***************************************************************************************************/
Fighter::~Fighter()
{
}