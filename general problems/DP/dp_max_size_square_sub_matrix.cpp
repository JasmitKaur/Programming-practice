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

int max_size_square_submatrix_dp_bottom_up(int **a, int m, int n)
{
    int L[m][n];
    int i, j;

    for (i = 0; i < m; ++i) {
        L[i][0] = a[i][0];
    }

    for (j = 0; j < n; ++j) {
        L[0][j] = a[0][j];
    }

    for (i = 1; i < m; ++i) {
        for (j = 1; j < n; ++j) {
            if (a[i][j])
                L[i][j] = min(L[i-1][j], min(L[i][j-1], L[i-1][j-1])) + 1;
            else
                L[i][j] = 0;
        }
    }

    int max = 0;
    for (i = 0; i < m; ++i) {
        for (j = 0; j < n; ++j) {
            if (L[i][j] > max)
                max = L[i][j];
        }
    }
    return max;
}

int main ()
{
    int i, j;

    int **a;
    a = new int*[6];
    for (i = 0; i < 6; ++i)
        a[i] = new int[5];

    a[0][0] = 0;
    a[0][1] = 1;
    a[0][2] = 1;
    a[0][3] = 0;
    a[0][4] = 1;

    a[1][0] = 1;
    a[1][1] = 1;
    a[1][2] = 0;
    a[1][3] = 1;
    a[1][4] = 0;

    a[2][0] = 0;
    a[2][1] = 1;
    a[2][2] = 1;
    a[2][3] = 1;
    a[2][4] = 0;

    a[3][0] = 1;
    a[3][1] = 1;
    a[3][2] = 1;
    a[3][3] = 1;
    a[3][4] = 0;

    a[4][0] = 1;
    a[4][1] = 1;
    a[4][2] = 1;
    a[4][3] = 1;
    a[4][4] = 1;

    a[5][0] = 0;
    a[5][1] = 0;
    a[5][2] = 0;
    a[5][3] = 0;
    a[5][4] = 0;

    cout << "Max size square sub matrix - dp (bottom_up): " << max_size_square_submatrix_dp_bottom_up(a, 6, 5) << endl;

    return 0;
}

