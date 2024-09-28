#include <iostream>
#include "queue.h"


Queue::Queue() { head = tail = nullptr;}

bool Queue::isEmpty() {
    return head == nullptr;
}

void Queue::enqueue(int newData) {
    Node* newNode = new Node(newData);

    if (isEmpty()) {
        head = tail = newNode;
    }

    else {
        tail->next = newNode;
        tail = newNode;
    }
}

void Queue::dequeue() {
    if (isEmpty()) {
        std::cout << "Queue Empty";
        return;
    }
    Node* temp = head;
    head = head->next;

    if (head == nullptr) {
        tail = nullptr;
    }

    delete temp;
}

int Queue::peek() {
    if (!this->isEmpty()) {
        return head->data;
    }
    else {
        std::cout << "Empty Queue";
        return INT_MIN;
    }
}