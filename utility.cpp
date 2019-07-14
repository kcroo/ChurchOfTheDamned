#include "utility.hpp"

namespace utility
{
	/************************************ validateInt **************************************************
This is an input validation function for integers. It takes a string as an argument,
It returns false if the string is empty, or if any character in the string is not a
digit (except for the first digit--it can be a negative sign). It returns true if every character is a
digit (except for an optional negative sign).

sources for input validation in general:
https://www.learncpp.com/cpp-tutorial/5-10-stdcin-extraction-and-dealing-with-invalid-text-input/
https://www.learncpp.com/cpp-tutorial/185-stream-states-and-input-validation/
how to use isdigit on a string:
https://www.programiz.com/cpp-programming/library-function/cctype/isdigit
*****************************************************************************************************/

	bool validateInt(const std::string& input)
	{
		bool validInt = true;

		// check if string is empty
		if (input.empty())
		{
			validInt = false;
			return validInt;
		}

		// make sure each character is a number (or first character is a negative sign)
		for (size_t i = 0; i < input.length(); i++)
		{
			if (!isdigit(input[i]))
			{
				if (i == 0 && input[i] == '-')
				{
					validInt = true;
				}
				else
				{
					validInt = false;
				}
			}
		}
		return validInt;
	}

	/************************************ validateDouble **************************************************
	This is an input validation function for doubles. It takes a string as an argument. It returns false
	if the string is empty or if any character in the string is not a digit, negative sign in the first
	digit, or a single decimal. Otherwise it returns true.
	Sources: see validateInt
	*****************************************************************************************************/
	bool validateDouble(const std::string& input)
	{
		bool validDouble = true;

		// check if string is empty
		if (input.empty())
		{
			validDouble = false;
			return validDouble;
		}

		// make sure each character is a number (or first character is a negative sign)
		int decimalCounter = 0;	// to count # of decimals in number
		for (size_t i = 0; i < input.length(); i++)
		{
			if (!isdigit(input[i]))
			{
				if (i == 0 && input[i] == '-')
				{
					validDouble = true;
				}
				else if (input[i] == '.')
				{
					decimalCounter++;
				}
				else
				{
					validDouble = false;
				}
			}
		}

		// make sure there's only 1 decimal in number
		if (decimalCounter > 1)
		{
			validDouble = false;
		}

		return validDouble;
	}

	/************************************ validateChar **************************************************
	This function validates that a character is in the defined set. It returns true if it is. It returns
	false if it is not in the set of allowed characters.
	*****************************************************************************************************/
	bool validateChar(const std::string& input)
	{
		// directions 
		if (input.length() == 1)
		{
			// north, east, south, west, or inventory
			if (input == "w" || input == "d" || input == "s" || input == "a" || input == "i" || input == "q")
			{
				return true;
			}
		}

		std::cout << "\nInvalid input.";
		return false;

		std::cin.clear();
		std::cin.ignore(100, '\n');
	}

	/************************************ getInt ********************************************************
	This is a menu function. It presents a menu and takes user input. It returns the user input as an
	integer. It takes three arguments: a string that presents the menu options; an integer that is the
	lowest menu option possible (usually 1); and an integer that is the highest menu option possible.
	This function can also be used to get any integer user input, where the minOptions and maxOptions
	represent the possible range of the input.

	sources for converting int to string:
	https://stackoverflow.com/questions/7663709/how-can-i-convert-a-stdstring-to-int
	https://www.geeksforgeeks.org/converting-strings-numbers-cc/
	***************************************************************************************************/
	int getInt(const std::string& menuOptions, const int& minValue, const int& maxValue, bool quitOption)
	{
		std::string choice = "";
		int num = 0;
		bool valid = true;

		// displays string at least once; displays again if invalid input
		do
		{
			// display menu and get input
			std::cout << menuOptions;
			std::getline(std::cin, choice);

			// if there is a quit option, let user enter q
			if (quitOption && choice == "q")
			{
				return 0;
			}

			// returns true if all characters in string are numbers
			valid = validateInt(choice);


			// display error message if input was not a number
			if (!valid)
			{
				std::cout << "Invalid entry. Please try again.\n";
			}
			else
			{
				// convert string to number
				num = std::stoi(choice);

				// display error message if entry invalid if above max or below min
				// menu will repeat after valid is set to false
				if (num < minValue || num > maxValue)
				{
					valid = false;
					std::cout << "Number out of range. Please try again.\n";
				}
			}
		} while (!valid);

		return num;
	}

	/********************************* getDouble *****************************************************
	This function gets and validates a double input from the user. It takes 3 arguments: a string, a
	double, and another double by reference. It displays the string to the user to prompt them for
	input, gets input, and makes sure it is a double between the min and max arguments. Once the
	number is validated, the function returns it as a double.
	**************************************************************************************************/
	double getDouble(const std::string& text, const double& min, const double& max)
	{
		bool invalidDouble = true;
		std::string input{ "" };
		double inputDouble{ 0.0 };

		while (invalidDouble)
		{
			std::cout << text;
			std::getline(std::cin, input);

			if (!validateDouble(input))
			{
				std::cout << "\nInvalid input.\n";
			}

			inputDouble = std::stod(input);
			if (inputDouble < min || inputDouble > max)
			{
				std::cout << "\nInput out of range.\n";
			}
			else
			{
				invalidDouble = false;
			}
		}

		return inputDouble;
	}

	/********************************* getString *****************************************************
	This function gets string input from the user. It validates that the string is not empty. It takes a
	string as an argument, which is displayed to the user. It returns the valid string that the user
	enters.
	**************************************************************************************************/
	std::string getString(const std::string& text, size_t maxLength)
	{
		bool validString{ false };
		std::string input;

		while (!validString)
		{
			std::cout << text;
			std::getline(std::cin, input);
			if (input.empty())
			{
				std::cout << "\nInvalid. Input cannot be empty.\n";
			}
			else if (input.length() > maxLength)
			{
				std::cout << "\nInvalid. Input was too long.\n";
			}
			else
			{
				validString = true;
			}
		}

		return input;
	}

	/********************************* getChar ********************************************************
	This function gets a character input from the user. If the character is in the allowed set, it
	returns the character. Otherwise, it keeps asking the user for input until they enter something valid.
	**************************************************************************************************/
	char getChar(const std::string& text)
	{
		bool validChar{ false };
		std::string input;

		while (!validChar)
		{
			std::cout << text;
			std::getline(std::cin, input);
			validChar = validateChar(input);
		}

		return input.at(0);
	}

	/********************************* pressEnter ******************************************************
	This function pauses the program until the user presses enter.
	Source: http://www.cplusplus.com/forum/articles/7312/
	**************************************************************************************************/
	void pressEnter()
	{
		std::cout << "\nPress enter to continue . . . \n";
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	}

	/********************************* getRandInt *****************************************************
	This function returns a random integer. It takes two integers as arguments: a minimum number for the
	lower bounds; and a maximum number for the upper bounds. These limits are inclusive.
	**************************************************************************************************/
	int getRandInt(int min, int max)
	{
		// seed to put into random number generator
		std::random_device seed;
		// Mersenne Twister 19937 random number generator
		std::mt19937 random(seed());
		// uniform distribution over required range (inclusive)
		std::uniform_int_distribution<int> makeRand(min, max);

		return makeRand(random);
	}

	/********************************* getRandFlaot **************************************************
	This function returns a random float. It takes two floats as arguments: a minimum number for the
	lower bounds; and a maximum number for the upper bounds. These limits are inclusive.
	**************************************************************************************************/
	double getRandDouble(double min, double max)
	{
		// seed to put into random number generator
		std::random_device seed;
		// Mersenne Twister 19937 random number generator
		std::mt19937 random(seed());
		// uniform distribution over required range (inclusive)
		std::uniform_real_distribution<> makeRand(min, max);

		return makeRand(random);
	}

	/********************************* again *********************************************************
	This function asks the user if they want to do something again. It takes one argument by reference:
	a string which is asked to the user. It returns true if the user wants to do it again. It returns
	false if they don't. This functin should be used to determine whether or not to repeat a while
	loop.
	**************************************************************************************************/
	bool again(std::string question)
	{
		// add menu options to question, then get user input
		question += "\n1. Yes \n2. No \n";
		int choice = getInt(question, 1, 2, false);

		// returns true if they want to do something again
		if (choice == 1)
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	/********************************* displayTextFile **********************************************
	This function displays whatever is in a text file. It takes a string as an argument for the file
	name. It then opens that file and displays it character by character.
	Sources for ASCI art:
	http://patorjk.com/software/taag/
	**************************************************************************************************/
	void displayTextFile(std::string fileName)
	{
		std::ifstream displayFile(fileName);
		char c{};

		while (!displayFile.eof())
		{
			displayFile.get(c);
			std::cout << c;
		}

		displayFile.close();
	}

	/********************************* printTitle ******************************************************
	This function takes a string as an argument and displays it in a box of asterisks. It adds spaces to
	either end of the string to make it easier to read.
	**************************************************************************************************/
	void printTitle(std::string title)
	{
		title = " " + title + " ";
		size_t titleLength = title.length();
		size_t starsEachSide = (78 - titleLength) / 2;

		std::cout << "\n" << std::string(78, '*') << std::endl;
		std::cout << std::string(starsEachSide, '*') << title << std::string(starsEachSide + 1, '*') << std::endl;
		std::cout << std::string(78, '*') << std::endl;
	}
}