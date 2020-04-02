// Matthew Ruiz

#pragma once

#include <list>
#include "ListInterface.h"

template<class ItemType>
class NiceList : public ListInterface<ItemType>
{
private:
    std::string name;
    std::list<ItemType> gifts;
public:
    void setName(std::string aName);

    void addGift(ItemType aGift);

    std::string getName() const;
    std::string giftsToString(std::string split = ",");
};

//#include "NiceList.cpp"