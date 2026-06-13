#include <iostream>
using namespace std;

void print(int d)
{
  for (int i = 1; i <= d; i++)
  {
    cout << "I" << i;
    for (int j = i + 1; j <= d; j++)
    {
      cout << "U" << j;
    }
    if (i != d)
      cout << " + ";
  }
}

int main()
{
  print(3);
}