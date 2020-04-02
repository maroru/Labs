// Matthew Ruiz

#include <iostream>
#include "NiceList.h"

int main()
{
    std::list<NiceList<std::string>> lists;
    std::string listName, giftName;

    std::cout << "name for nice list: ";
    std::getline(std::cin, listName);

    while (!listName.empty())
    {
        NiceList<std::string> niceList;
        niceList.setName(listName);

        std::cout << "add gifts for " << listName << std::endl;

        do {
            std::cout << "gift: ";
            std::getline(std::cin, giftName);
            niceList.addGift(giftName);
        } while (!giftName.empty());

        lists.push_back(niceList);

        std::cout << "name for nice list: ";
        std::getline(std::cin, listName);
    }

    std::cout << "The list contains" << std::endl;
    for (auto aList: lists)
        std::cout << aList.getName() << "  " << aList.giftsToString(" ") << std::endl;

    return 0;
}