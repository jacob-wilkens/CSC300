#include "linkedList.hpp"
#include <iostream>
template<typename T, size_t n>
void print_array(T const(& arr)[n])
{
	for (size_t i = 0; i < n; i++)
		std::cout << arr[i] << ' ';
}


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

void linkedList::sort(){
    /*int arr[this->count];
    for(int i = 0; i < this->count; i++){
        int val = this->getIndex(i);
        arr[i] = val;
    }
   for (int i = 0; i < this->count; i++) {
      int min = i;
      for (int j = i + 1; j < this->count; j++)
         if (arr[j] < arr[min]){
            min = j;
         }
      int temp = arr[i];
      arr[i] = arr[min];
      arr[min] = temp;
   }

    for(int i = 0; i < this->count; i++){
        this->getNodeAtIndex(i)->setPayload(arr[i]);
    }*/
    if(this->count > 1){

        int curFollowerPos;
        node* theFollower;
        node* temp;

        for(int curPos = 1; curPos < this->count; curPos++){
            curFollowerPos = curPos;
            theFollower = this->getNodeAtIndex(curPos);

        while(curFollowerPos > 0 ){
            temp = this->getNodeAtIndex(curFollowerPos - 1);

            if(theFollower->getPayload() < temp->getPayload()){
                temp->setNextNode(theFollower->getNextNode());
                theFollower->setNextNode(temp);

                if(curFollowerPos == 1){
                    this->head = theFollower;
                } else {
                    temp = this->getNodeAtIndex(curFollowerPos - 2);
                    temp->setNextNode(theFollower);
                }
                curFollowerPos --;
            } else{
                break;
            }

         }
        }
    } 


}
node* linkedList::getNodeAtIndex(int index)
{
    if(index == 0)
    {
        return this->head;
    }
    else
    {
        node* currNode = this->head; //gives us a second pointers to the front of the list
        for(int i = 0; i < index; i++)
        {
            currNode = currNode->getNextNode();
        }
        return currNode;
    }
}