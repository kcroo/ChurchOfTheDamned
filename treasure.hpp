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

enum class Type { weapon, armor, bread, wine, key };

class Treasure
{
private:
	std::string name;
	int attack;
	int defense;
	int HPChange;
	int MPChange;
	Type type;

public:
	Treasure(std::string name, int att, int def, int hp, int mp, Type t);
	~Treasure();
	void print();

	// getters and setters
	std::string getName();
	int getAttack();
	int getDefense();
	int getHPChange();
	int getMPChange();
	Type getType();
};

#endif
