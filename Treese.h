#ifndef TREESE_H
#define TREESE_H

#include <string>
#include <cstddef> 
#include <stdexcept> 
#include <iostream>

class Treese {
private:
    struct Node {
        bool leaf;

        Node* left;
        Node* right;
     
     
        size_t length;
        std::string data;




//no children 
//LN = leaf Node
//constructor for leaf node 
        Node(const std::string& str ){
            leaf = true ;
            length = str.length();
            data = str;
            left = nullptr; //empty 
            right = nullptr; //empty 
        }

//costructor for not leaf node
        Node(Node* L, Node* R){
            leaf = false;
            length = 0;
            left= L;
            right = R;
            if (left) length += left->length;
            if (right) length += right->length;
        }

    };


    Node* root;


    void destroy(Node* node);
    Node* copy(Node* node) const;
    char at(Node* node, size_t index) const;
    

    // your code here
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
