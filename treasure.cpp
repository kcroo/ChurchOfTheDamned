/**************************************************************************************************
Program Name: Final Project
File: Treasure.cpp
Author: Kirsten Corrao
Date: 03/05/2019
Description: this is the implementation file for the Treasure class. Treasure is a broad term for 
weapons, armor, holy water, or key. Weapons determine a Character object's attack damage; armor determines
armor class; and holy water heals the hero of damage. 
***************************************************************************************************/
#include "treasure.hpp"

/************************************ constructor ****************************************************
The constructor takes 5 parameters to set initial values for name, attack bonus, armor bonus, how 
much HP the treasure can recover, and an enum for Type (weapon, armor, or holyWater).
*****************************************************************************************************/
Treasure::Treasure(std::string n, int dam, int armBonus, int hp, Type t)
	: name{ n }, damage{ dam }, armorRating{ armBonus }, HPChange{ hp }, type{ t }
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
	utility::printColumns("Item", "Name", "Damage", "Armor", "HP Restored");
	utility::printColumns("", name, damage, armorRating, HPChange);
}

/************************************ getters and setters  ********************************************/

// name
std::string Treasure::getName()
{
	return name;
}

// attack bonus
int Treasure::getDamage()
{
	return damage;
}

// armor bonus
int Treasure::getArmorRating()
{
	return armorRating;
}

// HP bonus
int Treasure::getHPChange()
{
	return HPChange;
}

// type
Type Treasure::getType()
{
	return type;
}