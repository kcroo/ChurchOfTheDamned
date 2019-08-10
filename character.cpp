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
Character::Character(int maxHealth, std::string ty, std::string n, char sym, int m)
	: HP{ maxHealth }, maxHP{ maxHealth }, type{ ty }, name{ n }, symbol{ sym }, MP{ m }
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
	return utility::getRandInt(1, currentWeapon->getAttack());
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

/********************************* decreaseMP ************************************************

***************************************************************************************************/
void Character::decreaseMP(const int& amount)
{
	MP -= amount;
	if (MP < 0)
	{
		MP = 0;
	}
}

/********************************* recoverMP ************************************************

***************************************************************************************************/
void Character::recoverMP(const int& amount)
{
	MP += amount;

	// if restored damage will exceed character's max strength, set it to max 
	if (MP > maxMP)
	{
		MP = maxMP;
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

///********************************* equipItem *******************************************************
//This function equips an item as the Character's current weapon or armor. If the item is already 
//equipped, it just equips it again and returns true. If the item is not a weapon or armor, it returns false.
//Arguments: Treasure pointer by reference
//Returns: true if item successfully equipped, false if not
//***************************************************************************************************/
//bool Character::equipItem(Treasure*& item)
//{
//	// equip weapon
//	if (item->getType() == Type::weapon)
//	{
//		currentWeapon = item; return true;
//	}
//	else if (item->getType() == Type::armor)
//	{
//		currentArmor = item;
//		return true;
//	}
//	else
//	{
//		return false;
//	}
//}

/********************************* equipItem *******************************************************
Parameter: index of item to try to equip.
Returns: true if item equipped successfully, false if not (e.g. item not a weapon or armor)
***************************************************************************************************/
bool Character::equipItem(const int idx)
{
	Treasure* item{ inventory.getTreasure(idx) };

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

/********************************* printInventory **************************************************
Uses the Inventory class function to print each item in the inventory.
***************************************************************************************************/
void Character::printInventory()
{
	inventory.print();
}

/********************************* isInventoryFull *************************************************
Returns true if inventory not full (e.g. can add items to it). Returns false if full.
***************************************************************************************************/
bool Character::inventoryNotFull()
{
	return inventory.notFull();
}

/********************************* inventoryEmpty *************************************************
Returns true if inventory contains no items
***************************************************************************************************/
bool Character::inventoryEmpty()
{
	return inventory.isEmpty();
}

/********************************* addItem *********************************************************
Adds item to player's inventory. Size of inventory is checked in Game.cpp. 
Parameters: unique Treasure pointer
Returns: void
***************************************************************************************************/
void Character::addItem(std::unique_ptr<Treasure> t)
{
	std::unique_ptr<Treasure> treasure = std::move(t);
	inventory.add(std::move(treasure));
}

/********************************* removeItem ******************************************************
Removes item from player's inventory if that item is not the current weapon or armor.
Parameter: index of item to remove
Returns: true if item removed, false if not (because it's the current weapon or armor)
***************************************************************************************************/
bool Character::removeItem(int idx)
{
	Treasure* item{ inventory.getTreasure(idx) };

	if (item != currentWeapon && item != currentArmor)
	{
		inventory.deleteItem(idx);
		return true;
	}

	return false;
}

/********************************* getInventorySize ***********************************************
Returns current number of items in inventory.
***************************************************************************************************/
int Character::getInventorySize()
{
	return inventory.getSize();
}

/********************************* getItemByIndex **************************************************
Returns Treasure pointer to item in player's inventory. 
Parameters: index of item in inventory
***************************************************************************************************/
Treasure* Character::getItemByIndex(const int idx)
{
	return inventory.getTreasure(idx);
}

/********************************* moveTreasure **************************************************

***************************************************************************************************/
std::unique_ptr<Treasure> Character::moveTreasure(const int idx)
{
	std::unique_ptr<Treasure> treasure{ inventory.moveTreasure(idx) };
	return std::move(treasure);
}

/********************************* drinkHolyWater **************************************************
If there is holy water in the inventory, the hero drinks it and returns the amount of HP the holy
water restored. Otherwise, it returns -1 to indicate that no holy water was in the inventory.
***************************************************************************************************/
int Character::drinkHolyWater()
{
	int position{ inventory.getItemPosition(Type::holyWater) };

	if (position != -1)
	{
		int hpRecovered{ inventory.useHolyWater(position) };
		Character::recoverHP(hpRecovered);
		return hpRecovered;
	}

	// no holy water: 0 HP recovered
	else
	{
		return 0;
	}
}

/********************************* hasKey *********************************************************
Returns true if inventory contains key. Returns false if it does not.
***************************************************************************************************/
bool Character::hasKey()
{
	return inventory.hasKey();
}

/********************************* printSpecialActions *********************************************

***************************************************************************************************/
void Character::printSpecialActions()
{
	int counter{ 1 };
    std::cout << std::endl;

    std::cout << "\n------------------ SPECIAL ACTIONS ---------------------";
	for (const std::unique_ptr<SpecialAction>& act : specialActions)
	{
		std::cout << "\n" << counter << ". " << act->getName()
			<< "\nMP required: " << act->getMPRequired()
			<< "\n" << act->getDescription() << std::endl;
		counter++;
	}

    std::cout << "---------------------------------------------------------\n\n";
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

// MP
int Character::getMP()
{
	return MP;
}

// maxMP
int Character::getMaxMP()
{
	return maxMP;
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

// specialActions
int Character::getSpecialActionsSize()
{
	return specialActions.size();
}

SpecialAction* Character::getSpecialActionByIndex(int idx)
{
	return specialActions.at(idx).get();
}
