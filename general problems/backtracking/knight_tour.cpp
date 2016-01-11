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

int path = 0;

int can_move(int x, int y)
{
    if (x >= 0 && y >= 0 && x < 8 && y < 8)
        return 1;
    return 0;
}

int knight_tour_recursive(int **chess, int x, int y, int index)
{
    // base case
    if (chess[x][y] != 0)
        return 0;

    chess[x][y] = path++;

    if (index == 63)
        return 1;

    if (can_move(x+2, y+1) && knight_tour_recursive(chess, x+2, y+1, index+1))
        return 1;

    if (can_move(x+1, y+2) && knight_tour_recursive(chess, x+1, y+2, index+1))
        return 1;

    if (can_move(x-1, y+2) && knight_tour_recursive(chess, x-1, y+2, index+1))
        return 1;

    if (can_move(x-2, y+1) && knight_tour_recursive(chess, x-2, y+1, index+1))
        return 1;

    if (can_move(x-2, y-1) && knight_tour_recursive(chess, x-2, y-1, index+1))
        return 1;

    if (can_move(x-1, y-2) && knight_tour_recursive(chess, x-1, y-2, index+1))
        return 1;

    if (can_move(x+1, y-2) && knight_tour_recursive(chess, x+1, y-2, index+1))
        return 1;

    if (can_move(x+2, y-1) && knight_tour_recursive(chess, x+2, y-1, index+1))
        return 1;

    chess[x][y] = 0;
    path--;
    return 0;
}

int main ()
{
    int **chess;
    int i, j;

    chess = new int*[8];
    for (i = 0; i < 8; ++i)
        chess[i] = new int [8];

    for (i = 0; i < 8; ++i) {
        for (j = 0; j < 8; ++j) {
            chess[i][j] = 0;
        }
    }

    cout << "Check if possible to cover all checks only once: " << knight_tour_recursive(chess, 0, 0, 0) << endl;
    cout << "printing chess board: " << endl;
    for (i = 0; i < 8; ++i) {
        for (j = 0; j < 8; ++j) {
            cout << chess[i][j] << "  ";
        }
        cout << endl;
    }
    return 0;
}

