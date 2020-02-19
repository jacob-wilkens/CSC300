#include <iostream>
#include <string>
#include "linkedList.hpp"
#include "ctime"

using namespace std;

int main()
{   
    /*std::srand(std::time(nullptr));
    linkedList* ll = new linkedList();
    for(int i = 0; i < 10; i++) {
        int rand = std::rand();
        ll->addEnd(rand & 1000);
    }
    ll->display();
    ll->sort();
    std::cout << "\n";
    ll->display();
    delete ll;*/

    linkedList* ll = new linkedList();
    for(int i = 1; i<= 20; i+=2){
        ll->addFront(i);
    }
    ll->display();
    ll->sort();
    std::cout << "sorted " << "\n";
    ll->display();
}
