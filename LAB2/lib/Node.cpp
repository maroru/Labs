// Matthew Ruiz
#include "Node.h"

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
