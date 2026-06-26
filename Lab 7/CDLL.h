#ifndef CDLL_H
#define CDLL_H

#include <iostream>
using namespace std;

template <typename T>
class Node
{
public:
    T data;
    Node<T> *next;
    Node<T> *prev;

    Node()
    {
        data = 0;
        next = nullptr;
        prev = nullptr;
    }
    Node(T val)
    {
        data = val;
        next = nullptr;
        prev = nullptr;
    }
    ~Node()
    {
        next = nullptr;
        prev = nullptr;
    }
};

template <typename T>
class CDLL
{
private:
    Node<T> *head;

public:
    CDLL()
    {
        head = nullptr;
    }

    void insertAtHead(T val)
    {
        Node<T> *newNode = new Node<T>(val);

        if (head == nullptr)
        {
            head = newNode;
            head->next = newNode;
            head->prev = newNode;
            return;
        }
        newNode->next = head;
        newNode->prev = head->prev;
        head->prev->next = newNode;
        head->prev = newNode;
        head = newNode;
    }

    void insertAtTail(T val)
    {
        if (head == nullptr)
        {
            insertAtHead(val);
            return;
        }

        Node<T> *newNode = new Node<T>(val);
        head->prev->next = newNode;
        newNode->prev = head->prev;
        newNode->next = head;
        head->prev = newNode;
    }

    void removeAtHead()
    {
        if (head == nullptr)
            return;

        if (head->next == head)
        {
            delete head;
            head = nullptr;
            return;
        }

        Node<T> *temp = head;
        head = head->next;
        head->prev = temp->prev;
        head->prev->next = head;
        delete temp;
    }

    void removeAtTail()
    {
        if (head == nullptr)
            return;

        if (head->next == head)
        {
            removeAtHead();
            return;
        }

        Node<T> *temp = head->prev;
        head->prev->prev->next = head;
        head->prev = temp->prev;
        delete temp;
    }

    void remove(T val)
    {
        if (head == nullptr)
            return;

        if (head->data == val)
        {
            removeAtHead();
            return;
        }

        if (head->prev->data == val)
        {
            removeAtTail();
            return;
        }

        Node<T> *temp = head;
        while (temp->next != head)
        {
            if (temp->data == val)
            {
                temp->prev->next = temp->next;
                temp->next->prev = temp->prev;
                delete temp;
                return;
            }
            temp = temp->next;
        }
    }

    bool search(T key)
    {
        if (head == nullptr)
            return false;

        Node<T> *temp = head;
        do
        {
            if (temp->data == key)
            {
                return true;
            }
            temp = temp->next;
        } while (temp != head);
        return false;
    }

    void update(T key, T val)
    {
        if (head == nullptr)
            return;

        Node<T> *temp = head;
        do
        {
            if (temp->data == key)
            {
                temp->data = val;
                return;
            }
            temp = temp->next;
        } while (temp != head);
    }

    int countNodes()
    {
        if (head == nullptr)
            return 0;

        int count = 0;
        Node<T> *temp = head;
        do
        {
            count++;
            temp = temp->next;
        } while (temp != head);
        return count;
    }

    void merge(CDLL &list1, CDLL &list2)
    {
        if (list1.head == nullptr && list2.head == nullptr)
            return;

        if (list1.head == nullptr)
        {
            this->head = list2.head;
            list2.head = nullptr;
            return;
        }

        if (list2.head == nullptr)
        {
            this->head = list1.head;
            list1.head = nullptr;
            return;
        }

        Node<T> *curr1 = list1.head;
        Node<T> *curr2 = list2.head;
        Node<T> *tail = nullptr;

        if (curr1->data <= curr2->data)
        {
            head = curr1;
        }
        else
        {
            head = curr2;
        }
        tail = head;

        while (curr1 != nullptr || curr2 != nullptr)
        {
            Node<T> *nextNode = nullptr;

            if (curr1 == nullptr)
            {
                nextNode = curr2;
                curr2 = (curr2->next != list2.head) ? curr2->next : nullptr;
            }
            else if (curr2 == nullptr)
            {
                nextNode = curr1;
                curr1 = (curr1->next != list1.head) ? curr1->next : nullptr;
            }
            else if (curr1->data <= curr2->data)
            {
                nextNode = curr1;
                curr1 = (curr1->next != list1.head) ? curr1->next : nullptr;
            }
            else
            {
                nextNode = curr2;
                curr2 = (curr2->next != list2.head) ? curr2->next : nullptr;
            }

            if (nextNode != head)
            {
                tail->next = nextNode;
                nextNode->prev = tail;
                tail = nextNode;
            }
        }

        tail->next = head;
        head->prev = tail;

        list1.head = nullptr;
        list2.head = nullptr;
    }

    void splitList(CDLL &leftHalf, CDLL &rightHalf)
    {
        if (head == nullptr)
            return;

        int totalcount = this->countNodes();
        int count;
        if (totalcount % 2 != 0)
            count = (totalcount / 2) + 1;
        else
            count = totalcount / 2;
        int remCount = totalcount - count;

        leftHalf.head = head;
        Node<T> *temp1 = leftHalf.head;
        while (count > 1)
        {
            temp1 = temp1->next;
            count--;
        }

        rightHalf.head = temp1->next;
        temp1->next = leftHalf.head;
        leftHalf.head->prev = temp1;

        Node<T> *temp2 = rightHalf.head;
        while (remCount > 1)
        {
            temp2 = temp2->next;
            remCount--;
        }
        temp2->next = rightHalf.head;
        rightHalf.head->prev = temp2;

        head = nullptr;
    }

    void combine(CDLL<T> &list1, CDLL<T> &list2)
    {
        if (list1.head == nullptr && list2.head == nullptr)
            return;

        if(list1.head == nullptr)
        {
            head = list2.head;
            list2.head = nullptr;
            return;
        }

        if(list2.head == nullptr)
        {
            head = list1.head;
            list1.head = nullptr;
            return;
        }

        Node<T>* temp1 = list1.head->prev;
        Node<T>* temp2 = list2.head->prev;

        temp1->next = list2.head;
        list2.head->prev = temp1;
        temp2->next = list1.head;
        list1.head->prev = temp2;
        head = list1.head;

        list1.head = nullptr;
        list2.head = nullptr;
    }

    void shuffleMerge(CDLL &list1, CDLL &list2)
    {
        if(list1.head == nullptr && list2.head == nullptr)
        return;

        if(list1.head == nullptr)
        {
            head = list2.head;
            list2.head = nullptr;
            return;
        }

        if(list2.head == nullptr)
        {
            head = list1.head;
            list1.head = nullptr;
            return;
        }

        Node<T>* l1 = list1.head;
        Node<T>* l2 = list2.head;
        head = l1;
        Node<T>* temp = l1;
        l1 = l1->next;

        do
        {
            temp->next = l2;
            l2->prev = temp;
            temp = temp->next;
            l2 = l2->next;
            temp->next = l1;
            l1->prev = temp;
            temp = temp->next;
            l1 = l1->next;
        } while(l1 != list1.head && l2 != list2.head);
        

        if(l1 != list1.head)
        {
            temp->next = l1;
            l1 = list1.head->prev;
            temp = l1;
        }

        if(l2 != list2.head)
        {
            temp->next = l2;
            l2 = list2.head->prev;
            temp = l2;
        }
        temp->next = head;
        head->prev = temp;

        list1.head = nullptr;
        list2.head = nullptr;
    }

    void display()
    {
        if (head == nullptr)
        {
            cout << "List is empty." << endl;
            return;
        }

        Node<T> *temp = head;
        do
        {
            cout << temp->data << " ";
            temp = temp->next;
        } while (temp != head);
        cout << endl;
    }

    ~CDLL()
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
