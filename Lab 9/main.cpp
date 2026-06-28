#include <iostream>
#include "binaryTreeLL.h"
using namespace std;

int main()
{
    cout << "=== BINARY TREE LINKED LIST IMPLEMENTATION TEST ===" << endl;

    // Test 1: Create tree and set root
    cout << "\n1. Creating tree and setting root..." << endl;
    binaryTreeLL<int> tree;
    tree.setRoot(1);
    cout << "Root: " << tree.getRoot() << endl;

    // Test 2: Add children
    cout << "\n2. Adding children..." << endl;
    tree.setLeftChild(1, 2);
    tree.setRightChild(1, 3);
    tree.setLeftChild(2, 4);
    tree.setRightChild(2, 5);
    tree.setLeftChild(3, 6);
    tree.setRightChild(3, 7);

    // Test 3: Tree traversals
    cout << "\n3. Tree Traversals:" << endl;
    cout << "Pre-order: ";
    tree.preOrderDisplay();

    cout << "In-order: ";
    tree.inOrderDisplay();

    cout << "Post-order: ";
    tree.postOrderDisplay();

    cout << "Level-order: ";
    tree.levelOrderDisplay();

    // Test 4: Tree properties
    cout << "\n4. Tree Properties:" << endl;
    cout << "Height: " << tree.getHeight() << endl;
    cout << "Is 4 internal node? " << (tree.isInternalNode(4) ? "Yes" : "No") << endl;
    cout << "Is 4 external node? " << (tree.isExternalNode(4) ? "Yes" : "No") << endl;
    cout << "Is 1 internal node? " << (tree.isInternalNode(1) ? "Yes" : "No") << endl;
    cout << "Is 1 external node? " << (tree.isExternalNode(1) ? "Yes" : "No") << endl;

    // Test 5: Level operations
    cout << "\n5. Level Operations:" << endl;
    cout << "Level of node 5: " << tree.levelNo(5) << endl;
    cout << "Level of node 1: " << tree.levelNo(1) << endl;
    cout << "Nodes at level 1: ";
    tree.displayLevel(1);
    cout << "Sum of level 2: " << tree.levelSum(2) << endl;

    // Test 6: Siblings
    cout << "\n6. Sibling Tests:" << endl;
    cout << "Sibling of 2: " << tree.findNodeSiblings(2) << endl;
    cout << "Sibling of 4: " << tree.findNodeSiblings(4) << endl;
    cout << "Sibling of 1: " << tree.findNodeSiblings(1) << endl;

    // Test 7: Ancestors and Descendants
    cout << "\n7. Ancestors and Descendants:" << endl;
    cout << "Ancestors of 5: ";
    tree.displayAncestors(5);
    cout << endl;
    cout << "Descendants of 2: ";
    tree.displayDescendents(2);
    cout << endl;

    // Test 8: Parenthesized View
    cout << "\n8. Parenthesized View:" << endl;
    cout << "Parenthesized: ";
    tree.displayParenthesizedView();

    // Test 9: Copy Constructor
    cout << "\n9. Copy Constructor Test:" << endl;
    binaryTreeLL<int> treeCopy(tree);
    cout << "Original tree level-order: ";
    tree.levelOrderDisplay();
    cout << "Copied tree level-order: ";
    treeCopy.levelOrderDisplay();

    // Test 10: Assignment Operator
    cout << "\n10. Assignment Operator Test:" << endl;
    binaryTreeLL<int> treeAssigned;
    treeAssigned = tree;
    cout << "Original tree level-order: ";
    tree.levelOrderDisplay();
    cout << "Assigned tree level-order: ";
    treeAssigned.levelOrderDisplay();

    // Test 11: Mirror Image
    cout << "\n11. Mirror Image Test:" << endl;
    binaryTreeLL<int> mirrorTree = tree.getMirrorImage();
    cout << "Original tree in-order: ";
    tree.inOrderDisplay();
    cout << "Mirror tree in-order: ";
    mirrorTree.inOrderDisplay();

    // Test 12: Remove operation
    cout << "\n12. Remove Operation Test:" << endl;
    cout << "Before removal - Level order: ";
    tree.levelOrderDisplay();
    tree.remove(4);
    cout << "After removing 4 - Level order: ";
    tree.levelOrderDisplay();

    // Test 13: Error cases
    cout << "\n13. Error Case Tests:" << endl;
    tree.setLeftChild(99, 100); // Non-existent parent
    tree.setRightChild(1, 8);   // Right child already exists
    tree.remove(99);            // Non-existent node

    // Test 14: Empty tree operations
    cout << "\n14. Empty Tree Tests:" << endl;
    binaryTreeLL<int> emptyTree;
    cout << "Empty tree root: " << emptyTree.getRoot() << endl;
    cout << "Empty tree height: " << emptyTree.getHeight() << endl;
    emptyTree.levelOrderDisplay();

    cout << "=== All Tests Completed ===" << endl;

    return 0;
}