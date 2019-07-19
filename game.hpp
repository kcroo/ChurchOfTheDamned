/**************************************************************************************************
Program Name: Final Project
File: Game.hpp
Author: Kirsten Corrao
Date: 03/05/2019
Description: this is the header file for Game class. The Game class implements other classes to play
the game. It has Room pointers for each room, which are used to dynamically allocate each room. An 
Inventory object manages the hero's inventory. The player is given an introduction to the game, then 
asked what their name is. The hero takes that name. Then the player moves the hero around the church,
fighting monsters and collecting items. The game ends when the hero's HP reaches 0 (without any more
holy water to revive them); or the hero defeats the lich cardinal.
***************************************************************************************************/

#ifndef GAME_HPP
#define GAME_HPP

#include <iomanip>
#include <iostream>
#include <string>
//#include "BellTower.hpp"
//#include "Character.hpp"
//#include "Combat.hpp"
//#include "Crypt.hpp"
//#include "DarkPriest.hpp"
//#include "Dungeon.hpp"
#include "fighter.hpp"
//#include "Gallery.hpp"
//#include "Inventory.hpp"
//#include "Mezzanine.hpp"
#include "sanctuary.hpp"
#include "room.hpp"
#include "utility.hpp"

#include <memory>

using std::unique_ptr;
using std::shared_ptr;
using std::weak_ptr;

class Game
{
	public:
		Game();
		~Game();
		void play();
		void move();
		//Room* getCurrentRoom();
		
	private:
		bool gameContinues;
		int turns;					// # turns so far 
		unique_ptr<Character> player;

		// rooms
		shared_ptr<Room> currentRoom;
		shared_ptr<Room> sanctuary;
		shared_ptr<Room> mezzanine;
		shared_ptr<Room> bellTower;
		shared_ptr<Room> gallery;
		shared_ptr<Room> dungeon;
		shared_ptr<Room> crypt;
		//void createRooms();
	
		// inventory management
		Inventory* inventory;
		//void chooseHero();
		void addTreasureToInv(int row, int col);
		//void manageInventory();
		//void removeItemInventory();
		//void equipWeaponOrArmor();
		//void drinkHolyWater();

		//// combat 
		//void combat();
		//void energyDrain();

		//// print
		//void printIntro();
		////Utility utility;		// many printing functions
};


#endif