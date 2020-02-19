#ifndef linkedList_hpp
#define linkedList_hpp
#include "node.hpp"
using namespace std;
class linkedList {
    private:
        int count;
        node* head;
        node* runToEndList();
        
    public:
       linkedList();
       void addFront(int payload);
       void display();
       int getFront();
       int removeFront();
       void addEnd(int payload);    
       int getEnd();
       int removeEnd();
       void addAtIndex(int index, int payload);
       int getIndex(int index);
       int removeIndex(int index);
       void displayPointers();
       void sort(); // rearranges the list that it is in ascending numerical order
};
#endif