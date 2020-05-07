// Matthew Ruiz

#include <iostream>
#include <random>
#include <functional>
#include "SortedListInterface.h"
#include "LinkedSortedList.h"

// Function prototype
void displayList(const std::shared_ptr<SortedListInterface<int>>& listPtr);

int main()
{
    // generate a number from 1-100 use the STL random library
    auto dice = bind(std::uniform_int_distribution<int>{1, 100},
                     std::default_random_engine{std::random_device()()});

    const int LIST_SIZE {21};
    std::shared_ptr<SortedListInterface<int>> listPtr = std::make_shared<LinkedSortedList<int>>();
    int number{0};
    int position;
    int firstNum;

    for (int i = 0; i < LIST_SIZE; i++)
    {
        if (i == 0)
            std::cout << "Generating 21 random numbers which values range from 1-100:\n";
        else
            std::cout << ", ";

        // generates number in the range 1-100
        number = dice();
	    std::cout << number;
        // insert 21 random numbers 1-100 on the sorted list
        listPtr->insertSorted(number);

        if (i == 0)
        {
            firstNum = number;
        }
    }
    std::cout << "\n\n";

    // display sorted list
    displayList(listPtr);

    position = listPtr->getPosition(firstNum);
    std::cout << "Removing number: " << listPtr->getEntry(position) << "\n\n";
    listPtr->remove(position);
    /*if (number > 0)
    {
        position = listPtr->getPosition(number);
        std::cout << "Removing number: " << listPtr->getEntry(position) << "\n\n";
        listPtr->remove(position);
    }*/

    // display the sorted list with the first number inserted removed
    displayList(listPtr);

    return 0;
}

void displayList(const std::shared_ptr<SortedListInterface<int>>& listPtr)
{
    std::cout << "The linked sorted list contains " << '\n';

    for (int pos = 1; pos <= listPtr->getLength(); pos++)
    {
        if (pos > 1)
            std::cout << ", ";
	std::cout << listPtr->getEntry(pos);
    }

    std::cout << "\n\n";
}
