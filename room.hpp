/***************************************************************************************************
Program name: Church of the Damned
File: Room.hpp
Author: Kirsten Corrao
Date: 07/12/2019
***************************************************************************************************/
#ifndef ROOM_HPP
#define ROOM_HPP

#include "character.hpp"
#include "tile.hpp"
#include "treasure.hpp"
#include "utility.hpp"

#include <iostream>
#include <memory>
#include <string>
#include <vector>

class Room
{
	public:
		Room(int rows, int cols, std::string name);
		virtual ~Room();					
		//virtual void setRoomConnections(Room* room1, Room* room2 = nullptr) = 0;
		void printRoom();
		virtual void printContents() = 0;
		virtual int moveCharacter(std::unique_ptr<Character>& c, char direction, Room*& currentRoom);
		//virtual Room* moveNewRoom(int row, int col) = 0;

		Treasure* getTreasure(int row, int col);
		std::unique_ptr<Treasure> moveTreasure(int row, int col);
		//Character* getMonster(int row, int col);
		//void setTileToEmpty(int row, int col);
		//void setTileToHero(int row, int col);
		//virtual void fillRoomMonsters();

		/**** getters and setters******/
		void setHeroRowCol(int r, int c);
		int getHeroRow();
		void setHeroRow(int r);
		int getHeroCol();
		void setHeroCol(int c);
		bool getBellRung();
		

	protected:		
		int roomRows;
		int roomCols;
		std::string name; 
		Tile** room;

		// keep track of hero's location
		int heroRow;
		int heroCol;

		// pointers for adjacent rooms  
		Room* north;
		Room* south;
		Room* east;
		Room* west;
		Room* above;
		Room* below;

		//// treasure 
		//std::unique_ptr<Treasure> treasure1;
		//std::unique_ptr<Treasure> treasure2;

		//// monsters
		//Character* monster1;
		//Character* monster2;
		//Character* monster3;
		//Character* monster4;
		//Character* monster5;
		//Character* monster6;

		//// move to Game? 
		bool bellRung;

		void makeBorders(int rows, int cols);
};

#endif
