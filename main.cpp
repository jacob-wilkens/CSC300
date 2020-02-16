#include <iostream>
#include <string>
#include "linkedList.hpp"

using namespace std;

int main()
{   
    linkedList* ll = new linkedList();
    ll->addFront(4);
    ll->addFront(3);
    ll->addAtIndex(1,5);
    ll->addAtIndex(1,6);
    ll->display();
    int val = ll->removeIndex(1);
    std::cout << val << " This was deleted"<< "\n";
    ll->display();
    delete ll;
}