/**************************************************************************************************
Program Name: Final Project
File: Inventory.hpp
Author: Kirsten Corrao
Date: 03/05/2019
Description: this is the implementation file of the Inventory class. This class makes managing the 
hero or enemy's inventory easier. These functions initialize the inventory to a Character's 
Treasure pointer vector; print the inventory's contents; ask the user to add treasure they've found;
add an item to their inventory; delete an item; check if the user has a key; use holy water to 
restore HP; and check if the user has any of a certain item (usually used with holy water).
***************************************************************************************************/

#ifndef INVENTORY_HPP
#define INVENTORY_HPP

#include "treasure.hpp"
#include "utility.hpp"

#include <array>
#include <memory>
#include <vector>

class Inventory
{
private:
	static const int CAPACITY = 5;					// maximum # of items in inventory
	std::vector<std::unique_ptr<Treasure>> inventory;
	//std::array<std::unique_ptr<Treasure>, CAPACITY> inv;

public:
	Inventory();
	~Inventory();
	//void initialize(std::vector<Treasure*> inv);
	void print();

	//bool foundTreasure(std::unique_ptr<Treasure> t);
	//bool addItem(Treasure*& t);
	void add(std::unique_ptr<Treasure> t);
	bool deleteIfNotCurrent(int position, Treasure* currentW, Treasure* currentA);
	void deleteItem(int position);

	//bool hasKey();
	//int getItemPosition(Type t);
	//int useHolyWater(int position);

	int getSize();
	Treasure* getTreasure(int position);
	std::vector<std::unique_ptr<Treasure>>* getInventory();
	bool notFull();
	bool isEmpty();
};

#endif