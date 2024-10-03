#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include "stack.h"
#include "queue.h"

void palindromes(std::vector<std::string>& items) {
    int size = items.size(); 
    int i = 0;

    std::cout << "\nPalindromes:" << std::endl;
    while (i < size) {
        Stack s; 
        Queue q;
        std::string item = items[i];

        for(char c : item) {
            if(isalnum(c)) {
                char lowC = tolower(c);
                s.push(lowC);
                q.enqueue(lowC); 
            }
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

        if (palindrome) {std::cout << items[i] << std::endl;};
        i++;
    }
    std::cout << std::endl;
}