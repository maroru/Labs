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
    const int TREE_SIZE = 21;
    std::shared_ptr<BinarySearchTree<int>> treePtr = std::make_shared<BinarySearchTree<int>>();

    int number = 0;

    for (int i = 0; i < TREE_SIZE; i++)
    {
        if (i == 0)
            std::cout << "The numbers that will be inserted: \n";
        else
            std::cout << ", ";

        number = dice();
        std::cout << number;

        treePtr->add(number);
    }

    std::cout << "\n\n";

    // display just use in order traversal
    std::cout << "The sorted tree contains: " << std::endl;
    treePtr->inorderTraverse(displayTree);
    std::cout << "\n\n";

    if (number > 0)
        treePtr->remove(number);

    // display just use in order traversal
    std::cout << "The sorted tree contains: " << std::endl;
    treePtr->inorderTraverse(displayTree);
    std::cout << "\n\n";

    return 0;
}

void displayTree(int& anEntry)
{
    std::cout << anEntry << " ";
}
