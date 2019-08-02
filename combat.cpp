/**************************************************************************************************
Program Name: Church of the Damned
File: combat.cpp
Author: Kirsten Corrao
***************************************************************************************************/
#include "combat.hpp"

/************************************ constructor ****************************************************
The constructor sets initializes hero to the player and sets enemy to the monster at the same location.
*****************************************************************************************************/
Combat::Combat(Character* h, Character* e)
	: hero{ h }, enemy{ e }, heroWeapon{ hero->getCurrentWeapon() }, heroWeaponDamage{ heroWeapon->getAttack() },
	heroArmor{ hero->getCurrentArmor() },heroArmorRating{ heroArmor->getDefense() },
	enemyWeapon{ enemy->getCurrentWeapon() }, enemyWeaponDamage{ enemyWeapon->getAttack() },
	enemyArmor{ enemy->getCurrentArmor() }, enemyArmorRating{ enemyArmor->getDefense() }
{
	// set inventories for hero and enemy
	inventory = hero->getInventory();
	enemyInv = enemy->getInventory();
}

/************************************ destructor ****************************************************
*****************************************************************************************************/
Combat::~Combat()
{
}

/************************************ fight *************************************************
Introducing new fighting system.
*****************************************************************************************************/
void Combat::fight()
{
	bool bothAlive{ true };
	
    while (bothAlive)
	{
		Combat::displayHPWeaponArmor();

		// hero attacks first (what about initiative system?)
	    Combat::heroAttacks();	

		// enemy attacks
		if (enemy->getHP() > 0)
		{
			Combat::displayHPWeaponArmor();	
            Combat::enemyAttacks();
		}

		// if hero is dead, check inventory for holy water (will revive hero)
		if (hero->getHP() <= 0)
		{
			int position{ inventory->getItemPosition(Type::holyWater) };

			// if holy water in inventory, use it and recover hero's HP
			if (position != -1)
			{
				int hpRecovered{ inventory->useHolyWater(position) };
				hero->recoverHP(hpRecovered);
				Combat::displayHolyWaterUsed(hpRecovered);
			}

			// otherwise hero dies
			else
			{
				std::cout << "\n" << hero->getName() << " has been defeated.\n";
				bothAlive = false;
			}
		}

		// if enemy is dead, combat is over
		else if (enemy->getHP() <= 0)
		{
			bothAlive = false;

			// hero can loot enemies that aren't final boss (lich cardinal)
			if (enemy->getType() != "Lich Cardinal")
			{
				Combat::lootBody();
			}
		}
	}

	Combat::displayWinner();
}

/************************************ heroAttacks  ***************************************************
Player chooses between a standard attack or special action. If they choose not to do a special action,
or don't have enough MP, then they must choose to do a standard attack. 
Parameters: none
Returns: void
*****************************************************************************************************/
void Combat::heroAttacks()
{
    bool stillChoosingAttack {true};

    while (stillChoosingAttack)
    {
        int choice{ utility::getInt("\n1. Standard attack \n2. Special action\n", 1, 2) };
        if (choice == 1)
        {
            Combat::standardAttack(hero, enemy, heroWeaponDamage, enemyArmorRating);
            stillChoosingAttack = false;
        }
        else if (choice == 2)
        {
            SpecialAction* actionChoice{ Combat::chooseSpecialAction(hero) };
            if (actionChoice != nullptr)
            {
                Combat::executeSpecialAction(hero, enemy, actionChoice);
                stillChoosingAttack = false;
            }
        }
    }
}

/************************************ enemyAttacks ***************************************************
The enemy has a 50% chance of doing a normal attack, and a 50% chance of doing a special action. If 
special action is randomly selected, and the enemy has enough MP, then that action is taken. Otherwise,
a normal attack is done.
Parameters: none
Returns: void
*****************************************************************************************************/
void Combat::enemyAttacks()
{
    int randomAttack{ utility::getRandInt(1, 2) };
    if (randomAttack == 1)
    {
        Combat::standardAttack(enemy, hero, enemyWeaponDamage, heroArmorRating);
    }
    else
    {
        std::cout << "\nEnemy executing special action and has " << enemy->getMana() << " MP.\n";
        SpecialAction* action{ Combat::randomSpecialAction(enemy) };
        if (action != nullptr)
        {
            Combat::executeSpecialAction(enemy, hero, action);
        }
        else
        {
            Combat::standardAttack(enemy, hero, enemyWeaponDamage, heroArmorRating);
        }
    }
}

/************************************ standardAttack ***************************************************

*****************************************************************************************************/
void Combat::standardAttack(Character* attacker, Character* defender, int weaponDamage, int armorRating)
{
	// see if attacker hits (must roll above defender's armor rating)
	int attack{ utility::getRandInt(1, chanceHit) };

	// attacker hits
	if (attack > armorRating)
	{
		// get attack roll, defense roll, and total damage
		int damage{ utility::getRandInt(1, weaponDamage) };

		// decrease damage from fighter 2's strength
		defender->decreaseHP(damage);

		// display all fight stats
		Combat::displayHit(attacker, attack, damage);
	}

	// attacker misses
	else
	{
		Combat::displayMissed(attacker, attack);
	}
}

/************************************ chooseSpecialAction ********************************************
The player can choose a special action, or press 0 to go back and choose a standard attack. If they 
choose an action for which they don't have enough MP, an error message is printed.
Parameters: Character pointer for the attacker (who is choosing an action)
Returns: pointer to SpecialAction object (null if they didn't choose an action)
*****************************************************************************************************/
SpecialAction* Combat::chooseSpecialAction(Character* attacker)
{
	SpecialAction* action{ nullptr };
	bool stillChoosingAction{ true };

	while (stillChoosingAction)
	{
		attacker->printSpecialActions();
		int choice{ utility::getInt("Choose special action (or 0 to go back): ", 0, attacker->getSpecialActionsSize()) };
		if (choice > 0)
		{
			action = attacker->getSpecialActionByIndex(choice - 1);

			if (attacker->getMana() < action->getManaRequired())
			{
				std::cout << "\nInsufficient mana to execute that action.";
			}
			else
			{

				stillChoosingAction = false;
			}
		}

        else if (choice == 0)
        {
			action = nullptr;
			stillChoosingAction = false;
        }
	}
	
	return action;
}
/************************************ executeSpecialAttack *******************************************
Executes special action according to its type (attack, defense, HP recovery, or MP recovery).
*****************************************************************************************************/
void Combat::executeSpecialAction(Character* attacker, Character* defender, SpecialAction* action)
{
	std::string attackerName;
	std::string defenderName;

	// set proper names to use in summary statements of special action
	if (attacker == hero)
	{
		attackerName = hero->getName();
		defenderName = enemy->getType();
	}
	else
	{
		attackerName = enemy->getType();
		defenderName = hero->getName();
	}

	switch (action->getActionType())
	{
		case ActionType::attack:
		{
			int damage{ utility::getRandInt(action->getMinDamage(), action->getMaxDamage()) };
			defender->decreaseHP(damage);
			std::cout << "\n" << attackerName << " uses " << action->getName() << " to inflict " << damage << " points of damage on " << defenderName;
			break;
		}
		case ActionType::defense:
		{
			int defenseIncrease{ action->getArmorIncrease() };
			if (attacker == hero)
			{
				heroArmorRating += defenseIncrease;
			}
			else
			{
				enemyArmorRating += defenseIncrease;
			}

			std::cout << "\n" << attackerName << " uses " << action->getName() << " to raise their defense rating by " << defenseIncrease;
			break;
		}
		case ActionType::HP:
		{
			int hpIncrease{ action->getHpRecovery() };
			attacker->recoverHP(hpIncrease);
			std::cout << "\n" << attackerName << " uses " << action->getName() << " to recover " << hpIncrease << " points of damage";
			break;
		}
		case ActionType::MP:
		{
			int manaRecovery{ action->getManaRecovery() };
			attacker->recoverMana(manaRecovery);
			std::cout << "\n" << attackerName << " uses " << action->getName() << " to recover " << manaRecovery << " points of mana";
			break;
		}
	}

	attacker->decreaseMana(action->getManaRequired());
	
}

/************************************ randomSpecialAction ******************************************
Generates vector of attacker's special actions, shuffles the vector, then goes through vector sequentially
and returns SpecialAction pointer if the attacker has enough mana to execute that action. If the attacker 
has insufficient mana for all actions, it returns null.
Parameters: Character* for whose actions to choose
Returns: SpecialAction* if sufficient mana to execute, null if not
*****************************************************************************************************/
SpecialAction* Combat::randomSpecialAction(Character* attacker)
{
	if (attacker->getMana() > 0)
	{
		int numActions{ attacker->getSpecialActionsSize() };
		std::vector<SpecialAction*> randomizedActions;

		// generate vector of special actions in order
		for (int i = 0; i < numActions; i++)
		{
			randomizedActions.push_back(attacker->getSpecialActionByIndex(i));
		}

		// shuffle vector
		std::random_device seed;
		std::shuffle(randomizedActions.begin(), randomizedActions.end(), std::default_random_engine(seed()));

		for (SpecialAction*& act : randomizedActions)
		{
			if (attacker->getMana() >= act->getManaRequired())
			{
				return act;
			}
		}
	}
	
	return nullptr;
}

/************************************ displayWinner **************************************************
This prints who won the combat (e.g. the hero or the enemy). It prints the hero's name or enemy's type.
Arguments: none
Returns: void
*****************************************************************************************************/
void Combat::displayWinner()
{
	std::cout << std::endl;

	// if hero won
	if (hero->getHP() > 0)
	{
		std::string heroWins{ hero->getName() + " WINS" };
		utility::printTitle(heroWins);
	}

	// if enemy won
	else
	{
		std::string enemyWins{ enemy->getType() + " WINS" };
		utility::printTitle(enemyWins);
	}
}

/************************************ displayMissed **************************************************
This prints that a Character missed their attack and what they rolled.
Arguments: Character* pointer, integer for attack roll
Returns: void
*****************************************************************************************************/
void Combat::displayMissed(Character*& c, int attack)
{
	if (c->getName() != "")	// hero 
	{
		std::cout << "\n" << c->getName() << " MISSES with an attack roll of " << attack << std::endl;
	}
	else    // enemy
	{
		std::cout << "\nThe " << c->getType() << " MISSES with an attack roll of " << attack << std::endl;
	}
}

/************************************ displayHit **************************************************
This prints that a Character hit their attack and what they rolled.
Arguments: Character* pointer, integer for attack roll, integer for damage roll
Returns: void
*****************************************************************************************************/
void Combat::displayHit(Character*& c, int attack, int damage)
{
	if (c->getName() != "")	// hero 
	{
		std::cout << "\n" << c->getName() << " HITS with an attack roll of " << attack 
			<< " and inflicts " << damage << " points of damage." << std::endl;
	}
	else    // enemy
	{
		std::cout << "\nThe " << c->getType() << " HITS with an attack roll of " << attack
			<< " and inflicts " << damage << " points of damage." << std::endl;
	}
}

/************************************ displayHPWeaponArmor ******************************************
This function displays the hero's name and HP; and the enemy's type and HP, in fancy-ish columns.
Arguments: none
Returns: void
*****************************************************************************************************/
void Combat::displayHPWeaponArmor()
{
	// hero and enemy HP
	std::cout << "\n------------------------------------------------------------------------------\n"
		<< std::setw(1) << "|"
		<< std::right << std::setw(17) << hero->getName()
		<< std::setw(7) << hero->getHP() << " HP"
        << std::setw(7) << hero->getMana() << " MP"
		<< std::setw(4) << "|";
	std::cout  
		<< std::right << std::setw(17) << enemy->getType()
		<< std::setw(6) << enemy->getHP() << " HP"
        << std::setw(6) << enemy->getMana() << " MP"
		<< std::setw(1) << "|";

	// hero and enemy weapons
	std::cout << "\n------------------------------------------------------------------------------\n"
		// hero weapon
		<< std::left << std::setw(10) << "Weapon |"
		<< std::setw(20) << heroWeapon->getName()
		<< std::setw(10) << heroWeapon->getAttack()
		<< std::setw(5) << " | ";
	std::cout
		<< std::left << std::setw(26) << enemyWeapon->getName()
		<< std::setw(4) << enemyWeapon->getAttack()
		<< std::setw(1) << "  |\n";

	// hero and enemy armor 
	std::cout
		<< std::left << std::setw(11) << "Armor  |"
		<< std::setw(19) << heroArmor->getName()
		<< std::setw(10) << heroArmor->getDefense()
		<< std::setw(5) << " |";
	std::cout
		<< std::left << std::setw(26) << enemyArmor->getName()
		<< std::setw(4) << enemyArmor->getDefense()
		<< std::setw(1) << "  |";
	std::cout << "\n------------------------------------------------------------------------------\n";
}

/************************************ displayHolyWaterUsed ******************************************
This function displays how much HP was recovered by using holy water.
Arguments: integer for amount HP restored by holy water
Returns: void
*****************************************************************************************************/
void Combat::displayHolyWaterUsed(int restoredHP)
{
	std::cout << "\nHoly water saved " << hero->getName() << " from the brink of death, "
		<< "restoring " << restoredHP << " hit points.\n";
}

/************************************ lootBody *******************************************************
This function lets the player loot the body of the enemy they just defeated. Looted items are moved
into the player's inventory.
Arguments: none
Returns: void
*****************************************************************************************************/
void Combat::lootBody()
{
	std::cout << "\nThe " << enemy->getType() << " has been defeated! Loot the body?\n";
	bool keepLooting{ true };

	// add item to hero's inventory
	while (keepLooting)
	{
		enemyInv->print();
		int choice{ utility::getInt("\nSelect an item to add to inventory, or 0 to take nothing: ", 0, enemyInv->getSize()) };

		// stop looting if hero is done or enemy inventory is empty
		if (choice == 0 || enemyInv->getSize() == 0)
		{
			keepLooting = false;
		}

		// add item from enemy inventory to hero's inventory, unless it's full
		else
		{
			std::unique_ptr<Treasure> loot{ enemyInv->moveTreasure(choice - 1) };
			if (inventory->notFull())
			{
				inventory->add(std::move(loot));
			}
			else
			{
				std::cout << "\nCan't loot. Inventory full.\n";
			}
		}
	}
}
