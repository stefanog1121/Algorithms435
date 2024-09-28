#include <iostream>
using namespace std;
#include <vector>
#include <fstream>
#include <string>
#include "stack.h"
#include "queue.h"

void palindromes(vector<string> items);

int main() {
    ifstream file("magicitems.txt");
    string line;
    vector<string> list;

    if (file.is_open()) {
        while (getline(file, line)) {
            list.push_back(line);
        }
        file.close();
    } else {
        cout << "Unable to open file" << endl;
    }

   palindromes(list);
}

void palindromes(vector<string> items) {
    int size = items.size(); 
    int i = 0;

    while (i < size) {
        Stack s; 
        Queue q;
        string item = items[i];

        for(char c : item) {
            int charValue = static_cast<int>(c);
            s.push(charValue);
            q.enqueue(charValue); 
        }

        bool palindrome = true;
        while (!s.isEmpty() && !q.isEmpty()) {
            if(s.peek() == q.peek()) {
                s.pop();
                q.dequeue();
            }
            else {
                palindrome = false;
                break;
            }
        }

        if (palindrome) {cout << items[i] << endl;};
        i++;
    }
}