#ifndef BINARY_TREE_H
#define BINARY_TREE_H

#include <cmath>
#include <iostream>
using namespace std;

template <typename T>
class binaryTree
{
private:
    bool *status;
    T *data;
    int height;
    int capacity;

    void rem(int parIndex)
    {
        if (status[parIndex] == false)
            return;
        if (parIndex >= capacity)
            return;

        status[parIndex] = false;
        rem(2 * parIndex + 1);
        rem(2 * parIndex + 2);
    }

    void preOrderDisplay(int parIndex)
    {
        if (status[parIndex] == false)
            return;
        if (parIndex >= capacity)
            return;

        cout << data[parIndex] << " ";
        preOrderDisplay(2 * parIndex + 1);
        preOrderDisplay(2 * parIndex + 2);
    }

    void postOrderDisplay(int parIndex)
    {
        if (status[parIndex] == false)
            return;
        if (parIndex >= capacity)
            return;

        postOrderDisplay(2 * parIndex + 1);
        postOrderDisplay(2 * parIndex + 2);
        cout << data[parIndex] << " ";
    }

    void inOrderDisplay(int parIndex)
    {
        if (status[parIndex] == false)
            return;
        if (parIndex >= capacity)
            return;

        inOrderDisplay(2 * parIndex + 1);
        cout << data[parIndex] << " ";
        inOrderDisplay(2 * parIndex + 2);
    }

    int getHeight(int parIndex)
    {
        if (status[parIndex] == false || parIndex >= capacity)
        {
            return 0;
        }

        int leftChild = getHeight(2 * parIndex + 1);
        int rightChild = getHeight(2 * parIndex + 2);

        return 1 + max(leftChild, rightChild);
    }

    void mirror(int parIndex)
    {
        if (parIndex >= capacity || status[parIndex] == false)
            return;
        int left = 2 * parIndex + 1;
        int right = 2 * parIndex + 2;
        if (left >= capacity && right >= capacity)
            return;
        if (left < capacity && right < capacity && status[left] && status[right])
        {
            T temp = data[left];
            data[left] = data[right];
            data[right] = temp;
        }
        else if (left < capacity && status[left] && (right >= capacity || !status[right]))
        {
            data[right] = data[left];
            status[right] = true;
            status[left] = false;
        }
        else if (right < capacity && status[right] && (left >= capacity || !status[left]))
        {
            data[left] = data[right];
            status[left] = true;
            status[right] = false;
        }
        mirror(left);
        mirror(right);
    }

    void paranthesized(int index)
    {
        if (status[index] == false || index >= capacity)
        {
            return;
        }
        int left = index * 2 + 1;
        int right = index * 2 + 2;
        cout << data[index];
        if (status[left] == false && status[right] == false)
        {
            return;
        }
        cout << "(";
            paranthesized(left);
        if (status[left] == false)
            cout << ",";
            paranthesized(right);
        if (status[right] == false)
            cout << ",";
        cout << ")";
    }    

public:
    binaryTree(int h)
    {
        height = h;
        capacity = pow(2, h) - 1;
        status = new bool[capacity]();
        data = new T[capacity];
    }

    void setRoot(T val)
    {
        if (status[0] == false)
        {
            data[0] = val;
            status[0] = true;
        }
    }

    T getRoot()
    {
        if (status[0] == true)
        {
            return data[0];
        }
        else
        {
            return -1;
        }
    }

    T getParent(T val)
    {
        for (int i = 1; i < capacity; i++)
        {
            if (status[i] && data[i] == val)
            {
                int par = (i - 1) / 2;
                if (status[par])
                {
                    return data[par];
                }
            }
        }
    }

    void displayAncestors(T val)
    {
        if(val == getRoot())
        {
            return;
        }

        T par = getParent(val);
        cout << par << " ";
        displayAncestors(par);
    }

    void displayDescendents(T val)
    {
       int index = search(val);
       inOrderDisplay(2*index+1);
       inOrderDisplay(2*index+2);
    }

    void displayLevel(int levelNo)
    {
        int startIndex = pow(2,levelNo) - 1;
        int maxNodes = pow(2,levelNo) + startIndex;
        for(int i = startIndex; i < maxNodes; i++)
        {
            if(status[i] == true)
            {
                cout << data[i] << " ";
            }
        }
        cout << endl;
    }

    int findLevelOfNode(T val)
    {
        if(val == getRoot())
        {
            return 0;
        }

        T par = getParent(val);
        int count = findLevelOfNode(par);
        return 1 + count;
    }

    void setLeftChild(T par, T val)
    {
        for (int i = 0; i < capacity; i++)
        {
            if (status[i] == true && data[i] == par)
            {
                if (((2 * i) + 1) < capacity && status[((2 * i) + 1)] == false)
                {
                    data[(2 * i) + 1] = val;
                    status[(2 * i) + 1] = true;
                    return;
                }
            }
        }
    }

    void setLeftChildIndex(int parIndex, T val)
    {
        if (status[parIndex] == true && parIndex < capacity)
        {
            if (((2 * parIndex) + 1) < capacity && status[((2 * parIndex) + 1)] == false)
            {
                data[(2 * parIndex) + 1] = val;
                status[(2 * parIndex) + 1] = true;
                return;
            }
        }
    }

    void setRightChild(T par, T val)
    {
        for (int i = 0; i < capacity; i++)
        {
            if (status[i] == true && data[i] == par)
            {
                if (((2 * i) + 2) < capacity && status[((2 * i) + 2)] == false)
                {
                    data[(2 * i) + 2] = val;
                    status[(2 * i) + 2] = true;
                    return;
                }
            }
        }
    }

    void setRightChildIndex(int parIndex, T val)
    {
        if (status[parIndex] == true && parIndex < capacity)
        {
            if (((2 * parIndex) + 2) < capacity && status[((2 * parIndex) + 2)] == false)
            {
                data[(2 * parIndex) + 2] = val;
                status[(2 * parIndex) + 2] = true;
                return;
            }
        }
    }

    int countNodes()
    {
        int count = 0;
        for (int i = 0; i < capacity; i++)
        {
            if (status[i] != false)
            {
                count++;
            }
        }
        return count;
    }

    int countLeafNodes()
    {
        int count = 0;
        for (int i = 0; i < capacity; i++)
        {
            if (status[i] == true)
            {
                if (2 * i + 1 > capacity - 1 && 2 * i + 2 > capacity - 1)
                {
                    count++;
                }
                else if (status[2 * i + 1] == false && status[2 * i + 2] == false)
                {
                    count++;
                }
            }
        }
        return count;
    }

    int getHeight()
    {
        int h = getHeight(0);
        return h;
    }

    int search(T val)
    {
        for (int i = 0; i < capacity; i++)
        {
            if (status[i] == true && data[i] == val)
            {
                return i;
            }
        }
        return -1;
    }

    void remove(T val)
    {
        int parIndex = search(val);
        if (parIndex != -1)
            rem(parIndex);
    }

    void mirror()
    {
        mirror(0);
    }

    void removeDuplicates()
    {
        for (int i = 0; i < capacity; i++)
        {
            if (status[i] == true)
            {
                for (int j = i + 1; j < capacity; j++)
                {
                    if (status[j] == true && data[i] == data[j])
                    {
                        rem(j);
                    }
                }
            }
        }
    }

    void levelOrderDisplay()
    {
        for (int i = 0; i < capacity; i++)
        {
            if (status[i] == true)
                cout << data[i] << " ";
        }
        cout << endl;
    }

    

    void preOrderDisplay()
    {
        preOrderDisplay(0);
        cout << endl;
    }

    void postOrderDisplay()
    {
        postOrderDisplay(0);
        cout << endl;
    }

    void inOrderDisplay()
    {
        inOrderDisplay(0);
        cout << endl;
    }

    void displayParanthesized()
    {
        paranthesized(0);
    }

    ~binaryTree()
    {
        delete[] status;
        delete[] data;
    }
    
};

#endif