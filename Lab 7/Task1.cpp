#include<iostream>
#include"CDLL.h"

using namespace std;

int main()
{
    CDLL<int> l1;
    CDLL<int> l2;
    CDLL<int> l3;
    l1.insertAtTail(4);
    l1.insertAtTail(7);
    l1.insertAtTail(10);
    l1.insertAtTail(12);
    l2.insertAtTail(1);
    l2.insertAtTail(3);
    l2.insertAtTail(6);
    l2.insertAtTail(8);
    l2.insertAtTail(9);
    l2.insertAtTail(15);
    l3.merge(l1 , l2);
    l3.display();   
    l1.display();
    l2.display();
}