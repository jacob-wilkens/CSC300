#include "node.hpp"

node::node(int payload) {
    this ->payload = payload;
}

void node::setNextNode(node* newNode) {
    this->nextNode = newNode;
}