#include <iostream>
#include "stack.h"


Stack::Stack() { this->top = nullptr; }

bool Stack::isEmpty() {
    return top == nullptr;
}

// slice top element from the stack
void Stack::pop() {
    if (isEmpty()) {
        std::cout << "Empty Stack";
    }
    else {
        Node* temp = top;
        top = top->next;
        delete temp;
    }
}

// add new node to the stack
void Stack::push(int newData) {
    Node* newNode = new Node(newData);
    newNode->next = top;
    top = newNode;
}

// view node on top of stack
int Stack::peek() {
    if (!isEmpty()) {
        return top->data;
    }
    else {
        std::cout << "Empty Stack";
        return INT_MIN;
    }
}