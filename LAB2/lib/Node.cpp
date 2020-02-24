// Matthew Ruiz
#include "Node.h"

Node::Node() : next(nullptr){}
Node::Node(const char& anItem) : item(anItem), next(nullptr){}
Node::Node(const char& anItem, Node* nextNodePtr) : item(anItem), next(nextNodePtr){}

char Node::getItem() const
{
    return item;
}

void Node::setItem(const char& anItem)
{
    item = anItem;
}

Node * Node::getNext() const
{
    return next;
}

void Node::setNext(Node* nextNodePtr)
{
    next = nextNodePtr;
}
