#include "Treese.h"

// Constructors and Destructor
Treese::Treese() : root(nullptr) {}

Treese::Treese(const std::string& initial) {
    root = new Node(initial);
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

Treese::~Treese() {
    destroy(root);
}

// Public methods
size_t Treese::length() const {
    return root ? root->length : 0;
}

char Treese::at(size_t index) const {
    if (!root || index >= root->length) {
        throw std::out_of_range("Index out of bounds");
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

// Private helpers
void Treese::destroy(Node* node) {
    if (!node) return;
    destroy(node->left);
    destroy(node->right);
    delete node;
}

Treese::Node* Treese::copy(Node* node) const {
    if (!node) return nullptr;
    if (node->leaf) {
        return new Node(node->data);
    }
    return new Node(copy(node->left), copy(node->right));
}

char Treese::getCharAt(Node* node, size_t index) const {
    if (!node) throw std::out_of_range("Invalid node");
    if (node->leaf) {
        return node->data[index];
    }
    if (index < node->left->length) {
        return getCharAt(node->left, index);
    } else {
        return getCharAt(node->right, index - node->left->length);
    }
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
