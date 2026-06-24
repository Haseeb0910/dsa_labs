#include <iostream>
#include "LSLL.h"

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
    int val = -1;
    list.removeKthNode(3, val);
    cout<< val << endl;
    list.display();
}