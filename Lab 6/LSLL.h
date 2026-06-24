#ifndef LSLL_H
#define LSLL_H

#include <iostream>
using namespace std;

template <typename T>
class Node
{
public:
    T data;
    Node<T> *next;

    Node()
    {
        data = 0;
        next = nullptr;
    }
    Node(T val)
    {
        data = val;
        next = nullptr;
    }
    Node(T val, Node<T> *other)
    {
        data = val;
        next = other;
    }
    ~Node()
    {
        next = nullptr;
    }
};

template <typename T>
class LSLL
{
private:
    Node<T> *head;

public:
    LSLL()
    {
        head = nullptr;
    }

    void insertAtHead(T val)
    {
        Node<T> *temp = new Node<T>(val);
        temp->next = head;
        head = temp;
    }
    void insertAtTail(T val)
    {
        Node<T> *temp = new Node<T>(val);
        if (!head)
        {
            head = temp;
        }
        else
        {
            Node<T> *temp_H = head;
            while (temp_H->next != nullptr)
            {
                temp_H = temp_H->next;
            }
            temp_H->next = temp;
        }
    }
    void insertBefore(T key, T val)
    {
        if (head == nullptr)
            return;

        if (head->data == key)
        {
            insertAtHead(val);
            return;
        }

        Node<T> *curr = head->next;
        Node<T> *prev = head;

        while (curr != nullptr)
        {
            if (curr->data == key)
            {
                Node<T> *temp = new Node<T>(val);
                temp->next = curr;
                prev->next = temp;
                return;
            }
            prev = curr;
            curr = curr->next;
        }
    }
    void insertAfter(T key, T val)
    {
        if (head == nullptr)
            return;

        Node<T> *curr = head;

        while (curr != nullptr)
        {
            if (curr->data == key)
            {
                Node<T> *temp = new Node<T>(val);
                temp->next = curr->next;
                curr->next = temp;
                return;
            }
            curr = curr->next;
        }
    }

    T removeAtHead()
    {
        if (head == nullptr)
            return T();

        Node<T> *temp = head;
        T val = temp->data;
        head = head->next;
        delete temp;
        return val;
    }

    void removeAtTail()
    {
        if (head == nullptr)
            return;

        if (head->next == nullptr)
        {
            delete head;
            head = nullptr;
            return;
        }

        Node<T> *curr = head;
        Node<T> *prev = head;

        while (curr->next != nullptr)
        {
            prev = curr;
            curr = curr->next;
        }
        delete curr;
        prev->next = nullptr;
    }

    void remove(T val)
    {
        if (head == nullptr)
            return;

        if (head->data == val)
        {
            Node<T> *temp = head;
            head = head->next;
            delete temp;
            return;
        }

        Node<T> *curr = head->next;
        Node<T> *prev = head;

        while (curr != nullptr)
        {
            if (curr->data == val)
            {
                prev->next = curr->next;
                delete curr;
                return;
            }
            prev = curr;
            curr = curr->next;
        }
    }
    void removeBefore(T val)
    {
        if (head == nullptr || head->data == val || head->next == nullptr)
            return;

        if (head->next->data == val)
        {
            Node<T> *temp = head;
            head = head->next;
            delete temp;
            return;
        }

        Node<T> *curr = head->next->next;
        Node<T> *prev1 = head->next;
        Node<T> *prev2 = head;

        while (curr != nullptr)
        {
            if (curr->data == val)
            {
                prev2->next = curr;
                delete prev1;
                return;
            }
            prev2 = prev1;
            prev1 = curr;
            curr = curr->next;
        }
    }
    void removeAfter(T val)
    {
        if (head == nullptr || head->next == nullptr)
            return;

        Node<T> *curr = head;
        while (curr->next != nullptr)
        {
            if (curr->data == val)
            {
                Node<T> *temp = curr->next;
                curr->next = curr->next->next;
                delete temp;
                return;
            }
            curr = curr->next;
        }
    }

    bool removeKthNode(int k, int &val)
    {
        if (k == 0)
            return false;
        if (countNodes() < k)
            return false;

        Node<T> *temp = head;
        if (k == 1)
        {
            temp = head;
            val = head->data;
            head = head->next;
            delete temp;
            return true;
        }

        Node<T> *curr = head->next;
        Node<T> *prev = head;
        int count = 2;
        while (curr != nullptr)
        {
            if (count == k)
            {
                val = curr->data;
                prev->next = curr->next;
                delete curr;
                return true;
            }
            prev = prev->next;
            curr = curr->next;
            count++;
        }
    }

    int search(T key)
    {
        if (head == nullptr)
            return 0;

        Node<T> *temp = head;
        while (temp != nullptr)
        {
            if (temp->data == key)
                return 1;
            temp = temp->next;
        }
        return 0;
    }

    void update(T key, T val)
    {
        if (head == nullptr)
            return;

        Node<T> *temp = head;
        while (temp != nullptr)
        {
            if (temp->data == key)
            {
                temp->data = val;
                return;
            }
            temp = temp->next;
        }
    }

    int countNodes()
    {
        if (head == nullptr)
            return 0;

        int count = 0;
        Node<T> *temp = head;
        while (temp != nullptr)
        {
            count++;
            temp = temp->next;
        }
        return count;
    }

    void combine(LSLL<T> &list1, LSLL<T> &list2)
    {
        this->head = list1.head;
        Node<T> *temp = list1.head;

        while (temp->next != nullptr)
        {
            temp = temp->next;
        }

        temp->next = list2.head;
        list1.head = nullptr;
        list2.head = nullptr;
    }

    void shuffleMerge(LSLL &list1, LSLL &list2)
    {
        if (list1.head == nullptr && list2.head == nullptr)
        {
            this->head = nullptr;
            return;
        }

        if (list1.head != nullptr)
        {
            Node<T> *l1 = list1.head;
            Node<T> *l2 = list2.head;
            this->head = l1;
            Node<T> *temp = l1;
            l1 = l1->next;

            while (l1 != nullptr && l2 != nullptr)
            {
                temp->next = l2;
                l2 = l2->next;
                temp = temp->next;
                temp->next = l1;
                l1 = l1->next;
                temp = temp->next;
            }

            if (l1 != nullptr)
            {
                temp->next = l1;
            }
            else if (l2 != nullptr)
            {
                temp->next = l2;
            }
        }
        else
        {
            this->head = list2.head;
        }

        list1.head = nullptr;
        list2.head = nullptr;
    }

    void reverse_list()
    {
        if (head == nullptr || head->next == nullptr)
            return;

        Node<T> *curr = head;
        Node<T> *prev = nullptr;
        Node<T> *forward = nullptr;

        while (curr != nullptr)
        {
            forward = curr->next;
            curr->next = prev;
            prev = curr;
            curr = forward;
        }
        head = prev;
    }

    void removeDuplicates()
    {
        Node<T> *key = this->head;
        while (key != nullptr)
        {
            Node<T> *temp1 = key->next;
            Node<T> *temp2 = key;
            Node<T> *remove = nullptr;
            while (temp1 != nullptr)
            {
                if (key->data == temp1->data)
                {
                    temp2->next = temp1->next;
                    remove = temp1;
                }
                temp2 = temp1;
                temp1 = temp1->next;
                delete remove;
            }
            key = key->next;
        }
    }

    void display()
    {
        Node<T> *temp = head;
        while (temp != nullptr)
        {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }

    ~LSLL()
    {
        while (head != nullptr)
        {
            Node<T> *temp = head;
            head = head->next;
            delete temp;
        }
    }
};

#endif
