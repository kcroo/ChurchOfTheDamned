/**************************************************************************************************
Program Name: Final Project
File: ChoirBoy.hpp
Author: Kirsten Corrao
Date: 03/14/2019
Description: this is the implementation file for GhoulTormenter, which is a derived class of Character.
***************************************************************************************************/
#include "GhoulTormenter.hpp"

/********************************* constructor ****************************************************
Uses the Character base class constructor to create a derived class object. Creates a weapon and 
armor in the Character's inventory and sets the Character's currentWeapon and currentArmor to them.
***************************************************************************************************/
GhoulTormenter::GhoulTormenter()
	: Character(6, "Ghoul Tormenter", "")		// HP, type, name
{
	inventory.add(new Treasure("Human Arm", 5, 0, 0, Type::weapon));
	inventory.add(new Treasure("Human Leather", 0, 6, 0, Type::armor));

	currentWeapon = inventory.getTreasure(0);
	currentArmor = inventory.getTreasure(1);
}

/********************************* destructor *****************************************************
New inventory items deleted in Character destructor.
***************************************************************************************************/
GhoulTormenter::~GhoulTormenter()
{
}