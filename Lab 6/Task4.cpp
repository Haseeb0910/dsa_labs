#include<iostream>
#include"LSLL.h"

using namespace std;

int main()
{
    LSLL<int> list;
    list.insertAtHead(10);
    list.insertAtTail(20);  
    list.insertAtTail(30);
    list.insertAfter(20, 25);
    list.insertBefore(10, 5);
    list.display();
    list.reverse_list();
    list.display();
}