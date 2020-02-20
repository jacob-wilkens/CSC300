#include "linkedList.hpp"
#include <iostream>
#include <ctime>

int main()
{
    std::srand(std::time(nullptr)); // use current time as seed for random generator
    linkedList* ll = new linkedList();

    for(int i = 0; i < 9; i++)
    {
        ll->addEnd(std::rand() % 1000);
    }
    ll->display();
    std::cout << "\n";
    ll->sort();
    std::cout << "\n";
    ll->display(); //it should now be sorted

}
