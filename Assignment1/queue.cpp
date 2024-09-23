#include <iostream>
using namespace std;
#include "node.h"

class Queue {
private:
    Node* head;
    Node* tail;

public:
    Queue() { head = tail = nullptr;}

    bool isEmpty() {
        return head == nullptr;
    }

    void enqueue(int newData) {
        Node* newNode = new Node(newData);

        if (this->isEmpty()) {
            head = tail = newNode;
        }

        else {
            tail->next = newNode;
            tail = newNode;
        }
    }

    void dequeue() {
        if (this->isEmpty()) {
            cout << "Queue Empty";
            return;
        }
        Node* temp = head;
        head = head->next;

        if (head == nullptr) {
            tail = nullptr;
        }

        delete temp;
    }
};