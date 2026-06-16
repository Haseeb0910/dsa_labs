
#include <iostream>
#include <stdexcept>
using namespace std;

template <typename T>
class myQueue
{
protected:
    T *data;
    int capacity;
    int size;
    int front;
    int rear;

public:
    myQueue(int c);
    myQueue(const myQueue &other);
    myQueue &operator=(const myQueue &other);
    bool isEmpty();
    bool isFull();
    void resize(int nc);
    void enqueue(T val);
    T dequeue();
    int getSize();
    T queueFront();
    ~myQueue();
    void display();
};

template <typename T>
myQueue<T>::myQueue(int c) : capacity(c), size(0), front(0), rear(0)
{
    data = new T[capacity];
}

template <typename T>
myQueue<T>::myQueue(const myQueue &other) : capacity(other.capacity), size(other.size), front(other.front), rear(other.rear)
{
    data = new T[capacity];
    for (int i = 0; i < capacity; i++)
    {
        data[i] = other.data[i];
    }
}

template <typename T>
myQueue<T> &myQueue<T>::operator=(const myQueue<T> &other)
{
    if (this != &other)
    {
        delete[] data;
        capacity = other.capacity;
        size = other.size;
        front = other.front;
        rear = other.rear;
        data = new T[capacity];
        for (int i = 0; i < capacity; i++)
        {
            data[i] = other.data[i];
        }
    }
    return *this;
}

template <typename T>
bool myQueue<T>::isEmpty()
{
    return (size == 0);
}

template <typename T>
bool myQueue<T>::isFull()
{
    return (size == capacity);
}

template <typename T>
void myQueue<T>::resize(int nc)
{
    if (nc <= size)
    {
        throw std::invalid_argument("New capacity cannot be less than current size");
    }

    T *new_data = new T[nc];
    for (int i = 0; i < size; i++)
    {
        new_data[i] = data[(front + i) % capacity];
    }
    delete[] data;
    data = new_data;
    capacity = nc;
    front = 0;
    rear = size;
}

// o(1)
template <typename T>
void myQueue<T>::enqueue(T val)
{
    if (isFull())
        resize(capacity * 2);

    data[rear] = val;
    rear = (rear + 1) % capacity;
    size++;
}

// o(1)
template <typename T>
T myQueue<T>::dequeue()
{
    if (!isEmpty())
    {
        T e = data[front];
        front = (front + 1) % capacity;
        size--;
        return e;
    }
    else
    {
        throw out_of_range("Queue is empty");
    }
}

template <typename T>
int myQueue<T>::getSize()
{
    return size;
}

template <typename T>
T myQueue<T>::queueFront()
{
    if (!isEmpty())
        return data[front];
    else
    {
        throw out_of_range("Queue is empty");
    }
}

template <typename T>
myQueue<T>::~myQueue()
{
    delete[] data;
    data = nullptr;
    capacity = 0;
    size = 0;
    front = 0;
    rear = 0;
}

template <typename T>
void myQueue<T>::display()
{
    cout << "Elements in the circular queue are: ";
    for (int i = 0; i < size; i++)
    {
        cout << data[(front + i) % capacity] << " ";
    }
    cout << endl;
    
}

int main()
{
    myQueue<int> q(5);

    q.enqueue(14);
    q.enqueue(22);
    q.enqueue(13);
    q.enqueue(-6);
    q.display();
    cout << "Deleted Value = " << q.dequeue() << endl;
    cout << "Deleted Value = " << q.dequeue() << endl;
    q.display();

    q.enqueue(9);
    q.enqueue(20);
    q.enqueue(5);
    q.display();
    return 0;
}