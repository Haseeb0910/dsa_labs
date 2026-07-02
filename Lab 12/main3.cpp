#include <iostream>
#include "bst.h"
using namespace std;

int main()
{
    bst<int> bst;
    bst.insert(1);
    bst.insert(5);
    bst.insert(10);
    bst.insert(20);
    bst.insert(25);
    bst.insert(30);
    bst.insert(35);
    bst.insert(40);
    bst.insert(45);

    cout << "Original BST  Height: " << bst.getHeight() << endl;

    cout << "\nOriginal BST (Inorder): ";
    bst.inOrder();
    cout << "\nOriginal BST Pre-order: ";
    bst.preOrder();

    cout << "\nOriginal BST Post-order: ";
    bst.postOrder();

    bst.createPerfectTree();

    cout<<"\nHeight After DSW: "<<bst.getHeight()<<endl;

    cout << "\nBalanced BST using DSW (Inorder): ";
    bst.inOrder();

    cout << "\nBalanced BST using (DSWPre-order:) ";
    bst.preOrder();

    cout << "\nBalanced BST using DSW (Post-order:) ";
    bst.postOrder();

    return 0;
}