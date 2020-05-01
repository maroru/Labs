// Matthew Ruiz

#include <cmath>
#include <cassert>
#include "LinkedSortedList.h"

template<class ItemType>
LinkedSortedList<ItemType>::LinkedSortedList() : headPtr(nullptr), itemCount(0)
{
} // end default constructor

template<class ItemType>
LinkedSortedList<ItemType>::LinkedSortedList(const LinkedSortedList<ItemType> &aList)
{
    headPtr = copyChain(aList.headPtr);
    itemCount = aList.itemCount;
} // end copy constructor

template<class ItemType>
LinkedSortedList<ItemType>::~LinkedSortedList()
{
    clear();
} // end destructor

// private methods
template<class ItemType>
auto LinkedSortedList<ItemType>::getNodeBefore(const ItemType &anEntry) const
{
    auto curPtr = headPtr;
    std::shared_ptr<Node<ItemType>> prevPtr;

    while ( (curPtr != nullptr) && (anEntry > curPtr->getItem()) )
    {
        prevPtr = curPtr;
        curPtr = curPtr->getNext();
    }

    return prevPtr;
}

template<class ItemType>
auto LinkedSortedList<ItemType>::getNodeAt(int position) const
{
    // Debugging check of precondition
    assert( (position >= 1) && (position <= itemCount) );

    // Count from the beginning of the chain
    auto curPtr = headPtr;
    for (int skip = 1; skip < position; skip++)
        curPtr = curPtr->getNext();

    return curPtr ;
}

template<class ItemType>
auto LinkedSortedList<ItemType>::copyChain(const std::shared_ptr<Node<ItemType>> &origChainPtr)
{
    std::shared_ptr<Node<ItemType>> copiedChainPtr;

    if (origChainPtr != nullptr)
    {
        copiedChainPtr = std::make_shared<Node<ItemType>>(origChainPtr->getItem());

        copiedChainPtr->setNext(copyChain(origChainPtr->getNext()));
    }

    return copiedChainPtr;
}

// public methods
template<class ItemType>
bool LinkedSortedList<ItemType>::insertSorted(const ItemType &newEntry)
{
    int newPosition = abs(getPosition(newEntry));
    bool ableToInsert = (newPosition >= 1) && (newPosition <= itemCount + 1);

    if (ableToInsert)
    {
        // create a new node containing the new entry
        auto newNodePtr = std::make_shared<Node<ItemType>>(newEntry);

        // attach new node to chain
        if (newPosition == 1)
        {
            // insert new node at beginning of chain
            newNodePtr->setNext(headPtr);
            headPtr = newNodePtr;
        }
        else
        {
            // find node that will be before new node
            auto prevPtr = getNodeAt(newPosition - 1);

            // insert new node after node to which prevPtr points
            newNodePtr->setNext(prevPtr->getNext());
            prevPtr->setNext(newNodePtr);
        }  

        itemCount++;  // Increase count of entries
    }

    return ableToInsert;
}

template<class ItemType>
bool LinkedSortedList<ItemType>::removeSorted(const ItemType &anEntry)
{
    bool ableToDelete = false;
    if (!isEmpty())
    {
        auto nodeToRemovePtr = headPtr;
        auto prevPtr = getNodeBefore(anEntry);
        if (prevPtr != nullptr)
            nodeToRemovePtr = prevPtr->getNext();

        ableToDelete = (nodeToRemovePtr != nullptr) &&
                       (anEntry == nodeToRemovePtr->getItem());
        if (ableToDelete)
        {
            auto aftPtr = nodeToRemovePtr->getNext();
            if (nodeToRemovePtr == headPtr)
            {
                // Delete the first node in the chain
                headPtr = aftPtr;
            }
            else
            {

                // Disconnect indicated node from chain by connecting the
                // prior node with the one after
                prevPtr->setNext(aftPtr);
            }  

            itemCount--;  // Decrease count of entries
        }
    }

    return ableToDelete;
}

template<class ItemType>
int LinkedSortedList<ItemType>::getPosition(const ItemType &anEntry) const
{
    int position = 1;
    int length = getLength();

    while ( (position <= length) && (anEntry > getEntry(position)) )
        position++;

    if ( (position > length) || (anEntry != getEntry(position)) )
        position = -position;

    return position;
}

template<class ItemType>
bool LinkedSortedList<ItemType>::isEmpty() const
{
    return itemCount == 0;
}

template<class ItemType>
int LinkedSortedList<ItemType>::getLength() const
{
    return itemCount;
}

template<class ItemType>
bool LinkedSortedList<ItemType>::remove(int position)
{
    bool ableToDelete = (position >= 1) && (position <= itemCount);
    if (ableToDelete)
    {
        if (position == 1)
        {
            // Delete the first node in the chain
            headPtr = headPtr->getNext();
        }
        else
        {
            // Find node that is before the one to delete
            auto prevPtr = getNodeAt(position - 1);

            // Point to node to delete
            auto curPtr = prevPtr->getNext();

            // Disconnect indicated node from chain by connecting the
            // prior node with the one after
            prevPtr->setNext(curPtr->getNext());
        }

        itemCount--;  // Decrease count of entries
    }

    return ableToDelete;
}

template<class ItemType>
void LinkedSortedList<ItemType>::clear()
{
    headPtr.reset();

    itemCount = 0;
}

template<class ItemType>
ItemType LinkedSortedList<ItemType>::getEntry(int position) const noexcept(false)
{
    // Enforce precondition
    bool ableToGet = (position >= 1) && (position <= itemCount);
    if (ableToGet)
    {
        auto nodePtr = getNodeAt(position);
        return nodePtr->getItem();
    }
    else
    {
        std::string message = "getEntry() called with an empty linked sorted list or ";
        message  = message + "invalid position.";
        throw(PrecondViolatedExcep(message));
    }
}
