// Matthew Ruiz

#pragma once

#include <string>

template<class ItemType>
class ListInterface
{
public:
    virtual void setName(std::string aName) = 0;
    virtual void addGift(ItemType aGift) = 0;

    virtual std::string getName() const = 0;
    virtual std::string giftsToString(std::string split) = 0;
};