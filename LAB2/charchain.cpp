// Matthew Ruiz

#include <iostream>

class Node {
private:
    int item;
    Node * next;
public:
    Node(int item) : item(item),next(nullptr) {}

    int getItem() const {
        return item;
    }

    void setItem(int item) {
        Node::item = item;
    }

    Node *getNext() const {
        return next;
    }

    void setNext(Node *next) {
        Node::next = next;
    }

};

class Bag {
private:
    Node * head;
public:
    Bag () : head(nullptr) {}

    void add(int item) {
        Node *newNode = new Node(item);
        newNode->setNext(head);
        head = newNode;
    }
    void remove(int item) {
        Node *currNode = head;

        while(currNode != nullptr && currNode->getItem() != item) {
            currNode = currNode->getNext();
        }
        if (currNode != nullptr) {
            currNode->setItem(head->getItem());
            Node *deleteNode = head;
            head = head->getNext();
            delete deleteNode;
        }
    }
    void display() const {
        Node *currNode = head;
        std::cout << "bag - " << head << " : ";

        while(currNode != nullptr) {
            std::cout << currNode << " - " << currNode->getItem() << " ";
            currNode = currNode->getNext();
        }
        std::cout << std::endl;
    }
    void clear () {

        while (head !=nullptr) {
            Node *deleteNode = head;
            head = head->getNext();
            delete deleteNode;
        }
    }

    ~Bag () { clear(); }
};
int main() {
    Bag bag;
    bag.display();

    bag.add(1);
    bag.add(3);
    bag.add(5);
    bag.display();

    bag.remove(3);
    bag.display();

    bag.clear();
    bag.display();

    return 0;
}
