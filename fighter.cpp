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
	: Character(12, "Fighter", n, 'H', 5)		// HP, type, name, symbol, mana, level
{
	maxMP = MP;

	inventory.add(std::make_unique<Treasure>("Wooden Mallet", 4, 0, 0, 0, Type::weapon));
	inventory.add(std::make_unique<Treasure>("Wool Clothing", 0, 5, 0, 0, Type::armor));
	
	currentWeapon = inventory.getTreasure(0);
	currentArmor = inventory.getTreasure(1);

	specialActions.push_back(std::make_unique<SpecialAction>(ActionType::attack, "Holy Smite", "Rain down the wrath of God on your enemy for 2-10 damage", 2, 2, 10, 0, 0, 0));
	specialActions.push_back(std::make_unique<SpecialAction>(ActionType::defense, "Armor of God", "Raises your armor class by 2 points for the rest of the battle", 1, 0, 0, 2, 0, 0));
}

/********************************* destructor *****************************************************
New inventory items deleted in Character destructor.
***************************************************************************************************/
Fighter::~Fighter()
{
}