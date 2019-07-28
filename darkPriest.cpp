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
	: Character(10, "Dark Priest", "", 'P', 4, 1)		// HP, type, name, symbol, divineBlessings, level
{
	maxMana = mana;

	inventory.add(std::make_unique<Treasure>("Devil's Staff", 3, 0, 0, Type::weapon));
	inventory.add(std::make_unique<Treasure>("Unholy Robes", 0, 4, 0, Type::armor));

	currentWeapon = inventory.getTreasure(0);
	currentArmor = inventory.getTreasure(1);

	specialActions.push_back(std::make_unique<SpecialAction>(ActionType::attack, "Satanic Incantations", "Prayers to Satan bring hell on earth, causing 1D6 damage.", 2, 1, 6, 0, 0, 0));
	specialActions.push_back(std::make_unique<SpecialAction>(ActionType::mana, "Unholy Meditations", "Communing with the priest's hellish overloads restores 4 MP.", 1, 0, 0, 0, 0, 4));
}

/********************************* destructor *****************************************************
New inventory items deleted in Character destructor.
***************************************************************************************************/
DarkPriest::~DarkPriest()
{
}