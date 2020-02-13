#include "linkedList.hpp"
#include <iostream>

linkedList::linkedList() {
    this->count = 0;
}

void linkedList::addFront(int payload) {
    node* tempNode = new node(payload);

    if(this->count == 0) {//list is currently empty
        this->head = tempNode;
        
    } else {//list has something else
        tempNode->setNextNode(this->head);
        this->head = tempNode;
    }

    this->count++;

}
void linkedList::display() {
    node* currentNode = this->head;
    for(int i = 0; i < this->count; i++) {
        std::cout << currentNode->getPayload() << "\n";
        currentNode = currentNode->getNextNode();
    }
}

int linkedList::getFront() {
    return this->head->getPayload();
}

int linkedList::removeFront() {
    node* nodeToReturn = this->head;
    this->head = this->head->getNextNode();
    int val = nodeToReturn->getPayload();
    this->count--;
    delete nodeToReturn;
}

void linkedList::addEnd(int payload) {
    node* newNode = new node(payload); //new node

    if(this->count == 1) {
        this->head = newNode;
    } else {
        node* currNode = this->head;//used to navigate list

        for(int i = 1; i <= this->count; i++) {
            
            if(i == this->count) {
                currNode->setNextNode(newNode);
                break;
            }
            currNode = currNode->getNextNode();
        }
    }
    this->count++;
}

int linkedList::getEnd() {
    int endValue = 0;
    node* currNode = this->head;

    if(this->count == 1) {
        endValue = currNode->getPayload();
        return endValue;

    } else {
        for(int i = 1; i <= this->count; i++) {
            
        if(i == count) {
            endValue = currNode->getPayload();
            return endValue;
        }
        currNode = currNode->getNextNode();
            
        }

     }
     return endValue;

}

int linkedList::removeEnd() {
     
    int endValue = 0;
    node* currNode = this->head;

    if(this->count == 1) {
        endValue = currNode->getPayload();
        delete currNode;
        this->count--;
        return endValue;
        
     } else {
        for(int i = 1; i <= this->count; i++) {
            
            if(i == count) {
                endValue = currNode->getPayload();
                delete currNode;
                this->count--;
                return endValue;
            }

            currNode = currNode->getNextNode();
            
        }

     }
     return endValue;

}