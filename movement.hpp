/***************************************************************************************************
Program name: Church of the Damned
File: movement.hpp
Author: Kirsten Corrao
Date: 09/15/2019
Description: this is an enum class for movement around the church. It is used in the Room class
moveCharacter function and in the Game class move function.
***************************************************************************************************/

#ifndef MOVEMENT_HPP
#define MOVEMENT_HPP

enum class Movement
{
	move, combat, treasure, lockedDoor, stairsOrDoor, ringBell, invalid
};

#endif