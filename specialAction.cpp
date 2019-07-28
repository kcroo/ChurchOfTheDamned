/**************************************************************************************************
Program Name: Final Project
File: specialAttack.cpp
Author: Kirsten Corrao
***************************************************************************************************/

#include "specialAction.hpp"

/********************************* constructor ****************************************************

***************************************************************************************************/
SpecialAction::SpecialAction(ActionType t, std::string n, std::string d, int manaReq, int minD, int maxD, int armor, int hpRecov, int manaRecov)
	: type{ t }, name{ n }, description{ d }, manaRequired{ manaReq }, minDamage{ minD }, maxDamage{ maxD }, armorIncrease{ armor },
	hpRecovery{ hpRecov }, manaRecovery{ manaRecov }
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

int SpecialAction::getManaRequired()
{
	return manaRequired;
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
	return maxDamage;
}

int SpecialAction::getHpRecovery()
{
	return hpRecovery;
}

int SpecialAction::getManaRecovery()
{
	return manaRecovery;
}