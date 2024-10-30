#ifndef HASHTABLE_H
#define HASHTABLE_H

#include <string>
#include <vector>
#include <utility>

class HashTable {
private:
    struct Node {
        std::string item;
        Node* next;
        Node(const std::string& s);
    };

    static const int SIZE = 250;
    Node* table[SIZE];
    
    int hashCode(const std::string& s);

public:
    HashTable();
    
    void insertItem(const std::string& item);
    std::pair<bool, int> getItem(const std::string& item);
    void deleteItem(const std::string& item);
    
    void hashGetItems(const std::vector<std::string>& list, 
                     const std::vector<std::string>& items);
};

#endif 