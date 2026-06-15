#include <iostream>
#include <cctype>  
#include <string>
#include "Stack.h"

using namespace std;

bool isPalindrome(string s)
{
    myStack<char> stack(s.length());
    string filtered = "";

    for(char ch : s)
    {
        if(isdigit(ch) || isalpha(ch))
        {
            ch = tolower(ch);
            stack.push(ch);
            filtered += ch;
        }
    }

    string reversed = "";
    while(!stack.isEmpty())
    {
        reversed += stack.pop();
    }

    return filtered == reversed;
}

int main()
{
    string s;
    cout << "Enter a sentence: ";
    getline(cin, s);

    if (isPalindrome(s))
        cout << "Palindrome";
    else
        cout << "Not a palindrome";
}


