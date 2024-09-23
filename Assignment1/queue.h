#ifndef QUEUE_H
#define QUEUE_H

#include "node.h"

class Queue {
private:
    Node* head;
    Node* tail;

public:
    Queue();
    bool isEmpty();
    void enqueue(int newData);
    void dequeue();
};

#endif