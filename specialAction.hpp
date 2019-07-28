/**************************************************************************************************
Program Name: Final Project
File: specialAction.hpp
Author: Kirsten Corrao
***************************************************************************************************/

#ifndef SPECIALACTION_HPP
#define SPECIALACTION_HPP

#include "utility.hpp"

#include <string>

enum class ActionType { attack, defense, HP, mana };

class SpecialAction 
{
	private:
		ActionType type;
		std::string name;
		std::string description;
		int manaRequired;
		int minDamage;
		int maxDamage;
		int armorIncrease;
		int hpRecovery;
		int manaRecovery;
		

	public:
		SpecialAction(ActionType t, std::string n, std::string d, int manaReq, int minD, int maxD, int maxAr, int hp, int mana);
		~SpecialAction();
		ActionType getActionType();
		std::string getName();
		std::string getDescription();
		int getManaRequired();
		int getMinDamage();
		int getMaxDamage();
		int getArmorIncrease();
		int getHpRecovery();
		int getManaRecovery();
};

#endif