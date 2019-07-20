/**************************************************************************************************
Program Name: Final Project
File: Character.hpp
Author: Kirsten Corrao
Date: 02/28/2019
Description: this is the header file for Character, which is an abstract base class. It has 6
derived classes: Fighter, ChoirBoy, DarkPriest, Ghost, GhoulTormentor, and Lich. The Fighter is the 
hero, while the others are enemies. 
Source for static const:
https://stackoverflow.com/questions/14495536/how-to-initialize-const-member-variable-in-a-class
***************************************************************************************************/
#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include <iostream>
#include <memory>
#include <string>
#include <vector>

#include "inventory.hpp"
#include "treasure.hpp"
#include "utility.hpp"

class Character
{
	protected:
		int HP;									// current hit points
		int maxHP;								// max possible hit points (can't restore past max)
		std::string type;						// e.g. "Dark Priest"
		std::string name;						// name of Character (empty for monsters)

		// inventory
		static const int capacity{ 5 };			// max # of items in inventory
		Inventory inventory;					// includes vector to contain weapons, armor, etc.
		Treasure* currentWeapon;
		Treasure* currentArmor;		

	public:
		Character(int maxHealth, std::string ty, std::string n);
		virtual ~Character() = 0;				

		int damageRoll();
		void decreaseHP(const int& damage);
		void recoverHP(int amountHealed);
		//void printWeaponAndArmor();
		//bool equipItem(Treasure*& item);

		// getters and setters
		int getHP();
		void setHP(int str);
		int getMaxHP();
		void setMaxHP(int max);
		std::string getType();
		void setType(std::string ty);
		std::string getName();
		void setName(std::string n);
		Inventory* getInventory();
		Treasure* getCurrentWeapon();
		void setCurrentWeapon(Treasure* t);
		Treasure* getCurrentArmor();
		void setCurrentArmor(Treasure* t);
};

#endif
