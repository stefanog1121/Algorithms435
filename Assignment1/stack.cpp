#include <iostream>
using namespace std;
#include "node.h"

class Stack {
    Node* top;

public:
    Stack() { this->top = nullptr; }

    bool isEmpty() {
        return top == nullptr;
    }

    // slice top element from the stack
    void pop() {
        if (this->isEmpty()) {
            cout << "Empty Stack";
        }
        else {
            Node* temp = top;
            Node* top = top->next;
            delete temp;
        }
    }

    // add new node to the stack
    void push(int newData) {
        Node* newNode = new Node(newData);
        newNode->next = top;
        top = newNode;
    }

    // view node on top of stack
    int peek() {
        if (!this->isEmpty()) {
            return top->data;
        }
        else {
            cout << "Empty Stack";
            return INT_MIN;
        }
    }
};