#include <iostream>
#include <iomanip>
using namespace std;

class hashTable
{
private:
    int *arr;
    int size;

public:
    hashTable(int s)
    {
        size = s;
        arr = new int[size];
        for (int i = 0; i < size; i++)
            arr[i] = -1;
    }

    int hash(int key)
    {
        return key % size;
    }

    bool insert(int key)
    {
        int i = hash(key);
        if (arr[i] == -1)
        {
            arr[i] = key;
            return true;
        }
        else
        {
            return false;
        }
    }
};

int getRandomNumber(int start, int end)
{
    return rand() % (end - start + 1) + start;
}

int experiment(int tableSize)
{
    hashTable h(tableSize);
    int c = 0;
    for (int i = 0; i < 50; i++)
    {
        if (h.insert(getRandomNumber(1, 100)))
        {
            c++;
        }
        else
        {
            return c;
        }
    }
    return c;
}

int main()
{
    srand(static_cast<unsigned>(time(0))); // seed random generator
    const int numExperiments = 50;
    cout << "Table Size\tAverage Inserted\n";
    cout << "-----------\t----------------\n";
    // Run experiments for table sizes 10, 20, 30, ..., 100
    for (int S = 10; S <= 100; S += 10)
    {
        double totalInserted = 0.0;
        for (int i = 0; i < numExperiments; i++)
            totalInserted += experiment(S);
        double averageInserted = totalInserted / numExperiments;
        cout << setw(5) << S << "\t\t" << fixed << setprecision(2)
             << averageInserted << endl;
    }
}