#include <iostream>


class HashTable {
    private:
        struct Node {
            std::string item;
            Node* next;

            Node(const std::string& s) : item(s), next(nullptr) {}
        };

        static const int SIZE = 250;
        Node* table[SIZE];

        int hashCode (std::string& s) {
            std::string upperStr = s;
            std::transform(upperStr.begin(), upperStr.end(), upperStr.begin(), ::toupper);
            int length = upperStr.length();
            int letterTotal = 0;

            for (int i = 0; i < length; i++) {
                char thisLetter = upperStr.at(i);
                int thisValue = (int)thisLetter;
                letterTotal = letterTotal + thisValue;

                // Test: print the char and the hash.
                /* 
                System.out.print(" ["); 
                System.out.print(thisLetter); 
                System.out.print(thisValue); 
                System.out.print("] "); 
                */
            }
            int code = (letterTotal * 1) % SIZE;
            return code;
        };
    public:
        HashTable() {
            // Initialize all chain heads to NULL
            for (int i = 0; i < SIZE; i++) {
            table[i] = nullptr;
        };

        void insert(std::string& item) {

        };

        std::pair<int, int> get(std::string& item) {

        };

        void delete(std::string& item) {

        };

        void hashGetItems() {

        };
    };
};
