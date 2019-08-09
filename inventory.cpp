/**************************************************************************************************
Program Name: Final Project
File: Inventory.cpp
Author: Kirsten Corrao
Date: 03/05/2019
Description: this is the implementation file of the Inventory class. This class makes managing the 
hero or enemy's inventory easier. These functions initialize the inventory to a Character's 
Treasure pointer vector; print the inventory's contents; ask the user to add treasure they've found;
add an item to their inventory; delete an item; check if the user has a key; use holy water to 
restore HP; and check if the user has any of a certain item (usually used with holy water).
***************************************************************************************************/
#include "inventory.hpp"

/************************************ constructor ****************************************************
*****************************************************************************************************/
Inventory::Inventory() 
{
}

/************************************ destructor *****************************************************
Deletes all items in inventory.
*****************************************************************************************************/
Inventory::~Inventory()
{
	//// delete Treasure objects in inventory
	//for (std::vector<Treasure*>::iterator it = inventory.begin(); it != inventory.end(); ++it)
	//{
	//	delete *it;
	//	*it = nullptr;
	//}
}

///********************************* initialize ************************************************
//This function initializes the inventory pointer to a vector of Treasure pointers.
//Arguments: pointer to vector of Treasure pointers by reference
//Returns: void
//***************************************************************************************************/
//void Inventory::initialize(std::vector<Treasure*> inv)
//{
//	inventory = inv;
//}

/********************************* printInventory ************************************************
This function prints the character's inventory.
Arguments: none
Returns: void
***************************************************************************************************/
void Inventory::print()
{
	std::cout << "\n--------------------------------------------------------" 
		<< "\nInventory" 
		<< "\n--------------------------------------------------------\n";

	utility::printColumns("Item #", "Name", "Attack", "Armor", "HP Restored");
	int counter{ 1 };

	for (std::vector<std::unique_ptr<Treasure>>::iterator it = inventory.begin(); it != inventory.end(); ++it)
	{
		std::string count{ std::to_string(counter) };
		std::string itemNum{ "Item " + count };
		std::string name{ (*it)->getName() };
		int attackBonus{ (*it)->getAttack() };
		int armorBonus{ (*it)->getDefense() };
		int HPBonus{ (*it)->getHPChange() };

		utility::printColumns(itemNum, name, attackBonus, armorBonus, HPBonus);
		++counter;
	}

	std::cout << "--------------------------------------------------------\n";
}

///********************************* foundTreasure ****************************************************
//This function asks the user to add the Treasure to their inventory. It returns true if they do, false
//if they don't.
//Arguments: Treasure pointer by reference
//Returns: void
//***************************************************************************************************/
//bool Inventory::foundTreasure(std::unique_ptr<Treasure> t)
//{
//	std::cout << "\nYou have found teasure!\n"
//		<< "\nDo you want to add the " << t->getName() << " to your inventory?\n";
//
//	Inventory::print();
//
//	// ask player to add treasure to inventory
//	int choice{ utility::getInt("\n1. Add to inventory \n2. Don't add\n", 1, 2) };
//	if (choice == 1)
//	{
//		// add to inventory if there is room
//		if (Inventory::add(t))
//		{
//			Inventory::print();
//			return true;
//		}
//		// inventory is full
//		else
//		{
//			std::cout << "\nCan't add to inventory. Inventory already contains 5 items.\n";
//		}
//	}
//
//	return false;
//}

///********************************* addItem ************************************************
//This function adds an item to the hero's inventory. It dynamically allocates a copy of the Treasure
//object and adds it to the inventory.
//Arguments: Treasure pointer by reference
//Returns: void
//***************************************************************************************************/
//bool Inventory::addItem(Treasure*& t)
//{
//	if (inventory.size() < CAPACITY)
//	{
//		// make copy of treasure and add to inventory
//		Treasure* copy = new Treasure(*t);
//		inventory.push_back(copy);
//
//		return true;
//	}
//	else
//	{
//		return false;
//	}
//}

/********************************* add ***********************************************************
This function adds an item to the hero's inventory.
Arguments: Treasure pointer by reference
Returns: void
***************************************************************************************************/
void Inventory::add(std::unique_ptr<Treasure> t)
{
	std::unique_ptr<Treasure> treasure = std::move(t);
	inventory.push_back(std::move(treasure));
}


/********************************* deleteItem *****************************************************
This function removes an item in the inventory by its index.
Arguments: integer for position in vector
Returns: void
***************************************************************************************************/
void Inventory::deleteItem(const int position)
{
	inventory.at(position).reset();
	inventory.erase(inventory.begin() + position);
}

/********************************* hasKey *******************************************************
This function tests if the inventory contains a key.
Arguments: none
Returns: true if inventory contains a key, false if not
***************************************************************************************************/
bool Inventory::hasKey()
{
	for (std::vector<std::unique_ptr<Treasure>>::iterator it = inventory.begin(); it != inventory.end(); ++it)
	{
		if ((*it)->getType() == Type::key)
		{
			return true;
		}
	}

	return false;
}

/********************************* getItemPosition **************************************************
This function looks for an item in the inventory. If it is there, it returns its position in the
inventory vector, which will make using it easy.
Arguments: Type enum of type of item (e.g. Type::weapon)
Returns: position in vector, or -1 if not found 
***************************************************************************************************/
int Inventory::getItemPosition(Type t)
{
	// return position of item if in inventory
	for (size_t i = 0; i < inventory.size(); ++i)
	{
		if (inventory.at(i)->getType() == t)
		{
			return i;
		}
	}

	// index = -1 if item not in inventory 
	return -1;
}

/********************************* useHolyWater **************************************************
This function removes a holy water item from the inventory and returns how much HP it restores.
Arguments: integer for position in inventory
Returns: integer for amount of HP restored
***************************************************************************************************/
int Inventory::useHolyWater(int position)
{
	int hpRestored{ inventory.at(position)->getHPChange() };
	inventory.erase(inventory.begin() + position);

	return hpRestored;
}

/********************************* getters and setters  ************************************************/
int Inventory::getSize()
{
	return inventory.size();
}


Treasure* Inventory::getTreasure(const int position)
{
	return inventory.at(position).get();
}

std::unique_ptr<Treasure> Inventory::moveTreasure(const int position)
{
	std::unique_ptr<Treasure> t = std::move(inventory.at(position));
	inventory.erase(inventory.begin() + position);
	return std::move(t);
}

// returns true if inventory contains fewer than CAPACITY items (currently 5)
bool Inventory::notFull()
{
	if (inventory.size() < CAPACITY)
	{
		return true;
	}

	return false;
}

// returns true if inventory vector is empty
bool Inventory::isEmpty()
{
	if (inventory.size() == 0)
	{
		return true;
	}

	return false;
}