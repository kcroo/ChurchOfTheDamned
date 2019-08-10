/**************************************************************************************************
Program Name: Final Project
File: Lich.hpp
Author: Kirsten Corrao
Date: 03/14/2019
Description: this is the implementation file for Lich, which is a derived class of Character. It is
the final enemy in the game.
***************************************************************************************************/
#include "Lich.hpp"

/********************************* constructor ****************************************************
Uses the Character base class constructor to create a derived class object. Creates a weapon and 
armor in the Character's inventory and sets the Character's currentWeapon and currentArmor to them.
***************************************************************************************************/
Lich::Lich()
	: Character(20, "Lich Cardinal", "")		// HP, type, name
{
	inventory.add(new Treasure("Sword of the Spirits", 10, 0, 0, Type::weapon));
	inventory.add(new Treasure("Aura of Unrighteousness", 0, 12, 0, Type::armor));

	currentWeapon = inventory.getTreasure(0);
	currentArmor = inventory.getTreasure(1);
}

/********************************* destructor *****************************************************
New inventory items deleted in Character destructor.
***************************************************************************************************/
Lich::~Lich()
{
}