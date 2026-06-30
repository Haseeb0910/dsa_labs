#include <iostream>
#include <string>
using namespace std;

class hashNode
{
public:
    string key;
    int value;
    hashNode *next;

    hashNode(string k, int v)
    {
        key = k;
        value = v;
        next = nullptr;
    }
};

class hashTable
{
private:
    string *table;
    int s;
    int n;

public:
    hashTable(int size)
    {
        s = size;
        n = 0;
        table = new string[s];
        for (int i = 0; i < s; i++)
        {
            table[i] = "";
        }
    }

    bool isEmpty()
    {
        if (n == 0)
            return true;
        else
            return false;
    }

    bool isFull()
    {
        if (n == s)
            return true;
        else
            return false;
    }

    double loadFactor()
    {
        return double(n) / double(s);
    }

    int getHashValue(string name)
    {
        int h = 0;
        for (int i = 0; i < name.length(); i++)
        {
            h += name[i];
        }
        return h % s;
    }

    bool insert(string name)
    {
        if (!isFull())
        {
            int i = getHashValue(name);
            int begin = i;
            while (table[i] != "")
            {
                cout << "Current index: " << i << endl;
                i = (i + 1) % s;
                if (begin == i)
                {
                    return false;
                }
            }
            cout << name << " set successfully at: " << i << endl;
            table[i] = name;
            n += 1;
            return true;
        }
        else
        {
            cout << "Table is Full" << endl;
            return false;
        }
    }

    bool search(string name)
    {
        if (!isEmpty())
        {
            int i = getHashValue(name);
            int begin = i;
            while (table[i] != "")
            {
                if (table[i] == name)
                {
                    cout << name << " found successfully at: " << i << endl;
                    return true;
                }
                cout << "Current index: " << i << endl;
                i = (i + 1) % s;
                if (begin == i)
                {
                    cout << name << " not found" << endl;
                    return false;
                }
            }
            cout << name << " not found" << endl;
            return false;
        }
        else
        {
            cout << "Table is empty" << endl;
            return false;
        }
    }

    void display()
    {
        for (int i = 0; i < s; i++)
        {
            if (table[i] == "")
                cout << i << " : " << "EMPTY" << endl;
            else
                cout << i << " : " << table[i] << endl;
        }
    }

    bool remove(string name)
    {
        if (!isEmpty())
        {
            int i = getHashValue(name);
            int begin = i;
            while (table[i] != "")
            {
                if (table[i] == name)
                {
                    table[i] = "";
                    cout << name << " removed successfully" << endl;
                    return true;
                }
                i = (i + 1) % s;
                if (begin == i)
                {
                    cout << name << " not found" << endl;
                    return false;
                }
            }
        }
        else
        {
            cout << "Table is empty" << endl;
            return false;
        }
    }
};

void menu()
{
    int size;
    cout << "Enter the size of Hash Table: ";
    cin >> size;
    hashTable h(size);

    int option = 0;
    while (option != 6)
    {
        cout << "1. Insert a name " << endl;
        cout << "2. Search for a name " << endl;
        cout << "3. Remove a name " << endl;
        cout << "4. Display the Hash Table " << endl;
        cout << "5. Display Load Factor of the table  " << endl;
        cout << "6. Exit " << endl;
        cout << "Enter your choice: ";
        cin >> option;
        if (option == 1)
        {
            string name;
            cout << "Enter name: ";
            cin >> name;
            h.insert(name);
        }
        else if (option == 2)
        {

            string name;
            cout << "Enter name: ";
            cin >> name;
            h.search(name);
        }
        else if (option == 3)
        {
            string name;
            cout << "Enter name: ";
            cin >> name;
            h.remove(name);
        }
        else if (option == 4)
        {

            h.display();
        }
        else if (option == 5)
        {
            double loadF = h.loadFactor();
            cout << "Load Factor: " << loadF << endl;
        }
        else if (option == 6)
        {
            cout << "Program ends " << endl;
            return;
        }
        else
        {
            cout << "Wrong choice " << endl;
        }
    }
}

int main()
{
    menu();
}