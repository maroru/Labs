#pragma once
#include <string>
#include "Node.h"
class LinkedChar
{
    private:
        Node * head;
        int itemCount;
    public:
        LinkedChar();
        LinkedChar(std::string s);
        void display();
        void add(const char item);
        int length() const;
        void append(const LinkedChar& lc);
        bool submatch(const LinkedChar& lc) const;
        int index(char ch) const;
        ~LinkedChar();
};

LinkedChar::LinkedChar()
{
    head = nullptr;
    itemCount = 0;
}

LinkedChar::LinkedChar(std::string s)
{
    head = nullptr;
    itemCount = 0;
    for (int i = 0; i < s.length(); i++)
        add(s[i]);
}

void LinkedChar::display()
{
    Node * curr = head;
    std::cout << "LinkedChar: '";
    while (curr != nullptr) {
        std::cout << curr->getItem();
        curr = curr->getNext();
    }
    std::cout << "'";
}

void LinkedChar::add(const char item)
{
    Node * newNode = new Node(item);
    if (head == nullptr)
        head = newNode;
    else
    {
        Node* curr = head;
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
    Node * curr = head;
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
    Node* curr = lc.head;
    while (curr != nullptr)
    {
        add(curr->getItem());
        curr = curr->getNext();
    }
}

bool LinkedChar::submatch(const LinkedChar & lc) const
{
    Node* lcPtr = head;
    Node* subPtr = lc.head;
    while (lcPtr != nullptr)
    {
        if (lcPtr->getItem() == subPtr->getItem() && subPtr->getNext() == nullptr)
            return true;
        else if (lcPtr->getItem() == subPtr->getItem())
        {
            lcPtr = lcPtr->getNext();
            subPtr = subPtr->getNext();
        }
        else if (lc.head->getItem() == lcPtr->getItem())
            subPtr = lc.head;
        else
        {
            subPtr = lc.head;
            lcPtr = lcPtr->getNext();
        }
    }
    return false;
}

LinkedChar::~LinkedChar()
{
    while (head != nullptr)
    {
        Node *oldPtr = head;
        head = head->getNext();
        delete oldPtr;
    }
}
