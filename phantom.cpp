/**************************************************************************************************
Program Name: Final Project
File: phantom.hpp
Author: Kirsten Corrao
Date: 03/14/2019
Description: this is the implementation file for Phantom, which is a derived class of Character.
***************************************************************************************************/
#include "phantom.hpp"

/********************************* constructor ****************************************************
Uses the Character base class constructor to create a derived class object. Creates a weapon and 
armor in the Character's inventory and sets the Character's currentWeapon and currentArmor to them.
***************************************************************************************************/
Phantom::Phantom()
	: Character(6, "Corrupted Phantom", "", 'P', 10)		// HP, type, name
{
	inventory.add(std::make_unique<Treasure>("Soul Suck", 6, 0, 0, 0, Type::weapon));
	inventory.add(std::make_unique<Treasure>("Ethereal Chain Mail", 0, 10, 0, 0, Type::armor));

	currentWeapon = inventory.getTreasure(0);
	currentArmor = inventory.getTreasure(1);

	specialActions.push_back(std::make_unique<SpecialAction>(ActionType::attack, "Piercing Scream", "A high-pitched scream that causes 3-6 damage", 3, 3, 6, 0, 0, 0));
	specialActions.push_back(std::make_unique<SpecialAction>(ActionType::attack, "Ghostly Inhabitation", "Flying its incorporeal form through the hero's body causes 2-8 damage.", 4, 2, 8, 0, 0, 0));
}

/********************************* destructor *****************************************************
New inventory items deleted in Character destructor.
***************************************************************************************************/
Phantom::~Phantom()
{
}