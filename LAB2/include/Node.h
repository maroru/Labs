// Mattheew Ruiz
#pragma once

class Node {
    private:
        char item;
        Node * next;
    public:
        Node();
        Node(const char& anItem);
        Node(const char& anItem, Node* nextNodePtr);
        char getItem() const;
        void setItem(const char& anItem);
        Node* getNext() const;
        void setNext(Node* nextNodePtr);
};
