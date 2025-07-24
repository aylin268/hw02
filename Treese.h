#ifndef TREESE_H
#define TREESE_H

#include <string>
#include <cstddef> // for size_t
#include <stdexcept> // for std::out_of_range

class Treese {
private:
    struct Node {
        bool leaf;

        Node* left;
        Node* right;
        size_t height;
        size_t length;
        std:: string data;




//no children 
//LN = leaf Node
//constructor for leaf node 
        Node(const std::string& LN ){
            leaf = true ;
            length = LN.length();
            data = LN;
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


        void updateHeight() {
            size_t leftHeight = left ? left->height : 0;
            size_t rightHeight = right ? right->height : 0;
            height = 1 + std::max(leftHeight, rightHeight);
    };



    Node* root;


    void destroy(Node* node);
    Node* copy(Node* node);
    char at(Node* node, size_t index) const;
    void print(Node* node) const;

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
