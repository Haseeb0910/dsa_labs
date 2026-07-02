#ifndef BINARY_SEARCH_TREE
#define BINARY_SEARCH_TREE

#include <iostream>
#include <vector>
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
};

template <typename T>
class bst
{
private:
    Node<T> *root;

    Node<T> *findMin(Node<T> *curr)
    {
        while (curr->left != nullptr)
        {
            curr = curr->left;
        }
        return curr;
    }

    Node<T> *findMax(Node<T> *curr)
    {
        while (curr->right != nullptr)
        {
            curr = curr->right;
        }
        return curr;
    }

    void preOrder(Node<T> *curr)
    {
        if (curr != nullptr)
        {
            cout << curr->data << " ";
            preOrder(curr->left);
            preOrder(curr->right);
        }
    }

    void postOrder(Node<T> *curr)
    {
        if (curr != nullptr)
        {
            postOrder(curr->left);
            postOrder(curr->right);
            cout << curr->data << " ";
        }
    }

    void inOrder(Node<T> *curr)
    {
        if (curr != nullptr)
        {
            inOrder(curr->left);
            cout << curr->data << " ";
            inOrder(curr->right);
        }
    }

    void destroy(Node<T> *curr)
    {
        if (curr == nullptr)
            return;
        destroy(curr->left);
        destroy(curr->right);
        delete curr;
    }

    bool recSearch(Node<T> *curr, T val)
    {
        if (curr == nullptr)
            return false;
        if (curr->data == val)
            return true;
        if (val < curr->data)
            recSearch(curr->left, val);
        else
            recSearch(curr->right, val);
    }

    int countNodes(Node<T> *curr)
    {
        if (curr == nullptr)
            return 0;
        return 1 + countNodes(curr->left) + countNodes(curr->right);
    }

    int getHeight(Node<T> *curr)
    {
        if (curr == nullptr)
            return 0;
        int left = getHeight(curr->left);
        int right = getHeight(curr->right);
        return 1 + max(left, right);
    }

    void doubleTree(Node<T> *curr)
    {
        if (curr == nullptr)
            return;
        doubleTree(curr->left);
        doubleTree(curr->right);
        T val = curr->data;
        Node<T> *newNode = new Node<T>(val);
        newNode->left = curr->left;
        curr->left = newNode;
    }

    void printAllPaths(Node<T> *node, T arr[], int size)
    {
        if (node == nullptr)
        {
            return;
        }
        arr[size] = node->data;
        size++;
        if (node->left == nullptr && node->right == nullptr)
        {
            for (int i = 0; i < size; i++)
            {
                cout << arr[i] << " ";
            }
            cout << endl;
        }
        printAllPaths(node->left, arr, size);
        printAllPaths(node->right, arr, size);
        size--;
    }

    void construct_from_traversals(Node<T> *curr, vector<T> in_order, vector<T> pre_order)
    {
        if (in_order.size() == 0 || pre_order.size() == 0)
            return;
        if (curr == nullptr)
            return;
        T r = pre_order[0];
        insert(r);
        int i = 0;
        while (in_order[i] < r)
        {
            insert(in_order[i]);
            i++;
        }
        i++;
        while (i < in_order.size())
        {
            insert(in_order[i]);
            i++;
        }
        construct_from_traversals(curr->left, in_order, pre_order);
        construct_from_traversals(curr->right, in_order, pre_order);
    }

    Node<T> *LL_rotation(Node<T> *curr)
    {
        Node<T> *ch = curr->left;
        curr->left = ch->right;
        ch->right = curr;
        return ch;
    }

    Node<T>* RR_rotation(Node<T> *curr, int diff)
    {
        if (diff == 0)
            return nullptr;
        Node<T> *ch = curr->right;
        curr->right = ch->left;
        ch->left = curr;
        return ch;
        RR_rotation(curr->right, diff - 1);
    }

    Node<T> *RR_rotation(Node<T> *curr)
    {
        Node<T> *ch = curr->right;
        curr->right = ch->left;
        ch->left = curr;
        return ch;
    }

public:
    bst()
    {
        root = nullptr;
    }

    void insert(T val)
    {
        if (root == nullptr)
        {
            root = new Node<T>(val);
            return;
        }
        Node<T> *curr = root;
        Node<T> *par = nullptr;
        while (curr != nullptr)
        {
            par = curr;
            if (val < curr->data)
            {
                curr = curr->left;
            }
            else
            {
                curr = curr->right;
            }
        }
        if (val < par->data)
            par->left = new Node<T>(val);
        else
            par->right = new Node<T>(val);
    }

    bool search(T val)
    {
        Node<T> *curr = root;
        while (curr != nullptr)
        {
            if (curr->data == val)
                return true;
            else if (val < curr->data)
                curr = curr->left;
            else
                curr = curr->right;
        }
        return false;
    }

    bool recSearch(T val)
    {
        recSearch(root, val);
    }

    int countNodes()
    {
        int count = countNodes(root);
        return count;
    }

    int getHeight()
    {
        int height = getHeight(root);
        return height;
    }

    Node<T> *findMin()
    {
        Node<T> *min = findMin(root);
        return min;
    }

    Node<T> *findMax()
    {
        Node<T> *max = findMax(root);
        return max;
    }

    void deleteNode(T val)
    {
        if (root == nullptr)
            return;

        Node<T> *curr = root;
        Node<T> *par = nullptr;
        while (curr != nullptr && curr->data != val)
        {
            par = curr;
            if (val < curr->data)
                curr = curr->left;
            else if (val > curr->data)
                curr = curr->right;
        }

        if (curr == nullptr)
            return;

        // node with no child
        if (curr->left == nullptr && curr->right == nullptr)
        {
            if (par == nullptr)
            {
                delete root;
                root = nullptr;
            }
            else if (val < par->data)
            {
                delete curr;
                par->left = nullptr;
            }
            else
            {
                delete curr;
                par->right = nullptr;
            }
            return;
        }
        // only left child
        if (curr->left != nullptr && curr->right == nullptr)
        {
            if (par == nullptr)
            {
                root = curr->left;
            }
            else if (par->left == curr)
            {
                par->left = curr->left;
            }
            else
            {
                par->right = curr->left;
            }
            curr->left = nullptr;
            delete curr;
            return;
        }
        // only right child
        if (curr->left == nullptr && curr->right != nullptr)
        {
            if (par == nullptr)
            {
                root = curr->right;
            }
            else if (par->left == curr)
            {
                par->left = curr->right;
            }
            else
            {
                par->right = curr->right;
            }
            curr->right = nullptr;
            delete curr;
            return;
        }
        // node with both child
        if (curr->left != nullptr && curr->right != nullptr)
        {
            Node<T> *rightMin = findMin(curr->right);
            T minValue = rightMin->data;
            deleteNode(minValue);
            curr->data = minValue;
            return;
        }
    }

    void preOrder()
    {
        preOrder(root);
        cout << endl;
    }

    void postOrder()
    {
        postOrder(root);
        cout << endl;
    }

    void inOrder()
    {
        inOrder(root);
        cout << endl;
    }

    void doubleTree()
    {
        doubleTree(root);
    }

    void printAllPaths()
    {
        int arr[100];
        printAllPaths(root, arr, 0);
    }

    void construct_from_traversals(vector<T> in_order, vector<T> pre_order)
    {
        construct_from_traversals(root, in_order, pre_order);
    }

    void createBalancedTree(T *arr, T start, T end)
    {
        int mid = (start + end) / 2;
        if (start > end)
        {
            return;
        }
        insert(arr[mid]);
        createBalancedTree(arr, start, mid - 1);
        createBalancedTree(arr, mid + 1, end);
    }

    void convertToBackbone()
    {
        Node<T> *temp = root;
        while (temp != nullptr)
        {
            if (temp->left)
                temp = LL_rotation(temp->left);
            else
                temp = temp->right;
        }
    }

    void createPerfectTree()
    {
        int n = countNodes(root);
        int m = 2 * ceil((log2(n + 1))) - 1;
        int diff = n - m;
        root = RR_rotation(root, diff);
        while (m > 1)
        {
            m = m / 2;
            root = RR_rotation(root);
            root = root->right;
        }
    }

    ~bst()
    {
        destroy(root);
        root = nullptr;
    }
};

#endif