#include <iostream>
#include "CDLL.h"

using namespace std;

int main()
{
    CDLL<int> l1;
    CDLL<int> l2;
    CDLL<int> l3;
    l1.insertAtTail(1);
    l1.insertAtTail(3);
    l1.insertAtTail(5);
    l1.insertAtTail(6);
    l1.insertAtTail(8);
    l1.insertAtTail(12);
    l1.insertAtTail(14);

    l1.splitList(l2, l3);

    l1.display();
    l2.display();
    l3.display();
}