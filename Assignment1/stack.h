#ifndef STACK_H
#define STACK_H

#include "node.h"

class Stack {
private:
    Node* top;
public:
    Stack();
    bool isEmpty();
    void pop();
    void push(int newData);
    int peek();
};

#endif