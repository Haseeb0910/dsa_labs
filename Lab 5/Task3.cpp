#include <iostream>
using namespace std;

int countWays(int numStairs)
{
    if (numStairs == 0 || numStairs == 1)
        return 1;
    else
    {
        return countWays(numStairs - 1) + countWays(numStairs - 2);
    }
}

int main()
{
    int n;
    cout << "Enter no. of stairs: ";
    cin >> n;
    cout << "No. of ways to climb " << n << " stairs: " << countWays(n);
}