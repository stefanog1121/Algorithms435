#include <iostream>
using namespace std;
#include <vector>

class Node {
public:
    int data;
    Node* next;
    
    Node(int value) {
        this->data = value;
        this->next = nullptr;
    }
};
