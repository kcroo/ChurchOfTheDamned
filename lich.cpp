/**************************************************************************************************
Program Name: Final Project
File: lich.cpp
Author: Kirsten Corrao
Date: 03/14/2019
Description: this is the implementation file for Lich, which is a derived class of Character. It is
the final enemy in the game.
***************************************************************************************************/
#include "lich.hpp"

/********************************* constructor ****************************************************
Uses the Character base class constructor to create a derived class object. Creates a weapon and 
armor in the Character's inventory and sets the Character's currentWeapon and currentArmor to them.
***************************************************************************************************/
Lich::Lich()
	: Character(20, "Lich Cardinal", "", 'L', 12)		// HP, type, name
{
	inventory.add(std::make_unique<Treasure>("Sword of the Spirits", 10, 0, 0, 0, Type::weapon));
	inventory.add(std::make_unique<Treasure>("Aura of Unrighteousness", 0, 12, 0, 0, Type::armor));

	currentWeapon = inventory.getTreasure(0);
	currentArmor = inventory.getTreasure(1);

	specialActions.push_back(std::make_unique<SpecialAction>(ActionType::attack, "Touch of the Damned", "The touch of the Lich's icy fingers cause 5-10 damage", 2, 5, 10, 0, 0, 0));
	specialActions.push_back(std::make_unique<SpecialAction>(ActionType::HP, "Sinister Restoration", "The powers of hell grant the Lich another 6 HP", 2, 0, 0, 0, 6, 0));
	specialActions.push_back(std::make_unique<SpecialAction>(ActionType::MP, "Dark Blessings", "The Lich gains the unholy blessing of Satan, restoring 5 MP", 1, 0, 0, 0, 0, 5));
}

/********************************* destructor *****************************************************
New inventory items deleted in Character destructor.
***************************************************************************************************/
Lich::~Lich()
{
}