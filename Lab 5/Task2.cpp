#include <iostream>
#include "cmath"
using namespace std;

bool isprime(int n)
{
    if (n < 2)
        return false;
    for (int i = 2; i <= sqrt(n); i++)
    {
        if (n % i == 0)
            return false;
    }
    return true;
}

bool isGoodNumber(const string &s, int index = 0)
{
    if (index >= s.length())
        return true;
    else
    {
        if (index == 0 || index % 2 == 0)
        {
            if ((s[index] - '0') % 2 == 0)
                return isGoodNumber(s, index + 1);
            else
                return false;
        }
        else
        {
            if (isprime(s[index] - '0'))
                return isGoodNumber(s, index + 1);
            else
                return false;
        }
    }
}

int main()
{
    string digit_strings[] = {"02468", "23478", "224365"};
    for (string digits : digit_strings)
    {
        bool is_good = isGoodNumber(digits, 0);
        cout << "Digit string: " << digits << " is " << (is_good ? "good" : "not good") << endl;
    }
    return 0;
}