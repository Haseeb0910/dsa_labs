#include<iostream>
#include"bst.h"
using namespace std;

int main()
{
    bst<int> b;
    b.insert(50);
    b.insert(20);
    b.insert(40);
    b.insert(60);
    b.insert(70);
    b.insert(10);
    b.inOrder();
    cout << b.recSearch(60) << endl;
    cout << "Count: " << b.countNodes() << endl;
    cout << "Height: " << b.getHeight() << endl;
    // b.doubleTree();
    b.printAllPaths();
    b.inOrder();
}