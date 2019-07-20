/**************************************************************************************************
Program Name: Final Project
File: Game.cpp
Author: Kirsten Corrao
Date: 03/05/2019
Description: this is the implementation file for Game class. The Game class implements other classes to play
the game. It has Room pointers for each room, which are used to dynamically allocate each room. An
Inventory object manages the player's inventory. The player is given an introduction to the game, then
asked what their name is. The player takes that name. Then the player moves the player around the church,
fighting monsters and collecting items. The game ends when the player's HP reaches 0 (without any more
holy water to revive them); or the player defeats the lich cardinal.
***************************************************************************************************/
#include "Game.hpp"
#include <assert.h>


/********************************* constructor *****************************************************
The constructors initializes all member variables.
***************************************************************************************************/
Game::Game()
	: gameContinues{ true }, turns{ 1 }, hero{ nullptr } /*currentRoom{ nullptr }, sanctuary{ nullptr },
	mezzanine{ nullptr }, bellTower{ nullptr }, gallery{ nullptr }, dungeon{ nullptr }, crypt{ nullptr },
	inventory{ nullptr }*/
{
	
}

/********************************* destructor *****************************************************
This is the Game class destructor. It deletes all dynamically allocated data and sets their pointers
to null.
***************************************************************************************************/
Game::~Game()
{
	/*delete player;
	hero = nullptr;
	currentRoom = nullptr;
	delete sanctuary;
	sanctuary = nullptr;
	delete mezzanine;
	mezzanine = nullptr;
	delete bellTower;
	bellTower = nullptr;
	delete gallery;
	gallery = nullptr;
	delete dungeon;
	dungeon = nullptr;
	delete crypt;
	crypt = nullptr;*/
}

///********************************* createRooms ******************************************************
// This function creates all rooms in the church.
//Arguments: none
//Returns: void
//***************************************************************************************************/
//void Game::createRooms()
//{
//	// create Room objects for rooms
//	sanctuary = new Sanctuary();
//	mezzanine = new Mezzanine();		
//	bellTower = new BellTower();
//	gallery = new Gallery();
//	dungeon = new Dungeon();
//	crypt = new Crypt();
//
//	// create connections between rooms
//	sanctuary->setRoomConnections(mezzanine, gallery);
//	mezzanine->setRoomConnections(sanctuary, bellTower);
//	bellTower->setRoomConnections(mezzanine);
//	gallery->setRoomConnections(sanctuary, dungeon);
//	dungeon->setRoomConnections(gallery, crypt);
//	crypt->setRoomConnections(dungeon);
//}
//
/********************************* play ********************************************************
This function is the game's start menu. It lets the user start a new game, read instructions, or exit.
Arguments: none
Returns: void
***************************************************************************************************/
void Game::play()
{
	//utility::displayTextFile("title.txt");

	sanctuary = std::make_unique<Sanctuary>();
	currentRoom = sanctuary.get();
	hero = std::make_unique<Fighter>("Hugo");
	inventory = hero->getInventory();

	while (gameContinues)
	{
		currentRoom->printRoom();
		Game::move();
		
		//int choice{ utility::getInt("\n1. Play game \n2. Exit\n", 1, 2) };

		//switch (choice)
		//{
		//	case 1:
		//	{
		//		Game::printIntro();
		//		Game::chooseHero();							// user chooses player name

		//		Game::createRooms();
		//		currentRoom = sanctuary;
		//		currentRoom->printContents();				// prints intro to room

		//		while (gameContinues)
		//		{
		//			currentRoom->printRoom();
		//			Game::energyDrain();					// drains 1 HP every 5 turns
		//			Game::move();
		//			++turns;
		//		}
		//		break;
		//	}

		//	case 2:
		//	{
		//		gameContinues = false;
		//		break;
		//	}
		// }
	}
}

///********************************* chooseHero *****************************************************
//This function lets the user choose their player's name. It then dynamically creates the Character
//object and sets it to player.
//Arguments: none
//Returns: void
//***************************************************************************************************/
//void Game::chooseHero()
//{
//	std::string heroName{ utility::getString("\nWhat is your name?\n", 10) };
//	hero = new Fighter(heroName);
//	inventory = hero->getInventory();
//}
//
/********************************* move ************************************************************
This function lets the player move their character. It prints the possible inputs the user can do, 
then gets user input. It moves the player around the room, fights enemies, gets treasure, tries to 
open doors, goes up or down stairs, manages the inventory, or exits the game.
Arguments: none
Returns: void
***************************************************************************************************/
void Game::move()
{
	std::cout << "\nLEGEND\n";
	utility::printLegend("H - hero", "T - treasure", "s - stairs", "d - door", "D - Dark Priest");
	utility::printLegend("C - Zombie Choir Boy", "O - Corrupted Ghost", "G - Ghoul Tormenter", "L - Lich Cardinal");
	
	Treasure* currentWeapon{ hero->getCurrentWeapon() };
	Treasure* currentArmor{ hero->getCurrentArmor() };

	std::cout << "\nSTATUS\n";
	utility::printStatus("Name", "HP", "Weapon", "Armor");
	utility::printStatus(hero->getName(), hero->getHP(), currentWeapon->getName(), currentArmor->getName());

	std::cout << "\nMOVEMENT\n"
		<< "w - up    s - down    d - right    a - left    i - inventory    q - quit";

	std::cout << "\n***********************************************************************************************\n";

	char direction = utility::getChar("\nYour move: ");

	// manage inventory
	if (direction == 'i')
	{
		Game::manageInventory();
	}

	// quit game
	else if (direction == 'q')
	{
		gameContinues = false;
	}

	// move around room
	else
	{
		int action = currentRoom->moveCharacter(hero, direction, currentRoom);		// updates playerRow and playerCol

		int currentRow{ currentRoom->getHeroRow() };
		int currentCol{ currentRoom->getHeroCol() };

		switch (action)
		{
			case 1:		// moved into empty tile 
			{
				break;
			}
			case 2:		// monster
			{
				//Game::combat();					// sets gameContinues to false if player loses or beats lich cardinal
				break;
			}

			case 3:		// treasure
			{
				Game::addTreasureToInv(currentRow, currentCol);
				break;
			}
			case 4:		// door is locked
			{
				//// door to outside of church in sanctuary is always locked
				//if (currentRoom == sanctuary && currentRow == 7)
				//{
				//	std::cout << "\nDark forces have barred the door, preventing your escape."
				//		<< "\nYou must find another way out of the church.";
				//}

				//// if player has key, change rooms
				//else if (inventory->hasKey())
				//{
				//	currentRoom = currentRoom->moveNewRoom(currentRow, currentCol);
				//	currentRoom->printContents();
				//}

				//// if player doesn't have key, display error
				//else
				//{
				//	std::cout << "\nThe door is locked. You must find the key to open it.\n";
				//}
				break;
			}
			case 5:		// move to new room
			{
				//currentRoom = currentRoom->moveNewRoom(currentRow, currentCol);

				//// if room is sanctuary and the hero rung the bell in the bell tower, fill it with monsters
				//if (currentRoom == sanctuary && bellTower->getBellRung())
				//{
				//	currentRoom->fillRoomMonsters();
				//}

				//currentRoom->printContents();
				break;
			}
			case 6:		// invalid move
			{
				std::cout << "\nInvalid move. Try again.\n";
				break;
			}
		}
	}
}


/************************************ addTreasureToInv ***********************************************
This function adds new treasure to the Charactor's inventory.
Parameters: none
Returns: void
*****************************************************************************************************/
void Game::addTreasureToInv(int row, int col)
{
	Treasure* treasure{ currentRoom->getTreasure(row, col) };
	
	std::cout << "\nYou have found a " << treasure->getName() << "!\n\n";
	
	// print treasure stats and current inventory
	treasure->print();
	std::cout << "\nYour inventory: " << std::endl;
	inventory->print();

	// ask player to add treasure to inventory
	int choice{ utility::getInt("\n1. Add to inventory \n2. Don't add\n", 1, 2) };
	if (choice == 1)
	{
		// add to inventory if there is room
		if (inventory->notFull())
		{
			std::unique_ptr<Treasure> t = currentRoom->moveTreasure(row, col);
			inventory->add(std::move(t));
			//currentRoom->setTileToHero(row, col);
			inventory->print();
		}
		// inventory is full
		else
		{
			std::cout << "\nCan't add to inventory. Inventory already contains 5 items.\n";
		}
	}
}

/************************************ manageInventory ***********************************************
This function lets the user remove items from inventory and equip other equipment.
Parameters: none
Returns: void
*****************************************************************************************************/
void Game::manageInventory()
{
	bool keepManagingInv{ true };
	while (keepManagingInv)
	{
		inventory->print();

		int choice{ utility::getInt("\n1. Remove item from inventory \n2. Equip weapon/armor \n3. Drink holy water \n4. Exit\n", 1, 4) };
		switch (choice)
		{
			case 1:
			{
				Game::removeItemInventory();
				break;
			}
			case 2:
			{
				Game::equipWeaponOrArmor();
				break;
			}
			case 3:
			{
				//Game::drinkHolyWater();
				break;
			}
			case 4: 
			{
				keepManagingInv = false;
				break;
			}
		}
	}
}

/************************************ removeItemInventory ********************************************
This function lets the user remove an item from the inventory. If the inventory is empty, it shows 
an error message.
Parameters: none
Returns: void
*****************************************************************************************************/
void Game::removeItemInventory()
{
	if (inventory->isEmpty())
	{
		std::cout << "\nInventory is empty.";
	}
	else
	{
		bool notDone{ true };

		while (notDone)
		{
			// display inventory
			inventory->print();

			int choice{ utility::getInt("\nItem number to remove (or 0 for none): ", 0, inventory->getSize()) };

			// doesn't want to remove item
			if (choice == 0)
			{
				notDone = false;
			}

			// remove item (unless it is current weapon or armor)
			else
			{
				if (!inventory->deleteIfNotCurrent(choice - 1, hero->getCurrentWeapon(), hero->getCurrentArmor()))
				{
					std::cout << "\nError. Cannot remove current weapon or armor.\n";
				}
			}
		}
	}
}

/************************************ equipTreasure ***********************************************
This function asks the user if they want to equip a treasure item. They can only equip
one weapon and one armor at at time.
Parameters: none
Returns: void
Source for pointer equality: https://stackoverflow.com/questions/9086372/how-to-compare-pointers
*****************************************************************************************************/
void Game::equipWeaponOrArmor()
{
	bool notDone{ true };

	while (notDone)
	{
		// print currently equipped weapon and armor and inventory
		hero->printWeaponAndArmor();
		inventory->print();

		int choice = utility::getInt("\nItem # to equip (or 0 to exit): ", 0, inventory->getSize());

		if (choice == 0)
		{
			notDone = false;
		}
		else
		{
			// get treasure from index user specified
			Treasure* item{ inventory->getTreasure(choice - 1) };

			// if item can't be equipped, print error
			if (!hero->equipItem(item))
			{
				std::cout << "\nError: item is not a weapon or armor.\n";
			}
		}
	}
}

///************************************ drinkHolyWater *******************************************************
//This function finds the first holy water in the inventory and has the player drink it. The player recovers 
//how many HP the holy water item specifies.
//Parameters: none
//Returns: void
//*****************************************************************************************************/
//void Game::drinkHolyWater()
//{
//	int position{ inventory->getItemPosition(Type::holyWater) };
//
//	// drink holy water if it's in inventory
//	if (position != -1)
//	{
//		int hpRecovered{ inventory->useHolyWater(position) };
//		hero->recoverHP(hpRecovered);
//		std::cout << "\n" << hero->getName() << " drank holy water, restoring " << hpRecovered << " HP.\n";
//	}
//
//	// display error
//	else
//	{
//		std::cout << "\nError. Inventory does not contain holy water.\n";
//	}
//}
//
///************************************ combat ********************************************************
//This function is used when the player enters a tile with an enemy. It creates a Combat object, which
//is then used to have them fight. If the player dies in combat, then the game is over.
//Parameters: none
//Returns: void
//*****************************************************************************************************/
//void Game::combat()
//{
//	// get enemy in player's tile and create combat object to start combat
//	Character* enemy{ currentRoom->getMonster(currentRoom->getHeroRow(), currentRoom->getHeroCol()) };
//	Combat combat(hero, enemy, inventory);
//	combat.fightRound();
//
//	// print victory message if player wins fight against lich cardinal
//	if (hero->getHP() != 0 && enemy->getType() == "Lich Cardinal")
//	{
//		gameContinues = false;
//		std::cout << "\nVICTORY! " << hero->getName() << " has defeated the LICH CARDINAL."
//			<< "\nHis agonizing scream fades into the darkness, leaving behind a bland copper medallion."
//			<< "\nAs you make your way out of the church, the unwordly creatures you saw before have vanished--"
//			<< "\nexcept for the whispered \"THANK YOU\" you hear as you pass where the GHOSTS of your"
//			<< "\nfellow villagers had once been trapped. The stained glass of the SANCTUARY has cleared,"
//			<< "\nrevealing the saints smiling down on you. You exit the church, confident in the fact"
//			<< "\nthat the LICH CARDINAL will not return."
//			<< "\n\nBut little do you know that the innocuous copper medallion you had seen in the crypt"
//			<< "\nholds the very last of the LICH CARDINAL's power. It may take years, centuries, or"
//			<< "\nmillenia, but he will return. Then once again, a player will have to rise against the"
//			<< "\nCHURCH OF THE DAMNED.\n\n";
//	}
//
//	// print defeat message if player dies fighting lich cardinal
//	else if (hero->getHP() == 0 && enemy->getType() == "Lich Cardinal")
//	{
//		gameContinues = false;
//		std::cout << "\nDEFEAT. The LICH CARDINAL has slain " << hero->getName() << ". You hear the"
//			<< "\nLICH CARDINAL's cackling as your consciousness fades. You succumb to the darkness,"
//			"\nknowing that your fate will be the same as the other poor souls you found in the church."
//			"\nYou hope that another player will rise to rescue your body from the CHURCH OF THE DAMNED.\n\n";
//	}
//
//	// print different defeat message if player dies fighting other monster
//	else if (hero->getHP() == 0)
//	{
//		gameContinues = false;
//		std::cout << "\nYou collapse to the ground, dying, as the evil spectres of the church surround you."
//			<< "\nYou hope for a quick end, but you're sure it will be anything but. You become another"
//			<< "\nvictim of the CHURCH OF THE DAMNED.\n\n";
//	}
//}
//
///************************************ energyDrain ****************************************************
//This function causes the player to lose 1 HP every 5 turns due to the evil energy in the church. If this
//causes the player to have 1 HP, the game is over. This happens even if the player has holy water in their
//inventory.
//Parameters: none
//Returns: void
//*****************************************************************************************************/
//void Game::energyDrain()
//{
//	// every 5 turns
//	if (turns % 5 == 0)
//	{
//		// player loses 1 HP
//		hero->decreaseHP(1);
//
//		// if the energy drained the player's last HP
//		if (hero->getHP() == 0)
//		{
//			// revive player with holy water, if they have any
//			int position{ inventory->getItemPosition(Type::holyWater) };
//
//			if (position != -1)
//			{
//				int hpRecovered{ inventory->useHolyWater(position) };
//				hero->recoverHP(hpRecovered);
//				std::cout << "\nThe church's evil energy drained " << hero->getName() << "'s last health,"
//					<< "\nbut holy water in the inventory saved them.\n\n";
//			}
//
//			// otherwise player dies
//			else
//			{
//				std::cout << "\nThe church's evil energy has drained " << hero->getName() << "'s last remaining HP!"
//					<< "\nThe hero is dead. The last thing you hear is the cackling of the LICH CARDINAL in your ear."
//					<< "\nMay God have mercy on your soul, for the CHURCH OF THE DAMNED will give you none.\n";
//				gameContinues = false;
//			}
//		}
//
//		// display that player lost 1 HP
//		else
//		{
//			std::cout << "\nThe church's evil energy has drained 1 HP from " << hero->getName() << std::endl;
//		}
//	}
//}
//
///************************************ printIntro ****************************************************
//This function prints an introduction to the game, including who the player is and what their quest is.
//It waits to continue until the user presses enter
//Parameters: none
//Returns: void
//*****************************************************************************************************/
//void Game::printIntro()
//{
//	std::cout << "\n***********************************************************************************************\n"
//		<< "\nYou are a villager, whose home has recently come under attack by evil inhabitants of a DAMNED CHURCH."
//		<< "\nYou have made it your solemn task to clear the church of the LICH CARDINAL and his followers."
//		<< "\nArmed with only a wooden mallet, you have arrived in the SANCTUARY of the church,"
//		<< "\neager to find and kill the LICH CARDINAL however you can. Only then will the church--"
//		<< "\nand your village--be free of his influence.";
//
//	std::cout << "\n\nMark your progress on the map, where your position is displayed with an H."
//		<< "\nMove around the church using w (north), s (south), d (east), or a (west). Doors in the"
//		<< "\nchurch are marked with d, while stairs are s. T marks Rooms that contain TREASURE."
//		<< "\nIf the dread and horror are too much for you, press q to quit.";
//
//	std::cout << "\n\nBe cautious, for various types of MONSTERS lurk around the church, marked with different"
//		<< "\nletters on the map. Identify them by the LEGEND on the bottom of the map."
//		<< "\nBe sure to take whatever treasure you find and LOOT enemies whom you defeat--"
//		<< "\nthey may have items you find useful in your quest.";
//
//	std::cout << "\n\nTo manage your INVENTORY, press i while on the map. You can remove items, equip different "
//		<< "\nweapons and armor, or drink holy water to revive hit points. Remove items that you do not need, for"
//		<< "\nyour inventory can only carry FIVE items. Holy water will be used automatically when your HP drops"
//		<< "\nto zero.";
//
//	std::cout << "\n\nBeware--already, you feel the LICH CARDINAL's demonic power slowly sapping your health. You"
//		<< "\nwill lose 1 HP every 5 turns while inside the church and within the LICH's clutches.";
//
//	std::cout << "\n\nYou are now prepared for your quest. May God have mercy on your soul.\n"
//		<< "\n********************************************************************************************f***\n";
//
//	utility::pressEnter();
//}
//
///************************************ getters and setters *********************************************/
//Room* Game::getCurrentRoom()
//{
//	return currentRoom;
//}