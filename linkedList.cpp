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
 void linkedList::addAtIndex(int index, int payload)
 {
     if(index == 0)
     {
         this->addFront(payload);
     }
     else if(index == this->count)
     {
         this->addEnd(payload);
     }
     else
     {
         //we are placing somewhere in the middle
         node* n = new node(payload);
         node* currNode = this->head;
         for(int i = 0; i < index-1; i++)
         {
             currNode = currNode -> getNextNode();
         }
         //currNode points to the node right before where N should be inserted
         n->setNextNode(currNode->getNextNode());
         currNode->setNextNode(n);
         this->count++;
     }
     
 }
    
int linkedList::getIndex(int index)
{
    if(index == 0)
    {
        return this->getFront();
    }
    else if(index == this->count-1)
    {
        return this->getEnd();
    }
    else
    {
        node* currNode = this->head; //gives us a second pointers to the front of the list
        for(int i = 0; i < index; i++)
        {
            currNode = currNode->getNextNode();
        }
        return currNode->getPayload();
    }
}
 
int linkedList::removeIndex(int index)
{
    if(index == 0)
    {
        return this->removeFront();
    }
    else if(index == this->count-1)
    {
        return this->removeEnd();
    }
    else
    {
        node* currNode = this->head;
        for(int i = 0; i < index-1; i++)
        {
            currNode = currNode->getNextNode();
        }
        node* guy2Remove = currNode->getNextNode();
        currNode->setNextNode(guy2Remove->getNextNode());
        guy2Remove->setNextNode(0); //sets his next node to null
        
        int val2Return = guy2Remove->getPayload();
        delete guy2Remove;
        this->count--;
        return val2Return;
    }
    
}
void linkedList::displayPointers() {
    node* currentNode = this->head;
    for(int i = 0; i < this->count; i++) {
        std::cout << currentNode << "\n";
        currentNode = currentNode->getNextNode();
    }
}
int linkedList::lowestValue() {
    node* currNode = this->head;
    int lowestVal = this->head->getPayload();

    for(int i = 0; i < this->count; i++){
        if(currNode->getPayload() < lowestVal){
            lowestVal = currNode->getPayload();
        }
        currNode = currNode->getNextNode();
    }
    return lowestVal;
}
void linkedList::sort(){
    int index = 0;
    this->lowToHead();
    this->highToEnd();
    int i = 1;
    int x = 0;

    while(i < this->count - 2){
        int val = this->getIndex(i);
        for(int j = i; j <= this->count - 1; j++){
            int currentVal = this->getIndex(j);
            if(j == this->count - 1 && val != currentVal && index != 0){
                int lowest = this->getFront();
                int removed = this->removeIndex(index);

                this->addAtIndex(i, val);
            }
            if(currentVal < val){
                val = currentVal;
                index = j;
            }
        }
        i++;
    }

}
int linkedList::highestValue(){
    node* currNode = this->head;
    int highestVal = currNode->getPayload();

    for(int i = 1; i < this->count; i++){
        currNode = currNode->getNextNode();
        if(currNode->getPayload() > highestVal){
            highestVal = currNode->getPayload();
        }
    }
    return highestVal;
}
void linkedList::highToEnd(){

    int high = this->highestValue();
    int end = this->getEnd();

    node* currNode = this->head;

    for(int i = 0; i < this->count; i++){
        int val = this->getIndex(i);
        if(val == high){
            currNode->setPayload(end);
        }
        else if(i == this->count - 1){
            currNode->setPayload(high);
            break;
        }

        currNode = currNode->getNextNode();
    }
}
void linkedList::lowToHead(){

    int low = this->lowestValue();
    int front = this->head->getPayload();
    node* currNode = this->head;

    for(int i = 0; i < this->count; i++){
        int val = this->getIndex(i);
        if(i == 0){
            this->head->setPayload(low);
        }
        else if(val == low){
            currNode->setPayload(front);
            break;
        }

        currNode = currNode->getNextNode();
    }
}
