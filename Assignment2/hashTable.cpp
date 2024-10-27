#include <iostream>


class HashTable {
    private:
        struct Node {
            std::string item;
            int key;
            Node* next;
        };

        static const int SIZE = 250;
        Node* table[SIZE];
    public:
}