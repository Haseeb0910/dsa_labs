#include<iostream>
#include"LSLL.h"

using namespace std;

int main()
{
    LSLL<int> list;
    list.insertAtTail(23);
    list.insertAtTail(5);
    list.insertAtTail(4);
    list.insertAtTail(23);
    list.insertAtTail(6);
    list.insertAtTail(78);
    list.insertAtTail(4);
    list.insertAtTail(5);
    list.display();
    list.removeDuplicates();
    list.display();
}