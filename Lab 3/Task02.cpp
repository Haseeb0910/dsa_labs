#include <iostream>
#include "Stack.h"

using namespace std;

bool isAnBn(string s)
{
    int n = s.length();
    if(n % 2 != 0) return false;

    myStack<char> valid(s.length());

    int i = 0;
    while(i < n && s[i] == 'a')
    {
        valid.push(s[i]);
        i++;
    }

    while(i < n && s[i] == 'b')
    {
        if(valid.isEmpty()) return false;
        valid.pop();
        i++;
    }

    return(i == n && valid.isEmpty());
}

int main()
{
    string s;
    cout << "Enter a string: ";
    cin >> s;
    cout << (isAnBn(s) ? "Valid" : "Invalid");
}