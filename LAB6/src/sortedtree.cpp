// Matthew Ruiz

#include <iostream>
#include <random>
#include <functional>
#include "BinarySearchTree.h"

// Function prototype
void displayTree(int& anEntry);

int main()
{
    auto dice = std::bind(std::uniform_int_distribution<int>{1, 100},
                          std::default_random_engine{std::random_device()()});
    const int TREE_SIZE {21};
    std::shared_ptr<BinarySearchTree<int>> treePtr = std::make_shared<BinarySearchTree<int>>();

    int number {0};
    int firstNum;

    for (int i {0}; i < TREE_SIZE; i++)
    {
        if (i == 0)
            std::cout << "The numbers that will be inserted: \n";
        else
            std::cout << ", ";

        number = dice();

        if (i == 0)
            firstNum = number;

        std::cout << number;

        treePtr->add(number);
    }
    std::cout << "\n\n";

    // display just use in order traversal
    std::cout << "The sorted tree contains: \n";
    treePtr->inorderTraverse(displayTree);
    std::cout << "\n\n";

    std::cout << "Removing first number (" << firstNum << ") inserted.\n\n";
    treePtr->remove(firstNum);

    // display just use in order traversal
    std::cout << "The sorted tree contains: \n";
    treePtr->inorderTraverse(displayTree);
    std::cout << "\n\n";

    return 0;
}

void displayTree(int& anEntry)
{
    std::cout << anEntry << ", ";
}
