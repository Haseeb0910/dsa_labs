#include"binaryTreeArray.h"
#include<iostream>

using namespace std;

int main()
{
    binaryTree<char> b(5);
    b.setRoot('A');
    b.setLeftChild('A','B');
    b.setRightChild('A','C');
    b.setLeftChild('B','D');
    b.setRightChild('B','E');
    b.setRightChild('C','F');
    b.setRightChild('D','H');
    b.setLeftChild('E','I');
    b.setRightChild('E','J');
    b.setLeftChild('I','K');
    b.displayAncestors('D');
    cout << endl;
    b.displayDescendents('B');
    cout << endl;
    b.displayLevel(4);
    cout << b.findLevelOfNode('A') << endl;
}