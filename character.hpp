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
#include "specialAction.hpp"
#include "treasure.hpp"
#include "utility.hpp"

class Character
{
	protected:
		int HP;									// current hit points
		int maxHP;								// max possible hit points (can't restore past max)
		std::string type;						// e.g. "Dark Priest"
		std::string name;						// name of Character (empty for monsters)
		char symbol;
		int MP;
		int maxMP;
		int level;

		// inventory
		//static const int capacity{ 5 };			// max # of items in inventory
		Inventory inventory;					// includes vector to contain weapons, armor, etc.
		Treasure* currentWeapon;
		Treasure* currentArmor;		


		// special attacks
		std::vector<std::unique_ptr<SpecialAction>> specialActions;

	public:
		Character(int maxHealth, std::string ty, std::string n, char sym, int m, int lvl);
		virtual ~Character() = 0;				

		int damageRoll();
		void decreaseHP(const int& damage);
		void recoverHP(int amountHealed);
		void decreaseMP(const int& amount);
		void recoverMP(const int& amount);
		
		
		// inventory
		void printWeaponAndArmor();
		bool equipItem(Treasure*& item);
		void printInventory();
		bool isInventoryFull();


		// special attacks
		void printSpecialActions();

		// getters and setters
		int getHP();
		void setHP(int str);
		int getMaxHP();
		void setMaxHP(int max);
		std::string getType();
		void setType(std::string ty);
		std::string getName();
		void setName(std::string n);
		char getSymbol();
		int getMP();
		int getMaxMP();
		void setLevel(int lvl);
		int getLevel();
		Inventory* getInventory();
		Treasure* getCurrentWeapon();
		void setCurrentWeapon(Treasure* t);
		Treasure* getCurrentArmor();
		void setCurrentArmor(Treasure* t);
		int getSpecialActionsSize();
		SpecialAction* getSpecialActionByIndex(int idx);
};

#endif
