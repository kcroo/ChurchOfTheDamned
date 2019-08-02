/**************************************************************************************************
Program Name: Final Project
File: specialAttack.cpp
Author: Kirsten Corrao
***************************************************************************************************/

#include "specialAction.hpp"

/********************************* constructor ****************************************************

***************************************************************************************************/
SpecialAction::SpecialAction(ActionType t, std::string n, std::string d, int MPReq, int minD, int maxD, int armor, int hpRecov, int MPRecov)
	: type{ t }, name{ n }, description{ d }, MPRequired{ MPReq }, minDamage{ minD }, maxDamage{ maxD }, armorIncrease{ armor },
	hpRecovery{ hpRecov }, MPRecovered{ MPRecov }
{

}

/********************************* destructor *****************************************************

***************************************************************************************************/
SpecialAction::~SpecialAction()
{

}

// getters and setters 
ActionType SpecialAction::getActionType()
{
	return type;
}
std::string SpecialAction::getName()
{
	return name;
}

std::string SpecialAction::getDescription()
{
	return description;
}

int SpecialAction::getMPRequired()
{
	return MPRequired;
}

int SpecialAction::getMinDamage()
{
	return minDamage;
}

int SpecialAction::getMaxDamage()
{
	return maxDamage;
}

int SpecialAction::getArmorIncrease()
{
	return armorIncrease;
}

int SpecialAction::getHpRecovery()
{
	return hpRecovery;
}

int SpecialAction::getMPRecovered()
{
	return MPRecovered;
}