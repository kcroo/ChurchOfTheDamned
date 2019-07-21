/**************************************************************************************************
Program Name: Final Project
File: Character.cpp
Author: Kirsten Corrao
Date: 02/28/2019
Description: this is the implementation file for Character, which is an abstract base class. It has 6
derived classes: Fighter, ChoirBoy, DarkPriest, Ghost, GhoulTormentor, and Lich. The Fighter is the 
hero, while the others are enemies.
***************************************************************************************************/
#include "character.hpp"

/********************************* constructor ****************************************************
This is the Character base class constructor. It takes values for HP, maxHP, type, and name; and sets
	initial values for all other member variables.
Arguments: 1 integer for starting/max HP, 1 string for type of character (e.g. fighter, dark priest),
	1 string for name (blank for enemies)
***************************************************************************************************/
Character::Character(int maxHealth, std::string ty, std::string n, char sym, int db, int lvl)
	: HP{ maxHealth }, maxHP{ maxHealth }, type{ ty }, name{ n }, symbol{ sym }, divineBlessings{ db },
	level{ lvl }
{
	// weapon and armor allocated in derived classes
}

/********************************* destructor *****************************************************
This is the Character base class destructor. It deletes all Treasure objects in the inventory 
vector.
***************************************************************************************************/
Character::~Character()
{
}

/********************************* damageRoll *******************************************************
This function returns the result of rolling the character's weapon die. The max damage is based on 
the character's current weapon. For example, a weapon with damage of 6 will inflict 1 to 6 damage
on a hit.
Arguments: none
Returns: integer (the Character's total attack points)
***************************************************************************************************/
int Character::damageRoll()
{
	return 1;
	//return utility.getRandInt(1, currentWeapon->getDamage());
}

/********************************* decreaseHP ************************************************
This function decreases the character's strength according to the amount of damage done. It takes 
the amount of damage done in an attack and deduct it from the character's strength. If damage causes 
strength to go below 0, strength equals 0.
Arguments: 1 integer by reference (amount of damage to decrease strength by)
Returns: void
***************************************************************************************************/
void Character::decreaseHP(const int& damage)
{
	HP -= damage;
	if (HP < 0)
	{
		HP = 0;
	}
}

/********************************* recoverHP ************************************************
This function recovers some of the character's HP, for example after drinking holy water. HP will
not be set above that character's maximum HP.
Arguments: int (how much to recover)
Returns: void
***************************************************************************************************/
void Character::recoverHP(int amountHealed)
{
	HP += amountHealed;

	// if restored damage will exceed character's max strength, set it to max 
	if (HP > maxHP)
	{
		HP = maxHP;
	}
}

/********************************* printWeaponAndArmor ********************************************
This function prints the Character's currently equipped weapon and armor stats.
Arguments: none
Returns: void
***************************************************************************************************/
void Character::printWeaponAndArmor()
{
	std::string hp{ std::to_string(HP) };

	std::cout << "\n--------------------------------------------------------\n";
	utility::printColumns(Character::getType(), "Currently Equipped", "", hp + " HP");
	std::cout << "--------------------------------------------------------\n";
	utility::printColumns("", "Name", "Attack", "Armor");
	utility::printColumns("Weapon", currentWeapon->getName(), currentWeapon->getAttack(), "");
	utility::printColumns("Armor", currentArmor->getName(), "", currentArmor->getDefense());
	std::cout << "--------------------------------------------------------\n";
}

/********************************* equipItem *******************************************************
This function equips an item as the Character's current weapon or armor. If the item is already 
equipped, it just equips it again and returns true. If the item is not a weapon or armor, it returns false.
Arguments: Treasure pointer by reference
Returns: true if item successfully equipped, false if not
***************************************************************************************************/
bool Character::equipItem(Treasure*& item)
{
	// equip weapon
	if (item->getType() == Type::weapon)
	{
		currentWeapon = item;
		return true;
	}
	else if (item->getType() == Type::armor)
	{
		currentArmor = item;
		return true;
	}
	else
	{
		return false;
	}
}


/********************************* getters and setters ********************************************
***************************************************************************************************/

// HP
int Character::getHP()
{
	return HP;
}

void Character::setHP(int str)
{
	HP = str;
}

// maxHP
int Character::getMaxHP()
{
	return maxHP;
}

void Character::setMaxHP(int max)
{
	maxHP = max;
}

// type
std::string Character::getType()
{
	return type;
}

void Character::setType(std::string ty)
{
	type = ty;
}

// name
std::string Character::getName()
{
	return name;
}

void Character::setName(std::string n)
{
	name = n;
}

// symbol
char Character::getSymbol()
{
	return symbol;
}

// level
void Character::setLevel(int lvl)
{
	level = lvl;
}

int Character::getLevel()
{
	return level;
}

// inventory
Inventory* Character::getInventory()
{
	return &inventory;
}

// currentWeapon
Treasure* Character::getCurrentWeapon()
{
	return currentWeapon;
}

void Character::setCurrentWeapon(Treasure* t)
{
	currentWeapon = t;
}

// currentArmor
Treasure* Character::getCurrentArmor()
{
	return currentArmor;
}

void Character::setCurrentArmor(Treasure* t)
{
	currentArmor = t;
}