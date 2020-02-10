#include <iostream>
#include <string>
#include "linkedList.hpp"

using namespace std;

int main(int argc, const char * argv[])
{   
    linkedList* myList = new linkedList();
    myList->addFront(5);
    delete myList;

    return 0;
}