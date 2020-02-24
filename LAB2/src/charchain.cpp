// Matthew Ruiz
#include <iostream>
#include "LinkedChar.h"

// function declarations
void userDisplay();
void userOptions();

int main() 
{
    userOptions();
	return 0;
}

// function definitions
void userDisplay()
{
	std::cout << "LinkedChar Menu\n\n";
	std::cout << "[1] Get length of current LinkedChar\n";
	std::cout << "[2] Find index of char in LinkedChar\n";
	std::cout << "[3] Append AppendLinkedChar to LinkedChar\n";
	std::cout << "[4] Test if SubLinkedChar is a submatch of LinkedChar\n";
	std::cout << "[5] Exit\n\n";
}

void userOptions()
{
	std::string newString;
	std::cout << "Enter a string and convert to LinkedChar: ";
	std::getline(std::cin, newString);
	std::cout << "\n";
	LinkedChar lcCurrent(newString);
	int choice = 0;
	while (choice != 5)
	{
		userDisplay();
		lcCurrent.display();
		std::cout << "\n\nEnter selection [1-5]: ";
		std::cin >> choice;
		std::cout << "\n";
		if (choice == 1)
			std::cout << "Length of LinkedChar: " << lcCurrent.length() << "\n\n";
		else if (choice == 2)
		{
			char charSearch;
			std::cout << "Enter char to search for: ";
			std::cin >> charSearch;
			std::cout << "\nIndex of char in LinkedChar (starting from 0): " 
                << lcCurrent.index(charSearch) << "\n\n";
		}
		else if (choice == 3)
		{
			std::string appendString;
			std::cout << "Enter AppendLinkedChar and append to LinkedChar: ";
			std::cin.ignore();
			std::getline(std::cin, appendString);
			LinkedChar lcAppend(appendString);
			lcCurrent.append(lcAppend);
			std::cout << "\n";
			lcCurrent.display();
			std::cout << "\n\n";
		}
		else if (choice == 4)
		{
			std::string subString;
			std::cout << "Enter SubLinkedChar and search for match in LinkedChar: ";
			std::cin.ignore();
			std::getline(std::cin, subString);
			LinkedChar lcSub(subString);
			std::cout << "\nSubLinkedChar found in LinkedChar: ";
			if (lcCurrent.submatch(lcSub))
				std::cout << "TRUE\n\n";
			else
				std::cout << "FALSE\n\n";
		}
	}
}
