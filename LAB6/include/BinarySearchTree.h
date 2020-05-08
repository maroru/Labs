// Created by Frank M. Carrano and Timothy M. Henry.
// Copyright (c) 2017 Pearson Education, Hoboken, New Jersey.

// Listing 16-4. Altered

/** Link-based implementation of the ADT binary search tree.
 @file BinarySearchTree.h */
 
#ifndef BINARY_SEARCH_TREE_
#define BINARY_SEARCH_TREE_

#include <memory>
#include <vector>
#include "BinaryTreeInterface.h"
#include "BinaryNode.h"
#include "BinaryNodeTree.h"
#include "NotFoundException.h"
#include "PrecondViolatedExcep.h"

template<class ItemType>
class BinarySearchTree : public BinaryNodeTree<ItemType>
{
// use this->rootPtr to access the BinaryNodeTree rootPtr
   
protected:
   //------------------------------------------------------------
   // Protected Utility Methods Section:
   // Recursive helper methods for the public methods.
   //------------------------------------------------------------
   // Recursively finds where the given node should be placed and
   // inserts it in a leaf at that point.
   std::shared_ptr<BinaryNode<ItemType>> placeNode(std::shared_ptr<BinaryNode<ItemType>> subTreePtr,
                                       std::shared_ptr<BinaryNode<ItemType>> newNode);
   
   // Removes the given target value from the tree while maintaining a
   // binary search tree.
   std::shared_ptr<BinaryNode<ItemType>> removeValue(std::shared_ptr<BinaryNode<ItemType>> subTreePtr,
                                     const ItemType target,
                                     bool& success) override;
   
   // Removes a given node from a tree while maintaining a
   // binary search tree.
   std::shared_ptr<BinaryNode<ItemType>> removeNode(std::shared_ptr<BinaryNode<ItemType>> nodePtr);
   
   // Removes the leftmost node in the left subtree of the node
   // pointed to by nodePtr.
   // Sets inorderSuccessor to the value in this node.
   // Returns a pointer to the revised subtree.
   std::shared_ptr<BinaryNode<ItemType>> removeLeftmostNode(std::shared_ptr<BinaryNode<ItemType>> subTreePtr,
                                            ItemType& inorderSuccessor);
   
   // Returns a pointer to the node containing the given value,
   // or nullptr if not found.
   std::shared_ptr<BinaryNode<ItemType>> findNode(std::shared_ptr<BinaryNode<ItemType>> treePtr,
                                  const ItemType& target) const;
   
public:
   //------------------------------------------------------------
   // Constructor and Destructor Section.
   //------------------------------------------------------------
   // inherits from BinaryNodeTree
   
   //------------------------------------------------------------
   // Public Methods Section.
   //------------------------------------------------------------
   void setRootData(const ItemType& newData) const noexcept(false);
    bool add(const ItemType& newEntry) override;
   bool remove(const ItemType& anEntry) override;
   ItemType getEntry(const ItemType& anEntry) const override;
   bool contains(const ItemType& anEntry) const override;
   
}; // end BinarySearchTree

// add function implementations below
// Matthew Ruiz

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
void BinarySearchTree<ItemType>::setRootData(const ItemType &newItem) const noexcept(false) {
    throw PrecondViolatedExcep("Cannot change root value in a BST!");
}  // end setRootData

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
ItemType BinarySearchTree<ItemType>::getEntry(const ItemType &anEntry) const noexcept(false)
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

#endif
