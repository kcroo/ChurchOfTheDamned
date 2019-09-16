/**************************************************************************************************
Program Name: Church of the Damned
File: game.hpp
Author: Kirsten Corrao
Date: 09/13/2019
Description: this is the header file for Game class, which implements the game Church of the Damned.
The play function is a public function that runs the game. The premise of the game is that dark forces
have taken over a church, and the player must defeat them to save their village. To play, the player 
must enter their name. Then they move around the rooms in the church, collecting items and fighting
monsters. They must find a key to continue further into the church. In the crypt, they find the final
boss, the Lich King, whom they must defeat to win the game.
***************************************************************************************************/
#ifndef GAME_HPP
#define GAME_HPP

#include "bellTower.hpp"
#include "character.hpp"
#include "combat.hpp"
#include "crypt.hpp"
#include "dungeon.hpp"
#include "fighter.hpp"
#include "gallery.hpp"
#include "mezzanine.hpp"
#include "room.hpp"
#include "sanctuary.hpp"
#include "utility.hpp"

#include <iomanip>
#include <iostream>
#include <memory>
#include <string>

class Game
{
	public:
		Game();
		~Game();
		void play();
		
	private:
		bool gameContinues;
		bool exitGame;
		bool bellRung;
		int turns;	
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
		void move();
	
		// inventory management
		void chooseHeroName();
		void addTreasureToInv(int row, int col);
		void manageInventory();
		void removeItemInventory();
		void equipWeaponOrArmor();
		void eatSacramentalBread();
		void drinkSacramentalWine();

		// combat 
		void combat();
		void energyDrain();

		// print
		void printIntro();
		void printLegendAndStatus();

		void resetGame();
};

#endif