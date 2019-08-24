/**************************************************************************************************
Program Name: Final Project
File: specialAction.hpp
Author: Kirsten Corrao
***************************************************************************************************/

#ifndef SPECIALACTION_HPP
#define SPECIALACTION_HPP

#include "utility.hpp"

#include <string>

enum class ActionType { attack, defense, HP, MP };

class SpecialAction 
{
	private:
		ActionType type;
		std::string name;
		std::string description;
		int MPRequired;
		int minDamage;
		int maxDamage;
		int armorIncrease;
		int hpRecovery;
		int MPRecovered;
		

	public:
		SpecialAction(ActionType t, std::string n, std::string d, int mpReq, int minD, int maxD, int maxAr, int hpRestored, int mpRestored);
		~SpecialAction();
		ActionType getActionType();
		std::string getName();
		std::string getDescription();
		int getMPRequired();
		int getMinDamage();
		int getMaxDamage();
		int getArmorIncrease();
		int getHpRecovery();
		int getMPRecovered();
};

#endif