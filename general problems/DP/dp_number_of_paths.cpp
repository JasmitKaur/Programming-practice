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

#define MY_INT_MAX 100

int number_of_paths_recursive(int i, int j, int m, int n)
{
    if (i > m || j > n)
        return 0;

    if (i == m && j == n)
        return 1;

    int p1 = number_of_paths_recursive(i, j+1, m, n);
    int p2 = number_of_paths_recursive(i+1, j, m, n);
    return p1 + p2;
}

int number_of_paths_dp_bottom_up(int p, int q, int m, int n)
{
    int **table;
    int i, j, rows = m-p+1, cols = n-q+1;


    table = new int*[rows];
    for (i = 0; i < rows; ++i)
        table[i] = new int[cols];

    for (i = 0; i < rows; ++i)
        table[i][0] = 1;

    for (j = 0; j < cols; ++j)
        table[0][j] = 1;

    for (i = 1; i < rows; ++i) {
        for (j = 1; j < cols; ++j) {
            table[i][j] =  table[i-1][j] +  table[i][j-1];
        }
    }

    /*for (i = 0; i < n; ++i) {
        for (j = 0; j < n; ++j) {
            cout << table[i][j] << " ";
        }
        cout << endl;
    }*/
    return table[--i][--j];
}


int main ()
{
    int m, n;

    cout << "Enter row: ";
    cin >> m;
    cout << "Enter column: ";
    cin >> n;

    cout << "Number of paths from top-left to bottom-right - recursive: " << number_of_paths_recursive(0, 0, m-1, n-1) << endl;

    cout << "Number of paths from top-left to bottom-right - dp (bottom_up): " << number_of_paths_dp_bottom_up(0, 0, m-1, n-1) << endl;

    return 0;
}

