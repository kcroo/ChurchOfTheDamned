/**************************************************************************************************
Program Name: Final Project
File: ChoirBoy.hpp
Author: Kirsten Corrao
Date: 03/14/2019
Description: this is the implementation file for GhoulTormenter, which is a derived class of Character.
***************************************************************************************************/
#include "ghoul.hpp"

/********************************* constructor ****************************************************
Uses the Character base class constructor to create a derived class object. Creates a weapon and 
armor in the Character's inventory and sets the Character's currentWeapon and currentArmor to them.
***************************************************************************************************/
Ghoul::Ghoul()
	: Character(6, "Ghoul", "", 'G', 4)		// HP, type, name, symbol, MP
{
	inventory.add(std::make_unique<Treasure>("Human Arm", 5, 0, 0, 0, Type::weapon));
	inventory.add(std::make_unique<Treasure>("Human Leather", 0, 6, 0, 0, Type::armor));

	currentWeapon = inventory.getTreasure(0);
	currentArmor = inventory.getTreasure(1);

	specialActions.push_back(std::make_unique<SpecialAction>(ActionType::attack, "Claw Frenzy", "A frenetic assault of half-rotten claws causes 1-10 damage", 2, 1, 10, 0, 0, 0));
	specialActions.push_back(std::make_unique<SpecialAction>(ActionType::HP, "Blood Elixer", "An elixir made from the blood of human victims restores 2-4 HP", 1, 0, 0, 0, 4, 0));
}

/********************************* destructor *****************************************************
New inventory items deleted in Character destructor.
***************************************************************************************************/
Ghoul::~Ghoul()
{
}