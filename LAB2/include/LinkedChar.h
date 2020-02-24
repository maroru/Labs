#pragma once

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
