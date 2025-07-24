#ifndef TREESE_H
#define TREESE_H

#include <string>
#include <cstddef> 
#include <stdexcept> 
#include <iostream>

class Treese {
protected:
    struct Node {
        bool leaf;

        Node* left;
        Node* right;
     
        size_t length;
        std:: string data;

        //LN
        Node(const std::string& str ){
            leaf = true ;
            length = str.length();
            data = str;
            left = nullptr;
            right = nullptr;
        }

        // not lef node
        Node(Node* L, Node* R){
            leaf = false;
            length = 0;
            left= L;
            right = R;
            if (left) length += left->length;
            if (right) length += right->length;
        }

        void updateHeight() {
            size_t leftHeight = left ? left->height : 0;
            size_t rightHeight = right ? right->height : 0;
            height = 1 + std::max(leftHeight, rightHeight);
        }

        size_t height = 1; 
    };

    Node* root;

    void destroy(Node* node);
    Node* copy(Node* node) const;
    char getCharAt(Node* node, size_t index) const;
    void print(Node* node) const;

public:
    Treese();
    Treese(const std::string& initial);
    Treese(const Treese& other);
    Treese& operator=(const Treese& other);
    ~Treese();

    size_t length() const;
    char at(size_t index) const;
    void print() const;
    Treese concat(const Treese& other) const;
};

#endif // TREESE_H
