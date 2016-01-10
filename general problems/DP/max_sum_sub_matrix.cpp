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

int kadanes(int *a, int n, int *x1, int *x2, int *sum)
{
    int i = 0, temp = 0;
    *x1 = *x2 = *sum = 0;

    for (i = 0; i < n; ++i) {
        temp += a[i];
        if (temp < 0) {
            temp = 0;
            *x1 = i + 1;
        }
        if (temp > *sum) {
            *sum = temp;
            *x2 = i;
        }
    }
    return 0;
}

int max_sum_sub_matrix(int **a, int m, int n, int x1, int y1, int x2, int y2, int max_sum)
{
    int i, j, k, temp[n];
    int temp_sum = 0, t1 = 0, t2 = 0;
    x1 = y1 = x2 = y2 = max_sum = 0;

    for (i = 0; i < m; ++i) {
        //initialize temp array of size n
        for (k = 0; k < n; ++k)
            temp[k] = 0;

        for (j = i; j < m; ++j) {

            for (k = 0; k < n; ++k)
                temp[k] += a[j][k];

            kadanes(temp, n, &t1, &t2, &temp_sum);

            if (temp_sum > max_sum) {
                x1 = t1;
                y1 = i;
                x2 = t2;
                y2 = j;
                max_sum = temp_sum;
            }
        }
    }

    cout << "max sum = " << max_sum << endl;
    for (i = y1; i <= y2; ++i) {
        for (j = x1; j <= x2; ++j) {
            cout << a[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}

int main ()
{
    int i, j;

    int **a;
    a = new int*[4];
    for (i = 0; i < 4; ++i)
        a[i] = new int[5];

    a[0][0] = 1;
    a[0][1] = 2;
    a[0][2] = -1;
    a[0][3] = -4;
    a[0][4] = -20;

    a[1][0] = -8;
    a[1][1] = -3;
    a[1][2] = 4;
    a[1][3] = 2;
    a[1][4] = 1;

    a[2][0] = 3;
    a[2][1] = 8;
    a[2][2] = 10;
    a[2][3] = 1;
    a[2][4] = 3;

    a[3][0] = -4;
    a[3][1] = -1;
    a[3][2] = 1;
    a[3][3] = 7;
    a[3][4] = -6;

    /*int b[5] = {3, -4, 5, 1, 1};
    int sum, x1, x2;
    kadanes(b, 5, &x1, &x2, &sum);
    cout << "x1(" << x1 << ") x2(" << x2 << ") sum(" << sum <<")\n";*/

    max_sum_sub_matrix(a, 4, 5, 0, 0, 0, 0, 0);

    return 0;
}

