#include <iostream>
#include <string>
#include "Stack.h"

using namespace std;

string reverseWords(string str)
{
    myStack<char> charStack(str.length());
    string rev;

    for(int i = 0; i < str.length(); i++)
    {
        if(isalpha(str[i]))
        {
            charStack.push(str[i]);
        }
        if(str[i] == ' ' || i == str.length() - 1)
        {
            while(!charStack.isEmpty())
            {
                rev += charStack.pop();
            }
            if(str[i] == ' ')
            rev += ' ';
        }
    }
 
    return rev;
}

int main()
{
    string input;

    string s =  "Welcome to DSA";

    string reversed = reverseWords(s);

    cout << "Original: " << s << endl;
    cout << "Reversed: " << reversed << endl;

    return 0;
}