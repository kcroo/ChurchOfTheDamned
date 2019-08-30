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
#include "bellTower.hpp"
#include "character.hpp"
#include "combat.hpp"
#include "crypt.hpp"
#include "darkPriest.hpp"
#include "dungeon.hpp"
#include "fighter.hpp"
#include "gallery.hpp"
#include "mezzanine.hpp"
#include "sanctuary.hpp"
#include "room.hpp"
#include "utility.hpp"

#include <memory>

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
		std::unique_ptr<Character> hero;

		// rooms
		Room* currentRoom;
		std::unique_ptr<Room> sanctuary;
		std::unique_ptr<Room> mezzanine;
		std::unique_ptr<Room> bellTower;
		std::unique_ptr<Room> gallery;
		std::unique_ptr<Room> dungeon;
		std::unique_ptr<Room> crypt;
		void createRooms();
	
		// inventory management
		//void chooseHero();
		void addTreasureToInv(int row, int col);
		void manageInventory();
		void removeItemInventory();
		void equipWeaponOrArmor();
		void eatSacramentalBread();
		void drinkSacramentalWine();

		//// combat 
		void combat();
		void energyDrain();

		//// print
		//void printIntro();
};


#endif
