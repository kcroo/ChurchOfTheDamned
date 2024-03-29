/**************************************************************************************************
Program Name: Final Project
File: Treasure.cpp
Author: Kirsten Corrao
Date: 03/05/2019
Description: this is the implementation file for the Treasure class. Treasure is a broad term for 
weapons, armor, holy water, or key. Weapons determine a Character object's attack attack; armor determines
armor class; and holy water heals the hero of attack. 
***************************************************************************************************/
#include "treasure.hpp"

/************************************ constructor ****************************************************
The constructor takes 5 parameters to set initial values for name, attack bonus, armor bonus, how 
much HP the treasure can recover, and an enum for Type (weapon, armor, or holyWater).
*****************************************************************************************************/
Treasure::Treasure(std::string n, int dam, int armBonus, int hp, int mp, Type t)
	: name{ n }, attack{ dam }, defense{ armBonus }, HPChange{ hp }, MPChange{ mp }, type{ t }
{
}

/************************************ destructor *****************************************************
*****************************************************************************************************/
Treasure::~Treasure()
{
}

/************************************ print *********************************************************
This function prints the treasure's stats.
*****************************************************************************************************/
void Treasure::print()
{
	utility::printColumns("Item", "Name", "Attack", "Armor", "HP+", "MP+");
	utility::printColumns("", name, attack, defense, HPChange, MPChange);
}

/************************************ getters and setters  ********************************************/

// name
std::string Treasure::getName()
{
	return name;
}

// attack bonus
int Treasure::getAttack()
{
	return attack;
}

// armor bonus
int Treasure::getDefense()
{
	return defense;
}

// HP restored
int Treasure::getHPChange()
{
	return HPChange;
}

// MP restored
int Treasure::getMPChange()
{
	return MPChange;
}

// type
Type Treasure::getType()
{
	return type;
}