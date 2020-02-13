#ifndef linkedList_hpp
#define linkedList_hpp
#include "node.hpp"
class linkedList {
    private:
        int count;
        node* head;
        
    public:
       linkedList();
       void addFront(int payload);
       void display();
       int getFront();
       int removeFront();
       void addEnd(int payload);
       int getEnd();
       int removeEnd();
};
#endif