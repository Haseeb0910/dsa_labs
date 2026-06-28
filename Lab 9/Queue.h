#ifndef myQueue_H
#define myQueue_H

#include <iostream>
#include <stdexcept>
using namespace std;

template <typename T>
class myQueue
{
private:
    T *data;
    int capacity;
    int size;
    int front;
    int rear;

public:
    myQueue(int c = 10)
    {
        capacity = c;
        size = 0;
        front = 0;
        rear = 0;
        data = new T[capacity];
    }
    ~myQueue()
    {
        delete[] data;
        data = nullptr;
    }

    myQueue(const myQueue &other)
    {
        capacity = other.capacity;
        size = other.size;
        front = other.front;
        rear = other.rear;
        int index = front;
        data = new T[capacity];
        for (int i = 0; i < size; i++)
        {
            data[i] = other.data[index % capacity];
            index++;
        }
        front = 0;
        rear = size;
    }

    bool isFull()
    {
        return (size == capacity);
    }

    bool isEmpty()
    {
        return (size == 0);
    }

    void resize(int nc)
    {
        T *new_data = new T[nc];
        int index = front;
        for (int i = 0; i < size; i++)
        {
            new_data[i] = data[index % capacity];
            index++;
        }
        delete[] data;
        data = new_data;
        capacity = nc;
        front = 0;
        rear = size;
    }

    void enQueue(T d)
    {
        if (isFull())
            resize(this->capacity * 2);

        data[rear % capacity] = d;
        rear++;
        size++;
    }

    T deQueue()
    {
        if (!isEmpty())
        {
            T val = data[front % capacity];
            front++;
            size--;
            return val;
        }
        else
            throw out_of_range("Empty myQueue");
    }

    void display()
    {
        int index = front;
        for (int i = 0; i < size; i++)
        {
            cout << data[index % capacity] << " ";
            index++;
        }
    }

    T front_data()
    {
        if (!isEmpty())
        {
            return data[front % capacity];
        }
        else
            throw out_of_range("Empty myQueue");
    }

    myQueue<T> &operator=(const myQueue &other)
    {
        if (this != &other)
        {
            delete[] data;
            capacity = other.capacity;
            size = other.size;
            front = other.front;
            rear = other.rear;
            int index = front;
            data = new T[capacity];
            for (int i = 0; i < size; i++)
            {
                data[i] = other.data[index % capacity];
                index++;
            }
            front = 0;
            rear = size;
        }
        return *this;
    }

    int Size()
    {
        return size;
    }
};

#endif


