#include <stdio.h>
#include <windows.h>
#include <fstream>
#include <iostream>
using namespace std;

struct Student
{
    int roll;
    char name[30];
    Student() : roll(0)
    {
        strcpy(name, "none");
    }
};

void addToStudentUnBuffered(int N)
{
    ofstream ofs("studentdatabase.txt", ios::binary | ios::out);
    Student s;
    for (int i = 1; i < N; i++)
    {
        s.roll = i;
        ofs.write((char *)(&s), sizeof(Student));
    }
    ofs.close();
}

void addToStudentBuffered(int N)
{
    ofstream ofs("studentdatabase.txt", ios::binary | ios::out);

    const int BUFFER_SIZE = 10000; // how many students we store in memory before writing
    Student *buffer = new Student[BUFFER_SIZE];

    int count = 0;

    for (int i = 1; i < N; i++)
    {
        buffer[count].roll = i;
        strcpy(buffer[count].name, "none");
        count++;

        // If buffer is full, write all at once
        if (count == BUFFER_SIZE)
        {
            ofs.write((char *)buffer, sizeof(Student) * BUFFER_SIZE);
            count = 0; // reset buffer
        }
    }

    // Write any remaining records in buffer
    if (count > 0)
    {
        ofs.write((char *)buffer, sizeof(Student) * count);
    }

    delete[] buffer;
    ofs.close();
}

void readAllRecordsUnBuffered(int N)
{
    ifstream ifs("studentdatabase.txt", ios::binary | ios::in);
    Student s;
    for (int i = 1; i < N; i++)
    {
        ifs.read((char *)(&s), sizeof(Student));
    }
    ifs.close();
}

void readAllRecordsBuffered(int N)
{
    ifstream ifs("studentdatabase.txt", ios::binary | ios::in);

    const int BUFFER_SIZE = 10000000;
    Student *buffer = new Student[BUFFER_SIZE];

    int totalRead = 0;

    while (totalRead < N)
    {
        int recordsToRead = min(BUFFER_SIZE, N - totalRead);

        ifs.read((char *)buffer, sizeof(Student) * recordsToRead);

        totalRead += recordsToRead;
    }

    delete[] buffer;
    ifs.close();
}

int main()
{
    SYSTEMTIME systime;

    // -------- Writing Unbuffered --------
    cout << "\nWriting Records to File(unbuffered)";
    GetLocalTime(&systime);
    cout << endl
         << systime.wHour << ":" << systime.wMinute << ":" << systime.wSecond << ":" << systime.wMilliseconds;
    addToStudentUnBuffered(10000000);
    GetLocalTime(&systime);
    cout << endl
         << systime.wHour << ":" << systime.wMinute << ":" << systime.wSecond << ":" << systime.wMilliseconds;

    // -------- Writing Buffered --------
    cout << "\nWriting Records to File(buffered)";
    GetLocalTime(&systime);
    cout << endl
         << systime.wHour << ":" << systime.wMinute << ":" << systime.wSecond << ":" << systime.wMilliseconds;
    addToStudentBuffered(10000000);
    GetLocalTime(&systime);
    cout << endl
         << systime.wHour << ":" << systime.wMinute << ":" << systime.wSecond << ":" << systime.wMilliseconds;

    // -------- Reading Unbuffered --------
    cout << "\nReading Records from File(unbuffered)";
    GetLocalTime(&systime);
    cout << endl
         << systime.wHour << ":" << systime.wMinute << ":" << systime.wSecond << ":" << systime.wMilliseconds;
    readAllRecordsUnBuffered(10000000);
    GetLocalTime(&systime);
    cout << endl
         << systime.wHour << ":" << systime.wMinute << ":" << systime.wSecond << ":" << systime.wMilliseconds;

    // -------- Reading Buffered --------
    cout << "\nReading Records from File(buffered)";
    GetLocalTime(&systime);
    cout << endl
         << systime.wHour << ":" << systime.wMinute << ":" << systime.wSecond << ":" << systime.wMilliseconds;
    readAllRecordsBuffered(10000000);
    GetLocalTime(&systime);
    cout << endl
         << systime.wHour << ":" << systime.wMinute << ":" << systime.wSecond << ":" << systime.wMilliseconds;

    return 0;
}
