#include "Treese.h"


//constructor
Treese::Treese() : root(nullptr) {}


//deconstructor
Treese::~Treese() {
    destroy(root);
}

Treese::Treese(const std::string& str) {
    root = new Node(str);
}

Treese::Treese(const Treese& other) {
    root = copy(other.root);
}


Treese& Treese::operator=(const Treese& other) {
    if (this != &other) {
        destroy(root);
        root = copy(other.root);
    }
    return *this;
}


size_t Treese::length() const {
    return root ? root->length : 0;
}

char Treese::at(size_t index) const {
    if (!root || index >= root->length) {
        throw std::out_of_range("Index out of range.");
    }
    return getCharAt(root, index);
}

void Treese::print() const {
    print(root);
    std::cout << std::endl;
}

Treese Treese::concat(const Treese& other) const {
    Treese result;
    result.root = new Node(copy(this->root), copy(other.root));
    return result;
}


void Treese::destroy(Node* node) {
    if (!node) return;
    destroy(node->left);
    destroy(node->right);
    delete node;
}


void Treese::print(Node* node) const {
    if (!node) return;

    if (node->leaf) {
        std::cout << node->data;
    } else {
        print(node->left);
        print(node->right);
    }
}


Treese::Node* Treese::copy(Node* node) const{
    if (!node) return nullptr;

    if (node->leaf) {
        return new Node(node->data);
    } else {
        return new Node(copy(node->left), copy(node->right));
    }
}

char Treese::getCharAt(Node* node, size_t index) const {
    if (node->leaf) {
        return node->dat[index];
    }

    size_t leftLength = node->left ? node->left->totalLength : 0;

    if (index < leftLength) {
        return getCharAt(node->left, index);
    } else {
        return getCharAt(node->right, index - leftLength);
    }
}

char Treese::at(size_t index) const {
    if (!root || index >= root->length) throw std::out_of_range("Index out of range.");
    return getCharAt(root, index); \
