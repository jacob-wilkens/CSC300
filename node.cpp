#include "node.hpp"

node::node(int payload) {
    //this is a node*
    this ->payload = payload;
}

int node::getPayload() {
    return this->payload;
}

void node::setNextNode(node* newNode) {
    this->nextNode = newNode;
}

node* node::getNextNode() {
    return this->nextNode;
}