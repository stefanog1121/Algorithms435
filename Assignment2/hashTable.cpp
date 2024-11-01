#include "hashTable.h"
#include <iostream>
#include <algorithm>

// node constructor 
HashTable::Node::Node(const std::string& s) : item(s), next(nullptr) {}

// table constructor 
HashTable::HashTable() {
    // initialize all chain heads to NULL
    std::fill(table, table + SIZE, nullptr);
}

// hash function 
int HashTable::hashCode(const std::string& s) {
    std::string upperStr = s;
    std::transform(upperStr.begin(), upperStr.end(), upperStr.begin(), ::toupper);
    int length = upperStr.length();
    int letterTotal = 0;

    for (int i = 0; i < length; i++) {
        char thisLetter = upperStr.at(i);
        int thisValue = (int)thisLetter;
        letterTotal = letterTotal + thisValue;
    }
    int code = (letterTotal * 1) % SIZE;
    return code;
}

void HashTable::insertItem(const std::string& item) {
    int code = hashCode(item);
    Node* newNode = new Node(item);
    newNode->next = table[code];
    table[code] = newNode;
}

std::pair<bool, int> HashTable::getItem(const std::string& item) {
    int comparisons = 1; // initalize to 1 for get operation
    int code = hashCode(item);
    Node* current = table[code];

    while (current != nullptr) {
        comparisons++;
        if (current->item == item) {
            return {true, comparisons};
        }
        current = current->next;
    }
    return {false, comparisons};
}

void HashTable::deleteItem(const std::string& item) {
    int code = hashCode(item);
    Node* current = table[code];
    Node* prev = nullptr;

    // three cases to handle with deleetion:
    // empty chain
    if (current == nullptr) {
        return;
    }

    // item at head of chain
    if (current->item == item) {
        table[code] = current->next;
        delete current;
        return;
    }

    // item in middle/end of chain
    while (current != nullptr && current->item != item) {
        prev = current;
        current = current->next;
    }

    // if found, delete the item.
    if (current != nullptr) {
        prev->next = current->next;
        delete current;
    }
}

void HashTable::hashGetItems(const std::vector<std::string>& list, 
                           const std::vector<std::string>& items) {
    double hashComparisonCount = 0;

    // fill table with magic items
    for (const auto& i : list) {
        insertItem(i);
    }
    
    // Calculate load factor
    double loadFactor = static_cast<double>(list.size()) / SIZE;
    
    std::cout << "\nHash Table Search Results:\n";
    std::cout << "-------------------------\n";
    std::cout << "Load Factor: " << loadFactor << "\n";
    std::cout << "Total Items: " << list.size() << "\n";
    std::cout << "Table Size: " << SIZE << "\n\n";
    std::cout << "\nHash Table Search Results:\n";
    std::cout << "-------------------------\n";

    for (const auto& i : items) {
        std::pair<bool, int> retrival = getItem(i);
        if (retrival.first) {
            std::cout << "Found item | Comparisons: " << retrival.second << '\n';
            hashComparisonCount = hashComparisonCount + retrival.second;
        }
        else {
            std::cout << "ERR: Item Not Found" << '\n';
        }
    }
    std::cout << "Average Get Comparisons: " << hashComparisonCount / (double)items.size() << '\n';
}