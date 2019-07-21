#ifndef SPECIALATTACK_HPP
#define SPECIALATTACK_HPP

#include "utility.hpp"

#include <string>

class SpecialAttack 
{
	private:
		std::string name;
		std::string description;
		int maxDamage;
	public:
		SpecialAttack(std::string n, std::string d, int maxD);
		~SpecialAttack();
};

#endif