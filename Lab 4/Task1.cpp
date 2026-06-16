#include <iostream>
#include "Stack.h"
using namespace std;

struct Pair
{
    int x;
    int y;
};

void solve_maze(char maze[6][6], Pair s, Pair d, int row, int col)
{
    myStack<Pair> sa(row * col);
    myStack<Pair> res(row * col);
    sa.push(s);
    while (!sa.isEmpty())
    {
        Pair cur = sa.stackTop();
        if (cur.x == d.x && cur.y == d.y)
        {
            cout << "Path Found" << endl;
            while (!sa.isEmpty())
            {
                Pair ans = sa.pop();
                res.push(ans);
            }
            while (!res.isEmpty())
            {
                Pair temp = res.pop();
                cout << "(" << temp.x << " , " << temp.y << ")" << " ";
            }
            cout << endl;
            return;
        }
        else if (cur.y + 1 < col && maze[cur.x][cur.y + 1] == ' ' || maze[cur.x][cur.y + 1] == 'T')
        {
            maze[cur.x][cur.y] = 'P';
            cur.y += 1;
            sa.push(cur);
        }
        else if (cur.y - 1 >= 0 && maze[cur.x][cur.y - 1] == ' ' || maze[cur.x][cur.y - 1] == 'T')
        {
            maze[cur.x][cur.y] = 'P';
            cur.y -= 1;
            sa.push(cur);
        }
        else if (cur.x + 1 < row && maze[cur.x + 1][cur.y] == ' ' || maze[cur.x + 1][cur.y] == 'T')
        {
            maze[cur.x][cur.y] = 'P';
            cur.x += 1;
            sa.push(cur);
        }
        else if (cur.x - 1 >= 0 && maze[cur.x - 1][cur.y] == ' ' || maze[cur.x - 1][cur.y] == 'T')
        {
            maze[cur.x][cur.y] = 'P';
            cur.x -= 1;
            sa.push(cur);
        }
        else
        {
            maze[cur.x][cur.y] = 'P';
            sa.pop();
        }
    }
    cout << "No Path Found" << endl;
}

int main()
{
    char maze1[6][6] = {
        {' ', '*', ' ', '*', ' ', ' '},
        {' ', '*', ' ', '*', ' ', ' '},
        {'P', ' ', ' ', ' ', '*', ' '},
        {'*', ' ', '*', '*', '*', ' '},
        {' ', ' ', ' ', ' ', '*', 'T'},
        {'*', ' ', ' ', ' ', ' ', ' '}};

    Pair start = {2, 0};
    Pair dest = {4, 5};

    solve_maze(maze1, start, dest, 6, 6);

    char maze2[6][6] = {
        {' ', '*', ' ', '*', ' ', ' '},
        {' ', '*', ' ', '*', ' ', ' '},
        {'P', ' ', ' ', ' ', '*', ' '},
        {'*', '*', '*', ' ', '*', ' '},
        {' ', ' ', ' ', ' ', '*', 'T'},
        {'*', ' ', ' ', ' ', ' ', ' '}};

    solve_maze(maze2, start, dest, 6, 6);

    return 0;
}
