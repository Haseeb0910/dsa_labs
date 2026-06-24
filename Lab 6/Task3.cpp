#include<iostream>
#include"LSLL.h"

using namespace std;

int main()
{
    LSLL<int> list1;
    LSLL<int> list2;
    LSLL<int> list3;

    list1.insertAtTail(7);
    list1.insertAtTail(3);
    list1.insertAtTail(4);
    list1.insertAtTail(2);    

    list2.insertAtTail(5);    
    list2.insertAtTail(9);    

    list3.shuffleMerge(list1 , list2);
    list3.display();
    list1.display();
    list2.display();

}