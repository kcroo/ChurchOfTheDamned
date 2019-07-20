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
	std::unique_ptr<Treasure> weapon = std::make_unique<Treasure>("Wooden Mallet", 4, 0, 0, Type::weapon);
	std::unique_ptr<Treasure> armor = std::make_unique<Treasure>("Wool Clothing", 0, 5, 0, Type::armor);
	inventory.add(std::move(weapon));
	inventory.add(std::move(armor));
	
	currentWeapon = inventory.getTreasure(0);
	currentArmor = inventory.getTreasure(1);
	std::cout << "\nIn fighter constructor";
	currentWeapon->print();
	currentArmor->print();
}

/********************************* destructor *****************************************************
New inventory items deleted in Character destructor.
***************************************************************************************************/
Fighter::~Fighter()
{
}