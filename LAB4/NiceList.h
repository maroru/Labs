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

template<class ItemType>
void NiceList<ItemType>::setName(std::string aName)
{
    name = aName;
}

template<class ItemType>
void NiceList<ItemType>::addGift(ItemType aGift)
{
    gifts.push_back(aGift);
}

template<class ItemType>
std::string NiceList<ItemType>::getName() const
{
    return name;
}

template<class ItemType>
std::string NiceList<ItemType>::giftsToString(std::string split)
{
    std::string result;

    for (typename std::list<ItemType>::iterator i = gifts.begin(); i != gifts.end(); i++)
    {
        if (!result.empty())
            result += split;
        result += ItemType(*i);
    }

    return result;
}