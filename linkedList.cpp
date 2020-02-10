#include "linkedList.hpp"

linkedList::linkedList() {
    this->count = 0;
}

void linkedList::addFront(int payload) {
    node* tempNode = new node(payload);

    if(this->count = 0) {
        this->head = tempNode;
        
    } else {
        tempNode->setNextNode(this->head);
        this->head = tempNode;
    }

    this->count++;

}