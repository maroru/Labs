// Matthew Ruiz

#include "BinarySearchTree.h"

// protected methods

template<class ItemType>
std::shared_ptr<BinaryNode<ItemType>> BinarySearchTree<ItemType>::placeNode(
        std::shared_ptr<BinaryNode<ItemType>> subTreePtr, std::shared_ptr<BinaryNode<ItemType>> newNode)
{
    if (subTreePtr == nullptr)
        return newNode;
    else if (subTreePtr->getItem() > newNode->getItem())
        subTreePtr->setLeftChildPtr(placeNode(subTreePtr->getLeftChildPtr(), newNode));
    else
        subTreePtr->setRightChildPtr(placeNode(subTreePtr->getRightChildPtr(), newNode));

    return subTreePtr;
}

template<class ItemType>
std::shared_ptr<BinaryNode<ItemType>> BinarySearchTree<ItemType>::removeValue(
        std::shared_ptr<BinaryNode<ItemType>> subTreePtr, const ItemType target, bool &success)
{
    if (subTreePtr == nullptr)
    {
        success = false;
    }
    else if (subTreePtr->getItem() == target)
    {
        subTreePtr = removeNode(subTreePtr);
        success = true;
    }
    else if (subTreePtr->getItem() > target)
    {
        auto tempPtr = removeValue(subTreePtr->getLeftChildPtr(), target, success);
        subTreePtr->setLeftChildPtr(tempPtr);
    }
    else
    {
        auto tempPtr = removeValue(subTreePtr->getRightChildPtr(), target, success);
        subTreePtr->setRightChildPtr(tempPtr);
    }

    return subTreePtr;
}

template<class ItemType>
std::shared_ptr<BinaryNode<ItemType>> BinarySearchTree<ItemType>::removeNode(
        std::shared_ptr<BinaryNode<ItemType>> nodePtr)
{
    if (nodePtr->isLeaf())
    {
        nodePtr = nullptr;

        return nodePtr;
    }
    else if ((nodePtr->getLeftChildPtr() != nullptr) != (nodePtr->getRightChildPtr() != nullptr))
    {
        std::shared_ptr<BinaryNode<ItemType>> nodeToConnectPtr = nullptr;

        if (nodePtr->getLeftChildPtr() != nullptr)
            nodeToConnectPtr = nodePtr->getLeftChildPtr();
        else
            nodeToConnectPtr = nodePtr->getRightChildPtr();

        nodePtr = nullptr;
        return nodeToConnectPtr;
    }
    else
    {
        auto newNodeValue = nodePtr->getItem();
        auto tempPtr = removeLeftmostNode(nodePtr->getRightChildPtr(), newNodeValue);
        nodePtr->setRightChildPtr(tempPtr);
        nodePtr->setItem(newNodeValue);

        return nodePtr;
    }
}

template<class ItemType>
std::shared_ptr<BinaryNode<ItemType>> BinarySearchTree<ItemType>::removeLeftmostNode(
        std::shared_ptr<BinaryNode<ItemType>> subTreePtr, ItemType &inorderSuccessor)
{
    if (subTreePtr->getLeftChildPtr() == nullptr)
    {
        inorderSuccessor = subTreePtr->getItem();

        return removeNode(subTreePtr);
    }
    else
    {
        auto tempPtr = removeLeftmostNode(subTreePtr->getLeftChildPtr(), inorderSuccessor);
        subTreePtr->setLeftChildPtr(tempPtr);

        return subTreePtr;
    }
}

template<class ItemType>
std::shared_ptr<BinaryNode<ItemType>> BinarySearchTree<ItemType>::findNode(
        std::shared_ptr<BinaryNode<ItemType>> treePtr, const ItemType &target) const
{
    if (treePtr == nullptr)
        return nullptr;
    else if (treePtr->getItem() == target)
        return treePtr;
    else if (treePtr->getItem() > target)
        return findNode(treePtr->getLeftChildPtr(), target);
    else
        return findNode(treePtr->getRightChildPtr(), target);
}

// public methods

template<class ItemType>
void BinarySearchTree<ItemType>::setRootData(const ItemType &newData) const throw(PrecondViolatedExcep)
{

}

template<class ItemType>
bool BinarySearchTree<ItemType>::add(const ItemType &newEntry)
{
    auto newNodePtr = std::make_shared<BinaryNode<ItemType>>(newEntry);
    this->rootPtr = placeNode(this->rootPtr, newNodePtr);

    return true;
}

template<class ItemType>
bool BinarySearchTree<ItemType>::remove(const ItemType &anEntry)
{
    bool isSuccessful = false;
    this->rootPtr = removeValue(this->rootPtr, anEntry, isSuccessful);

    return isSuccessful;
}

template<class ItemType>
ItemType BinarySearchTree<ItemType>::getEntry(const ItemType &anEntry) const throw(NotFoundException)
{
    auto binaryNodePtr = findNode(this->rootPtr, anEntry);
    bool isSuccessful = binaryNodePtr != nullptr;

    if (isSuccessful)
        return binaryNodePtr->getItem();
    else
        throw NotFoundException("Entry not found in tree!");
}

template<class ItemType>
bool BinarySearchTree<ItemType>::contains(const ItemType &anEntry) const
{
    auto binaryNodePtr = findNode(this->rootPtr, anEntry);
    bool isSuccessful = binaryNodePtr != nullptr;

    return isSuccessful;
}
