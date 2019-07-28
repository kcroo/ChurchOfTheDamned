/**************************************************************************************************
Program Name: Final Project
File: Combat.hpp
Author: Kirsten Corrao
Date: 03/05/2019
Description: this is the header file of the Combat class. This class is used when the hero must fight 
a monster. The hero attacks first. They roll a 20-sided die, and if that value is above the enemy's 
armor class, they roll again to see what damage they inflict. Armor class is determined by the 
currently equipped armor, and the amount of damage is determined by the currently equipped weapon. 
Combat automatically alternates between the hero and monster attacking each other. If the hero hits 
0 HP and has holy water in their inventory, they are revived with the amount of HP the holy water 
indicates. The hero wins if the enemy has 0 HP. If the hero has 0 HP and no holy water, they lose
and the game is over. After an enemy is defeated, the hero can loot the body of any weapons, armor,
or holy water it has.
***************************************************************************************************/
#ifndef COMBAT_HPP
#define COMBAT_HPP

#include "character.hpp"
#include "room.hpp"
#include "treasure.hpp"
#include "utility.hpp"

class Combat
{
private:
	Character* hero;
	Character* enemy;

	// weapons and armor
	Treasure* heroWeapon;
	int heroWeaponDamage;
	Treasure* heroArmor;
	int heroArmorRating;

	Treasure* enemyWeapon;
	int enemyWeaponDamage;
	Treasure* enemyArmor;
	int enemyArmorRating;

	// inventory
	Inventory* inventory;
	Inventory* enemyInv;

	// combat stats 
	static const int chanceHit = 20;			// 20-sided die
	
	// print figh results
	void displayWinner();
	void displayMissed(Character*& c, int attack);
	void displayHit(Character*& c, int attack, int damage);
	void displayHPWeaponArmor();
	void displayHolyWaterUsed(int restoredHP);

	void lootBody();
	void standardAttack(Character* attacker, Character* defender, int damage, int defense);
	int chooseSpecialAction(Character* attacker, Character* defender);
	void executeSpecialAction(Character* attacker, Character* defender, int choice);

public:
	Combat(Character* hero, Character* enemy);
	~Combat();
	void fightRevamped();
	void fight();

};

#endif 
