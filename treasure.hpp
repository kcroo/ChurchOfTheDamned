/**************************************************************************************************
Program Name: Final Project
File: Treasure.hpp
Author: Kirsten Corrao
Date: 03/05/2019
Description: this is the header file for the Treasure class. Treasure is a broad term for 
weapons, armor, holy wate, or key. Weapons determine a Character object's attack damage; armor determines
armor class; and holy water heals the hero of damage. The enum class Type is used to differentiate 
treasure in other classes.
***************************************************************************************************/
#ifndef TREASURE_HPP
#define TREASURE_HPP

#include "utility.hpp"
#include <iostream>
#include <string>

enum class Type { weapon, armor, holyWater, key };

class Treasure
{
private:
	std::string name;
	int damage;
	int armorRating;
	int HPChange;
	Type type;

public:
	Treasure(std::string name, int attBonus, int armBonus, int hp, Type t);
	~Treasure();
	void print();

	// getters and setters
	std::string getName();
	int getDamage();
	int getArmorRating();
	int getHPChange();
	Type getType();
};

#endif
