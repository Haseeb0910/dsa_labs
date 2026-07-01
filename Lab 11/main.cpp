#include<iostream>
#include"studentBST.h"
using namespace std;

void menu()
{
    StudentBST b;
    int option = 0;
    while (option != 4)
    {
        cout << "1. Insert a new student " << endl;
        cout << "2. Search for a student " << endl;
        cout << "3. See the list of students  " << endl;
        cout << "4. Exit " << endl;
        cout << "Enter your choice: ";
        cin >> option;
        if (option == 1)
        {
            int rollNo;
            string name;
            double cgpa;
            cout << "Enter rollNo: ";
            cin >> rollNo;
            cout << "Enter name: ";
            cin >> name;
            cout << "Enter cgpa: ";
            cin >> cgpa;
            b.insert(rollNo , name , cgpa);
        }
        else if (option == 2)
        {

            int rollNo;
            cout << "Enter rollNo: ";
            cin >> rollNo;
            b.search(rollNo);
        }
        else if (option == 3)
        {
            b.InOrder();
        }
        else if (option == 4)
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
    // menu();
    StudentBST b;
    b.insert(2,"Haseeb",3.86);
    b.insert(1,"Jimmy",3.63);
    b.insert(6,"Huzaifa",3.81);
    b.insert(29,"Abdullah",3.40);
    // b.InOrder();
    b.displayInRange(3.4 , 3.7);
}