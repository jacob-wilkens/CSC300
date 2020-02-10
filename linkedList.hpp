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

};
#endif