// Matthew Ruiz
#include <iostream>
#include "LinkedChar.h"

LinkedChar::LinkedChar()
{
    headPtr = nullptr;
    itemCount = 0;
}

LinkedChar::LinkedChar(std::string s)
{
    headPtr = nullptr;
    itemCount = 0;
    for (int i = 0; i < s.length(); i++)
        add(s[i]);
}

void LinkedChar::display()
{
    Node * curr = headPtr;
    std::cout << "LinkedChar: '";
    while (curr != nullptr) {
        std::cout << curr->getItem();
        curr = curr->getNext();
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
        Node* curr = headPtr;
        while (curr->getNext() != nullptr)
            curr = curr->getNext();
        curr->setNext(newNode);
    }
    itemCount++;
}

int LinkedChar::length() const
{
    return itemCount;
}

int LinkedChar::index(char ch) const
{
    int lcindex = 0;
    Node * curr = headPtr;
    while (curr != nullptr && curr->getItem() != ch)
    {
        ++lcindex;
        curr = curr->getNext();
    }
    if (curr == nullptr)
        return -1;
    else
        return lcindex;
}

void LinkedChar::append(const LinkedChar & lc)
{
    Node* curr = lc.headPtr;
    while (curr != nullptr)
    {
        add(curr->getItem());
        curr = curr->getNext();
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
