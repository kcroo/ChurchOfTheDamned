/***************************************************************************************************
Program name: Final Project
File: Utility.cpp
Author: Kirsten Corrao
Date: 03/04/2019
Description: this is the header file for the Utility class. Utility objects are used to
implement common utility functions. These include functions to validate an integer; validate a string;
validate a double; display a menu and get user input; get a double input from user; get a string
input from user; produce a random integer; produce a random double; display the contents of a text
file (typically for a program main title); and several functions to print columns of different types
of data. All functions are public, since they are to be used in other classes/programs.
***************************************************************************************************/
#ifndef UTILITY_HPP
#define UTILITY_HPP

#include <fstream>
#include <iomanip>
#include <iostream>
#include <limits>
#include <random>
#include <string>

namespace utility
{
	// validation functions
	bool validateInt(const std::string& input);
	bool validateDouble(const std::string& input);
	bool validateChar(const std::string& input);

	// get user input
	int getInt(const std::string& menuOptions, const int& min, const int& max, bool quitOption = false);
	double getDouble(const std::string& menuOptions, const double& min, const double& max);
	std::string getString(const std::string& menuOptions, size_t maxLength);
	char getChar(const std::string& menuOptions);

	void pressEnter();
	int getRandInt(int min, int max);
	double getRandDouble(double min, double max);
	bool again(std::string question);

	// printing functions
	void displayTextFile(std::string fileName);
	void printTitle(std::string title);

	/*********************** Template Functions ***********************************/
// source: https://stackoverflow.com/questions/8752837/undefined-reference-to-template-class-constructor

/********************************* printColumns (template, 2 values) ******************************
This function uses a template and takes 4 values to print in columns.
Source: https://stackoverflow.com/questions/972152/how-to-create-a-template-function-within-a-class-c
**************************************************************************************************/
	template <class T1, class T2>
	void printColumns(T1 val1, T2 val2)
	{
		std::cout << std::left
			<< std::setw(15) << val1
			<< std::setw(10) << val2
			<< std::endl;
	}

	/********************************* printColumns (template, 3 values) ******************************
	This function uses a template and takes 3 values to print in columns.
	**************************************************************************************************/
	template <class T1, class T2, class T3>
	void printColumns(T1 val1, T2 val2, T3 val3)
	{
		std::cout << std::left
			<< std::setw(10) << val1
			<< std::setw(15) << val2
			<< std::setw(10) << val3
			<< std::endl;
	}

	/********************************* printColumns (template, 4 values) ******************************
	This function uses a template and takes 4 values to print in columns.
	**************************************************************************************************/
	template <class T1, class T2, class T3, class T4>
	void printColumns(T1 val1, T2 val2, T3 val3, T4 val4)
	{
		std::cout << std::left
			<< std::setw(10) << val1
			<< std::setw(15) << val2
			<< std::setw(10) << val3
			<< std::setw(10) << val4
			<< std::endl;
	}

	/********************************* printLegend (template, 4 values) ******************************
	This function uses a template and takes 4 values to print in columns.
	**************************************************************************************************/
	template <class T1, class T2, class T3, class T4>
	void printLegend(T1 val1, T2 val2, T3 val3, T4 val4)
	{
		std::cout << std::left
			<< std::setw(25) << val1
			<< std::setw(25) << val2
			<< std::setw(25) << val3
			<< std::setw(25) << val4
			<< std::endl;
	}

	/********************************* printLegend (template, 5 values) ******************************
	This function uses a template and takes 5 values to print in columns.
	**************************************************************************************************/
	template <class T1, class T2, class T3, class T4, class T5>
	void printLegend(T1 val1, T2 val2, T3 val3, T4 val4, T5 val5)
	{
		std::cout << std::left
			<< std::setw(25) << val1
			<< std::setw(25) << val2
			<< std::setw(25) << val3
			<< std::setw(25) << val4
			<< std::setw(25) << val5
			<< std::endl;
	}

	/********************************* printStatus (template, 4 values) ******************************
	This function uses a template and takes 4 values to print in columns.
	**************************************************************************************************/
	template <class T1, class T2, class T3, class T4>
	void printStatus(T1 val1, T2 val2, T3 val3, T4 val4)
	{
		std::cout << std::left
			<< std::setw(15) << val1
			<< std::setw(10) << val2
			<< std::setw(20) << val3
			<< std::setw(20) << val4
			<< std::endl;
	}

	/********************************* printColumns (template, 5 values) ******************************
	This function uses a template and takes 4 values to print in columns.
	**************************************************************************************************/
	template <class T1, class T2, class T3, class T4, class T5>
	void printColumns(T1 val1, T2 val2, T3 val3, T4 val4, T5 val5)
	{
		std::cout << std::left
			<< std::setw(10) << val1
			<< std::setw(15) << val2
			<< std::setw(10) << val3
			<< std::setw(10) << val4
			<< std::setw(10) << val5
			<< std::endl;
	}
}


#endif
