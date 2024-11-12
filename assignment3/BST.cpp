#include "BST.h"
#include <iostream>
#include <vector>
#include <map>

BST::Node::Node(const std::string& s) : id(s), left(nullptr), right(nullptr), parent(nullptr) {}

BST::BST() : root(nullptr) {};

void BST::treeInsert(const std::string& s) {
    Node* x = root;
    Node* y = nullptr;
    Node* z = new Node(s);

    std::cout<<"\n" << "-------------------" << "\n";
    while (x != nullptr) {
        y = x;
        if (makeLower(z->id) < makeLower(x->id)) {
            std::cout<< "L" << "\n";
            x = x->left;
            }
        else {
            std::cout<< "R" << "\n";
            x = x->right;
            }
    }

    z->parent = y;
    if (y == nullptr) { root = z; }
    else if (makeLower(z->id) < makeLower(y->id)) { y->left = z; }
    else { y->right = z; };
    std::cout<< "Inserted " << s <<"\n";

};

void BST::inOrderTraversal(Node* x) {
    if (x != nullptr) {
        inOrderTraversal(x->left);
        std::cout<< x->id << "\n";
        inOrderTraversal(x->right);
    }
};

int BST::search(Node* x, const std::string& s, int comparisons) {
    if (x == nullptr || x->id == s){
        std::cout<< "Found " << s << " | ";
        comparisons++;
        return comparisons;
    }
    if (makeLower(s) < makeLower(x->id)) {
        std::cout<< "L" << "\n";
        comparisons++;
        return search(x->left, s, comparisons);
    }
    else {
        std::cout<< "R" << "\n";
        comparisons++;
        return search(x->right, s, comparisons);
    }
}

BST::Node* BST::getRoot() {
    return this->root;
}

void BST::populateTree(std::vector<std::string>& list) {
    for (const auto& i : list) {
        treeInsert(i);
    }
};

std::string makeLower(std::string s) {
    std::transform(s.begin(), s.end(), s.begin(),
        [](unsigned char c){ return std::tolower(c); });
    return s;
};