#include "math.h"
#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <climits>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <cstdlib>
#include <fstream>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <string>
#include <stdlib.h>

using namespace std;

void print_array(int *a, int n)
{
    for (int i = 0; i < n; i++)
        cout << a[i] << " ";
    cout << endl;
}

// 0 - blocked, 1 - open
// Rat can move in any direction ( left, right, up and down).
int maze[5][5] = {{1, 0, 1, 1, 1},
                    {1, 1, 1, 0, 1},
                    {1, 0, 0, 1, 1},
                    {1, 0, 0, 1, 0},
                    {1, 0, 0, 1, 1}};

int moves_x[4] = {1, 0, -1, 0};
int moves_y[4] = {0, 1, 0, -1};

int path[5][5] = {{0, 0, 0, 0, 0},
                    {0, 0, 0, 0, 0},
                    {0, 0, 0, 0, 0},
                    {0, 0, 0, 0, 0},
                    {0, 0, 0, 0, 0}};

int c = 1;

int is_valid(int x, int y, int m, int n)
{
    if (x >= 0 && x <= m && y >= 0 && y <= n && maze[x][y] != 0 && path[x][y] == 0)
        return 1;
    return 0;
}

int rat_maze(int i, int j, int m, int n, char dir)
{
    if (i == m && j == n) {
        path[i][j] = c++;
        cout << "printing rat path: " << endl;
        for (i = 0; i < 5; ++i) {
            for (j = 0; j < 5; ++j) {
                cout << path[i][j] << "   ";
            }
            cout << endl;
        }
        return 1;
    }

    path[i][j] = c++;

    if (dir != 'U' && is_valid(i+1, j, m, n) && rat_maze(i+1, j, m, n, 'D'))
        return 1;

    if (dir != 'L' && is_valid(i, j+1, m, n) && rat_maze(i, j+1, m, n, 'R'))
        return 1;

    if (dir != 'D' && is_valid(i-1, j, m, n) && rat_maze(i-1, j, m, n, 'U'))
        return 1;

    if (dir != 'R' && is_valid(i, j-1, m, n) && rat_maze(i, j-1, m, n, 'L'))
        return 1;

    /*  Can be done both ways

    int k, next_x, next_y;
    for (k = 0; k < 4; ++k) {
        next_x = i + moves_x[k];
        next_y = j + moves_y[k];
        if (is_valid(next_x, next_y, m, n)) {
            if (rat_maze(next_x, next_y, m, n))
                return 1;
        }
    }
    */

    c--;
    path[i][j] = 0;
    return 0;
}

// directions are L - left, R - right, U - up, D - down

int main ()
{
    int i, j;
    cout << "Can rat reach to the destination?: " << rat_maze(0, 0, 4, 4, 'D') << endl;

    return 0;
}
