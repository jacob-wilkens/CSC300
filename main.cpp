#include <iostream>
#include <string>
#include "linkedList.hpp"
#include "ctime"

using namespace std;

int main()
{   
    linkedList* ll = new linkedList();
    for(int i = 1; i<= 66; i+=2){
        ll->addFront(i);
    }
    ll->display();
    ll->sort();
    std::cout << "sorted " << "\n";
    ll->display();
}
