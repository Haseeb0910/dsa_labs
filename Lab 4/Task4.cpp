#include <iostream>
#include "Queue.h"

using namespace std;

struct Pair
{
    int tickets;
    int index;
};

int timeTaken(int arr[], int size, int k)
{
    myQueue<Pair> q(size);
    Pair target;
    int count = 0;
    for (int i = 0; i < size; i++)
    {
        if (i == k)
        {
            target.tickets = arr[i];
            target.index = i;
        }
        Pair temp;
        temp.tickets = arr[i];
        temp.index = i;
        q.enqueue(temp);
    }

    while (target.tickets != 0)
    {
        Pair element = q.dequeue();
        element.tickets--;
        if (element.tickets != 0)
            q.enqueue(element);
        if (element.index == k)
            target.tickets--;

        count++;
    }
    return count;
}

int main()
{
    int arr[4] = {5,1,1,1};
    int ans = timeTaken(arr, 4, 0);
    cout << ans;
}
