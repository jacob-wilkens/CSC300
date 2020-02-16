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
    if(!this->head)
    {
        this->addFront(payload);
    }
    else
    {
        //we have at least one thing in our list
        //traverse to end of list and connect new node

        node* n = new node(payload);
        node* currNode = this->runToEndList();
        //currNode now points to the end of our list (ie the last Node)
        currNode->setNextNode(n);
        this->count++;

    } 
}

int linkedList::getEnd() {
    int endValue = -1;
    node* currNode = this->head;
    
    for(int i = 1; i <= this->count; i++) {
            
        if(i == count) {
            endValue = currNode->getPayload();
            return endValue;
        }
        currNode = currNode->getNextNode();
            
        }
    return endValue;    

}

int linkedList::removeEnd() {
     
    /*int endValue = -1;
    node* currNode = this->head;

    for(int i = 1; i <= this->count; i++) {
            
        if(i == count) {
            endValue = currNode->getPayload();
            delete currNode;
            this->count--;
            return endValue;
        }

        currNode = currNode->getNextNode();
            
        }
    return endValue;*/

    //we are assuming the list has at least one element in it for now
    //is this a list with a single element in it?
    if(!this->head->getNextNode())
    {
        return this->removeFront();
    }
    else
    {
        //we have at least two elements in our list
        node* lastNode = this->runToEndList();
        node* secondLast = this->head;
        while(secondLast->getNextNode() != lastNode)
        {
            secondLast = secondLast->getNextNode();
        }
        //theGuyBeforeTheLastGuy now points to the Node right before theLastGuy
        secondLast->setNextNode(0);
        int valueToReturn = lastNode->getPayload();
        delete lastNode;
        this->count--;
        return valueToReturn;
    }
    

}

node* linkedList::runToEndList() {
    node* currNode = this->head;
    while(currNode->getNextNode()) //returns true when currNode has a next node
    {
        currNode = currNode->getNextNode(); // (*currNode).getNextNode()
    }
    return currNode;

}
void linkedList::addAtIndex(int index, int payload) {

    if(this->count == 0 || index == 0) {
        this->addFront(payload);
    } else if (index >= this->count) {
        this->addEnd(payload);
    } else {
        node* newNode = new node(payload);
        node* currNode = this->head;
        for(int i = 0; i<= index; i++) {
            if(i == index - 1) {
                newNode->setNextNode(currNode->getNextNode());
                currNode->setNextNode(newNode);
                this->count++;
                break;
            }
            currNode = currNode->getNextNode();
        }
    }
    
}
int linkedList::getIndex(int index) {
    int valAtIndex;
    
    if(index == 0) {
        valAtIndex = getFront();
        return valAtIndex;
        
    } else if (index >= this->count){
        valAtIndex = getEnd();
        return valAtIndex;
    } else {
        node* currNode = this->head;
        for(int i = 0; i <= index; i++) {
            
            if(i == index) {
                valAtIndex = currNode->getPayload();
                return valAtIndex;
            }

            currNode = currNode->getNextNode();
        }
    }
       
}
int linkedList::removeIndex(int index) {
    int valAtIndex;
    
    if(index == 0) {
        valAtIndex = removeFront();
        return valAtIndex;
    } else if (index >= this->count){
        valAtIndex = removeEnd();
        return valAtIndex;
    } else {
        node* currNode = this->head;
        node* beforeIndex = NULL;

        for(int i = 0; i <= index; i++) {
            if(i == index - 1) {
                beforeIndex = currNode;
            }
            if(i == index) {
                valAtIndex = currNode->getPayload();
                beforeIndex->setNextNode(currNode->getNextNode());
                currNode->setNextNode(0);
                delete currNode;
                this->count--;
                return valAtIndex;

            }
            currNode = currNode->getNextNode();
        }
    }
}
