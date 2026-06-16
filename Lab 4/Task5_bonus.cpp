#include <iostream>
#include "Queue.h"

class Process
{
private:
    int processId;
    string processName;
    int executionTime;

public:
    Process()
    {
        processId = 0;
        processName = "";
        executionTime = 0;
    }

    Process(int id, string name, int time) : processId(id), processName(name), executionTime(time) {}

    int getId() { return processId; };
    string getName() { return processName; };
    int getExecutionTime() { return executionTime; };
    void setExecutionTime(int t) { executionTime = t; };
    void display()
    {
        cout << processName << ", " << executionTime << " completed execution." << endl;
    }
};

class Scheduler
{
private:
    myQueue<Process> q;
    int timeQuantum;

public:
    Scheduler(Process arr[], int len, int tq) : q(10), timeQuantum(tq)
    {
        for (int i = 0; i < len; i++)
        {
            q.enqueue(arr[i]);
        }
    }
    void assignProcessor()
    {
        Process curr;
        while (!q.isEmpty())
        {
            curr = q.dequeue();
            int unit;
            int time = curr.getExecutionTime() - timeQuantum;
            if (curr.getExecutionTime() > timeQuantum)
            {
                unit = timeQuantum;
            }
            else
            {
                unit = curr.getExecutionTime();
            }
            cout << "Executing process " << curr.getName() << " for " << unit << " units." << endl;
            if (time > 0)
            {
                curr.setExecutionTime(time);
                q.enqueue(curr);
            }
            else
            {
                cout << curr.getName() << " Completed" << endl;
            }
        }
    }
};

int main()
{
    Process arr[] = {
        Process(1, "notepad.exe", 20),
        Process(13, "mp3player.exe", 5),
        Process(4, "bcc.exe", 30),
        Process(11, "explorer.exe", 2)};

    Scheduler s(arr, 4, 5);
    s.assignProcessor();
    return 0;
}