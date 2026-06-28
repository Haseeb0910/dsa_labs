#ifndef BINARY_TREE_LL_H
#define BINARY_TREE_LL_H

#include <iostream>
#include "Queue.h"
#include <cmath>
using namespace std;

template <typename T>
class Node
{
public:
    T data;
    Node<T> *left;
    Node<T> *right;

    Node(T val)
    {
        data = val;
        left = nullptr;
        right = nullptr;
    }

    ~Node()
    {
        delete left;
        delete right;
    }
};

template <typename T>
class binaryTreeLL
{
private:
    Node<T> *root;

    Node<T> *search(Node<T> *curr, T val)
    {
        if (curr == nullptr)
            return nullptr;
        if (curr->data == val)
            return curr;

        Node<T> *t = search(curr->left, val);
        if (t == nullptr)
            t = search(curr->right, val);
        return t;
    }

    Node<T> *getParent(Node<T> *curr, T val)
    {
        if (curr == nullptr || curr->data == val)
            return nullptr;
        if ((curr->left != nullptr && curr->left->data == val) || (curr->right != nullptr && curr->right->data == val))
        {
            return curr;
        }
        Node<T> *t = getParent(curr->left, val);
        if (t == nullptr)
            t = getParent(curr->right, val);
        return t;
    }

    void preOrderDisplay(Node<T> *curr)
    {
        if (curr == nullptr)
            return;

        cout << curr->data << " ";
        preOrderDisplay(curr->left);
        preOrderDisplay(curr->right);
    }

    void postOrderDisplay(Node<T> *curr)
    {
        if (curr == nullptr)
            return;

        postOrderDisplay(curr->left);
        postOrderDisplay(curr->right);
        cout << curr->data << " ";
    }

    void inOrderDisplay(Node<T> *curr)
    {
        if (curr == nullptr)
            return;

        inOrderDisplay(curr->left);
        cout << curr->data << " ";
        inOrderDisplay(curr->right);
    }

    int getHeight(Node<T> *curr)
    {
        if (curr == nullptr)
        {
            return 0;
        }

        int left = getHeight(curr->left);
        int right = getHeight(curr->right);
        return 1 + max(left, right);
    }

    void displayParenthesizedView(Node<T> *curr)
    {
        if (curr == nullptr)
            return;

        cout << curr->data << " ";
        if (curr->left == nullptr && curr->right == nullptr)
            return;
        cout << "( ";
        displayParenthesizedView(curr->left);
        if (curr->left == nullptr)
            cout << " , ";
        displayParenthesizedView(curr->right);
        if (curr->right == nullptr)
            cout << ",";
        cout << " )";
    }

    void getMirrorImage(Node<T> *curr)
    {
        if (curr == nullptr)
        {
            return;
        }

        swap(curr->left, curr->right);
        getMirrorImage(curr->left);
        getMirrorImage(curr->right);
    }

    Node<T> *deepCopyHelp(Node<T> *curr)
    {
        if (curr == nullptr)
        {
            return nullptr;
        }
        Node<T> *newNode = new Node<T>(curr->data);
        newNode->left = deepCopyHelp(curr->left);
        newNode->right = deepCopyHelp(curr->right);
        return newNode;
    }

public:
    binaryTreeLL()
    {
        root = nullptr;
    }

    void setRoot(T val)
    {
        if (root == nullptr)
        {
            root = new Node<T>(val);
        }
    }

    T getRoot()
    {
        if (root != nullptr)
        {
            return root->data;
        }
        else
        {
            cout << "Tree is empty." << endl;
            return T();
        }
    }

    int getHeight()
    {
        int height = getHeight(root);
        return height;
    }

    void setLeftChild(T parentVal, T childVal)
    {
        Node<T> *p = search(root, parentVal);
        if (p != nullptr)
        {
            if (p->left == nullptr)
                p->left = new Node<T>(childVal);
            else
                cout << "Left child of " << parentVal << " already exist." << endl;
        }
        else
            cout << "Parent Node(" << parentVal << ") does not exist." << endl;
    }

    void setRightChild(T parentVal, T childVal)
    {
        Node<T> *p = search(root, parentVal);
        if (p != nullptr)
        {
            if (p->right == nullptr)
                p->right = new Node<T>(childVal);
            else
                cout << "Right child of " << parentVal << " already exist." << endl;
        }
        else
            cout << "Parent Node(" << parentVal << ") does not exist." << endl;
    }

    void remove(T val)
    {
        if (root == nullptr)
        {
            cout << "Tree is empty." << endl;
            return;
        }
        if (root->data == val)
        {
            delete root;
            root = nullptr;
            return;
        }
        Node<T> *p = getParent(root, val);
        if (p != nullptr)
        {
            if (p->left != nullptr && p->left->data == val)
            {
                delete p->left;
                p->left = nullptr;
            }
            else if (p->right != nullptr && p->right->data == val)
            {
                delete p->right;
                p->right = nullptr;
            }
        }
        else
        {
            cout << "Node(" << val << ") does not exist." << endl;
        }
    }

    void preOrderDisplay()
    {
        preOrderDisplay(root);
        cout << endl;
    }

    void postOrderDisplay()
    {
        postOrderDisplay(root);
        cout << endl;
    }

    void inOrderDisplay()
    {
        inOrderDisplay(root);
        cout << endl;
    }

    void levelOrderDisplay()
    {
        if (root == nullptr)
        {
            cout << "Tree is empty." << endl;
            return;
        }
        myQueue<Node<T>*> q;
        q.enQueue(root);
        while (!q.isEmpty())
        {
            Node<T> *curr = q.deQueue();
            cout << curr->data << " ";
            if (curr->left)
                q.enQueue(curr->left);
            if (curr->right)
                q.enQueue(curr->right);
        }
        cout << endl;
    }

    void displayAncestors(T val)
    {
        if (val == getRoot())
            return;
        Node<T> *par = getParent(root, val);
        cout << par->data << " ";
        displayAncestors(par->data);
    }

    void displayDescendents(T val)
    {
        Node<T> *s = search(root, val);
        inOrderDisplay(s->left);
        inOrderDisplay(s->right);
    }

    void displayLevel(int levelNo)
    {
        if (root == nullptr)
        {
            cout << "Tree is empty." << endl;
            return;
        }

        myQueue<Node<T> *> q;
        int count = 0;
        q.enQueue(root);
        while (!q.isEmpty())
        {
            if (count == levelNo)
            {
                while (!q.isEmpty())
                {
                    Node<T> *curr = q.deQueue();
                    cout << curr->data << " ";
                }
                return;
            }
            count++;

            int qSize = q.Size();
            for (int i = 0; i < qSize; i++)
            {
                Node<T> *next = q.deQueue();
                if (next->left)
                    q.enQueue(next->left);
                if (next->right)
                    q.enQueue(next->right);
            }
        }
    }

    int levelSum(int levelNo)
    {
        if (root == nullptr)
        {
            cout << "Tree is empty." << endl;
            return 0;
        }

        myQueue<Node<T> *> q;
        int count = 0;
        int sum = 0;
        q.enQueue(root);
        while (!q.isEmpty())
        {
            if (count == levelNo)
            {
                while (!q.isEmpty())
                {
                    Node<T> *curr = q.deQueue();
                    sum += curr->data;
                }
                return sum;
            }
            count++;

            int qSize = q.Size();
            for (int i = 0; i < qSize; i++)
            {
                Node<T> *next = q.deQueue();
                if (next->left)
                    q.enQueue(next->left);
                if (next->right)
                    q.enQueue(next->right);
            }
        }
    }

    int levelNo(T val)
    {
        if (root == nullptr)
        {
            cout << "Tree is empty." << endl;
            return -1;
        }
        if (search(root, val) == nullptr)
        {
            cout << "Node not present." << endl;
            return -1;
        }
        if (val == getRoot())
        {
            return 0;
        }

        Node<T> *par = getParent(root, val);
        int level = levelNo(par->data);
        return 1 + level;
    }

    T findNodeSiblings(T val)
    {
        if (val == getRoot())
        {
            cout << "Root does not have siblings." << endl;
            return T();
        }
        Node<T> *par = getParent(root, val);
        if (par->left->data == val)
        {
            if (par->right)
                return par->right->data;
            else
            {
                cout << "Sibling does not exist." << endl;
                return T();
            }
        }
        if (par->right->data == val)
        {
            if (par->left)
                return par->left->data;
            else
            {
                cout << "Sibling does not exist." << endl;
                return T();
            }
        }
        return T();
    }

    bool isInternalNode(T val)
    {
        Node<T> *n = search(root, val);
        if (n == nullptr)
            return false;
        if (n->left != nullptr || n->right != nullptr)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    bool isExternalNode(T val)
    {
        Node<T> *n = search(root, val);
        if (n == nullptr)
            return false;
        if (n->left == nullptr && n->right == nullptr)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    void displayParenthesizedView()
    {
        displayParenthesizedView(root);
        cout << endl;
    }

    binaryTreeLL<T>& operator=(binaryTreeLL<T> &other)
    {
        if (this != &other)
        {
            delete root;
            root = nullptr;

            if (other.root != nullptr)
            {
                root = deepCopyHelp(other.root);
            }
        }
        return *this;
    }

    binaryTreeLL(const binaryTreeLL<T> &other)
    {
        root = deepCopyHelp(other.root);
    }

    binaryTreeLL<T> getMirrorImage()
    {
        binaryTreeLL<T> mirrorTree; 
        if (root != nullptr)
        {
            mirrorTree.root = deepCopyHelp(root);
            mirrorTree.getMirrorImage(mirrorTree.root);
        }
        return mirrorTree;
    }

    ~binaryTreeLL()
    {
        delete root;
    }
};
#endif
