// Mattheew Ruiz
#pragma once

class Node {
    private:
        char item;
        Node * next;
    public:
        Node(char anItem) : item(anItem), next(nullptr) {}
        char getItem() const;
        void setItem(const char& anItem);
        Node* getNext() const;
        void setNext(Node* nextNodePtr);
};
