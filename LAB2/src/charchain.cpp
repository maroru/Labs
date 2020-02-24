#include <iostream>
#include "LinkedChar.h"

void menuDisplay()
{
	std::cout << "LinkedChar Menu\n\n";
	std::cout << "[1] Get length of current LinkedChar\n";
	std::cout << "[2] Find index of char in LinkedChar\n";
	std::cout << "[3] Append AppendLinkedChar to LinkedChar\n";
	std::cout << "[4] Test if SubLinkedChar is a submatch of LinkedChar\n";
	std::cout << "[5] Exit\n\n";
}

int main() 
{
	std::string newstring;
	std::cout << "Enter a string and convert to LinkedChar: ";
	std::getline(std::cin, newstring);
	std::cout << "\n";
	LinkedChar currentlc(newstring);
	int choice = 0;
	while (choice != 5)
	{
		menuDisplay();
		currentlc.display();
		std::cout << "\n\nEnter selection [1-5]: ";
		std::cin >> choice;
		std::cout << "\n";
		if (choice == 1)
			std::cout << "Length of LinkedChar: " << currentlc.length() << "\n\n";
		else if (choice == 2)
		{
			char charsearch;
			std::cout << "Enter char to search for: ";
			std::cin >> charsearch;
			std::cout << "\nIndex of char in LinkedChar (starting from 0): " << currentlc.index(charsearch) << "\n\n";
		}
		else if (choice == 3)
		{
			std::string appendstring;
			std::cout << "Enter AppendLinkedChar and append to LinkedChar: ";
			std::cin.ignore();
			std::getline(std::cin, appendstring);
			LinkedChar appendlc(appendstring);
			currentlc.append(appendlc);
			std::cout << "\n";
			currentlc.display();
			std::cout << "\n\n";
		}
		else if (choice == 4)
		{
			std::string substring;
			std::cout << "Enter SubLinkedChar and search for match in LinkedChar: ";
			std::cin.ignore();
			std::getline(std::cin, substring);
			LinkedChar sublc(substring);
			std::cout << "\nSubLinkedChar found in LinkedChar: ";
			if (currentlc.submatch(sublc))
				std::cout << "TRUE\n\n";
			else
				std::cout << "FALSE\n\n";
		}
	}
	return 0;
}
