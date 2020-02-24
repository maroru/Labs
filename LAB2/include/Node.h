#pragma once

class Node {
    private:
        char item;
        Node * next;
    public:
        Node(char aitem) : item(aitem), next(nullptr) {}
        char getItem();
        void setItem(char aitem);
        Node* getNext();
        void setNext(Node* anode);
};
