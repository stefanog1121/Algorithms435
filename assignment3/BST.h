#ifndef BST_H
#define BST_H

#include <string>
#include <vector>
#include <utility>

class BST {
private:
    struct Node {
        Node(const std::string& s);
        std::string id;
        Node* left;
        Node* right;
        Node* parent;
    };

    Node* root;
public:
    BST();
    
    BST::Node* getRoot();
    void treeInsert(const std::string& s);
    void inOrderTraversal(Node* x);
    void populateTree(std::vector<std::string>& list);
    int search(Node* x, const std::string& s, int comparisons);
};

std::string makeLower(std::string s);

#endif 