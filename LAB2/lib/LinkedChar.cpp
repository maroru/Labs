// Matthew Ruiz
#include <iostream>
#include "LinkedChar.h"

LinkedChar::LinkedChar() : headPtr(nullptr), itemCount(0){}

LinkedChar::LinkedChar(std::string s)
{
    headPtr = nullptr;
    itemCount = 0;
    for (int i = 0; i < s.length(); i++)
        add(s[i]);
}

void LinkedChar::display()
{
    Node * curPtr = headPtr;
    std::cout << "LinkedChar: '";
    while (curPtr != nullptr) {
        std::cout << curPtr->getItem();
        curPtr = curPtr->getNext();
    }
    std::cout << "'";
}

void LinkedChar::add(const char& newEntry)
{
    Node * newNode = new Node(newEntry);
    if (headPtr == nullptr)
        headPtr = newNode;
    else
    {
        Node* curPtr = headPtr;
        while (curPtr->getNext() != nullptr)
            curPtr = curPtr->getNext();
        curPtr->setNext(newNode);
    }
    itemCount++;
}

int LinkedChar::length() const
{
    return itemCount;
}

int LinkedChar::index(char ch) const
{
    int lcIndex = 0;
    Node * curPtr = headPtr;
    while (curPtr != nullptr && curPtr->getItem() != ch)
    {
        ++lcIndex;
        curPtr = curPtr->getNext();
    }
    if (curPtr == nullptr)
        return -1;
    else
        return lcIndex;
}

void LinkedChar::append(const LinkedChar & lc)
{
    Node* curPtr = lc.headPtr;
    while (curPtr != nullptr)
    {
        add(curPtr->getItem());
        curPtr = curPtr->getNext();
    }
}

bool LinkedChar::submatch(const LinkedChar & lc) const
{
    Node* lcPtr = headPtr;
    Node* subPtr = lc.headPtr;
    while (lcPtr != nullptr)
    {
        if (lcPtr->getItem() == subPtr->getItem() && subPtr->getNext() == nullptr)
            return true;
        else if (lcPtr->getItem() == subPtr->getItem())
        {
            lcPtr = lcPtr->getNext();
            subPtr = subPtr->getNext();
        }
        else if (lc.headPtr->getItem() == lcPtr->getItem())
            subPtr = lc.headPtr;
        else
        {
            subPtr = lc.headPtr;
            lcPtr = lcPtr->getNext();
        }
    }
    return false;
}

LinkedChar::~LinkedChar()
{
    Node* nodeToDeletePtr = headPtr;
    while (headPtr != nullptr)
    {
        headPtr = headPtr->getNext();

        nodeToDeletePtr->setNext(nullptr);
        delete nodeToDeletePtr;

        nodeToDeletePtr = headPtr;
    }
    itemCount = 0;
}
