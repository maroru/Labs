// Matthew Ruiz

#include <iostream>
#include "NiceList.h"

int main()
{
    std::list<NiceList<std::string>> lists;
    std::string name, gift;

    std::cout << "name for nice list: ";
    std::getline(std::cin, name);

    while (!name.empty())
    {
        NiceList<std::string> niceList;
        niceList.setName(name);

        std::cout << "add gifts for " << name << '\n';

        do {
            std::cout << "gift: ";
            std::getline(std::cin, gift);
            niceList.addGift(gift);
        } while (!gift.empty());

        lists.push_back(niceList);

        std::cout << "name for nice list: ";
        std::getline(std::cin, name);
    }

    std::cout << "The list contains" << '\n';
    for (auto aList: lists)
        std::cout << aList.getName() << " : " << aList.giftsToString(" ") << '\n';

    return 0;
}