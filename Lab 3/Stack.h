#ifndef STACK_H
#define STACK_H

#include<iostream>
using namespace std;

template <typename T>
class myStack
{
protected:
    T *data;
    int capacity;
    int top;

public:
    myStack(int c);
    myStack(const myStack &other);
    myStack &operator=(const myStack &other);
    bool isEmpty();
    bool isFull();
    void push(T val);
    T pop();
    int getTop();
    T stackTop();
    ~myStack();
};

template <typename T>
myStack<T>::myStack(int c) : capacity(c), top(0)
{
    data = new T[capacity];
}

template <typename T>
myStack<T>::myStack(const myStack &other) : capacity(other.capacity), top(other.top)
{
    data = new T[capacity];
    for (int i = 0; i < top; i++)
    {
        data[i] = other.data[i];
    }
}

template <typename T>
myStack<T> &myStack<T>::operator=(const myStack<T> &other)
{
    if (this != &other)
    {
        delete[] data;
        capacity = other.capacity;
        top = other.top;
        data = new T[capacity];
        for (int i = 0; i < top; i++)
        {
            data[i] = other.data[i];
        }
    }
    return *this;
}

template <typename T>
bool myStack<T>::isEmpty()
{
    return (top == 0);
}

template <typename T>
bool myStack<T>::isFull()
{
    return (top == capacity);
}

template <typename T>
void myStack<T>::push(T val)
{
    if (!isFull())
    {
        data[top++] = val;
    }
    else
    {
        throw out_of_range("Stack Overflow");
    }
}

template <typename T>
T myStack<T>::pop()
{
    if (!isEmpty())
    {
        top--;
        return data[top];
    }
    else
    {
        return 0;
    }
}

template <typename T>
int myStack<T>::getTop()
{
    return top;
}

template <typename T>
T myStack<T>::stackTop()
{
    if (!isEmpty())
        return data[top - 1];
    else
    {
        throw out_of_range("Stack is empty");
    }
}

template <typename T>
myStack<T>::~myStack()
{
    delete[] data;
    data = nullptr;
    capacity = 0;
    top = 0;
}

#endif