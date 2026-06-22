#include <iostream>
#include <cmath>

using namespace std;

int num_of_squares(int size, int targetX, int targetY, int centerX = 1024, int centerY = 1024)
{
    if (size < 1)
        return 0;
    
    int count = 0;
    if (abs(centerX - targetX) <= size && abs(centerY - targetY) <= size)
    {
        count++;
    }

    if (size == 1)
    {
        return count;
    }

    int nextSize = size / 2;
    int topLeft = num_of_squares(nextSize, targetX, targetY, centerX - size, centerY - size);
    int topRight = num_of_squares(nextSize, targetX, targetY, centerX - size, centerY + size);
    int bottomLeft = num_of_squares(nextSize, targetX, targetY, centerX + size, centerY - size);
    int bottomRight = num_of_squares(nextSize, targetX, targetY, centerX + size, centerY + size);

    int total = count + topLeft + topRight + bottomLeft + bottomRight;

    return total;
}

int main()
{
    cout << num_of_squares(500, 113, 941) << endl;
    cout << num_of_squares(300, 100, 200) << endl;
    cout << num_of_squares(300, 1024, 1024) << endl;
    return 0;
}