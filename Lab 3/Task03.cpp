#include <iostream>
#include "Stack.h"

using namespace std;

bool isBracketsValid(string s)
{
    myStack<char> isValid(s.length());
    for (int i = 0; i < s.length(); i++)
    {
        char ch = s[i];
        if (ch == '(' || ch == '{' || ch == '[')
        {
            isValid.push(ch);
        }
        else if (ch == ')' || ch == '}' || ch == ']')
        {
            if(isValid.isEmpty())
            return 0;

            char stacktop = isValid.stackTop();
            if(ch == ')' && stacktop == '(' || ch == '}' && stacktop == '{'  || ch == ']' && stacktop == '[')
            {
                isValid.pop();
            }
            else
            {
                return 0;
            }
        }
    }

    if (isValid.isEmpty())
        return 1;
    else
        return 0;
}

int main()
{
    string s = "3+3";
    cout << isBracketsValid(s) << endl; 
    
    string s2 = "[A+{B-(C * D)}";
    cout << isBracketsValid(s2) << endl; 
    
    string s3 = "[A+{B-(C * D)}]]"; 
    cout << isBracketsValid(s3) << endl; 
    
    return 0;
}