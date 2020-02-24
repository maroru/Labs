#include "Node.h"

char Node::getItem()
{
    return item;
}

void Node::setItem(char aitem)
{
    item = aitem;
}

Node * Node::getNext()
{
    return next;
}

void Node::setNext(Node* anode)
{
    next = anode;
}
