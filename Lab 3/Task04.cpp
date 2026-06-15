#include <iostream>
#include "Stack.h"

using namespace std;

void addingLargeNumbers(string s1, string s2)
{
    myStack<int> stack1(s1.length());
    myStack<int> stack2(s2.length());
    int stackSize = (max(s1.length(), s2.length())) + 1;
    myStack<int> res(stackSize);
    int carry = 0;
    for (int i = 0; i < s1.length(); i++)
    {
        stack1.push(s1[i] - '0');
    }
    for (int i = 0; i < s2.length(); i++)
    {
        stack2.push(s2[i] - '0');
    }

    while (!stack1.isEmpty() || !stack2.isEmpty() || carry != 0)
    {
        int operand1 = (!stack1.isEmpty()) ? stack1.pop() : 0;
        int operand2 = (!stack2.isEmpty()) ? stack2.pop() : 0;
        int result = operand1 + operand2 + carry;
        int unit = result % 10;
        carry = result / 10;
        res.push(unit);
    }

    while(!res.isEmpty())
    {
        cout << res.pop();
    }
}

int main()
{
    string s1 = "800";
    string s2 = "265";
    addingLargeNumbers(s1, s2);
}
