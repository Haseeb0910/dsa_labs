#include<iostream>
using namespace std;

int dec2oct(int dec)
{
    if(dec < 8)
    return dec;
    else
    {
        int rem = dec % 8;
        int curr = dec2oct(dec / 8) * 10;
        return rem + curr;
    }
}

int main()
{
    int n = 90;
    cout << "Octal Equivalent of " << n << " is: " << dec2oct(n) << endl; 
    n = 389;
    cout << "Octal Equivalent of " << n << " is: " << dec2oct(n) << endl; 
    return 0;
}

