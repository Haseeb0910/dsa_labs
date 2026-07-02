#include <iostream>
#include "bst.h"
using namespace std;

int main()
{
    bst<int> bst;
    int arr[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    int n = sizeof(arr) / sizeof(arr[0]);
    bst.createBalancedTree(arr, 0, n - 1);
    cout << "Pre-order: ";
    bst.preOrder();
    cout << "In-order: ";
    bst.inOrder();
    cout << "Post-order: ";
    bst.postOrder();
    return 0;
}