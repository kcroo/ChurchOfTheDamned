/**************************************************************************************************
Program Name: Final Project
File: ChoirBoy.hpp
Author: Kirsten Corrao
Date: 03/14/2019
Description: this is the implementation file for ChoirBoy, which is a derived class of Character.
***************************************************************************************************/
#include "choirBoy.hpp"

/********************************* constructor ****************************************************
Uses the Character base class constructor to create a derived class object. Creates a weapon and 
armor in the Character's inventory and sets the Character's currentWeapon and currentArmor to them.
***************************************************************************************************/
ChoirBoy::ChoirBoy()
	: Character(5, "Zombie Choir Boy", "", 'Z', 12)		// HP, type, name
{
	inventory.add(std::make_unique<Treasure>("Satanic Hymnal", 2, 0, 0, 0, Type::weapon));
	inventory.add(std::make_unique<Treasure>("Choir Robes", 0, 2, 0, 0, Type::armor));

	currentWeapon = inventory.getTreasure(0);
	currentArmor = inventory.getTreasure(1);

	specialActions.push_back(std::make_unique<SpecialAction>(ActionType::attack, "Hymn of Beelzebub", "A disturbing hymn straight from hell causes 2-10 damage", 3, 2, 10, 0, 0, 0));
	specialActions.push_back(std::make_unique<SpecialAction>(ActionType::attack, "Zombie Bite", "The Zombie child tears at the hero's flesh, causing 1-6 damage", 2, 1, 6, 0, 0, 0));
}

/********************************* destructor *****************************************************
New inventory items deleted in Character destructor.
***************************************************************************************************/
ChoirBoy::~ChoirBoy()
{
}
