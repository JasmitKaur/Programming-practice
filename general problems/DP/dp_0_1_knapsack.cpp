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

int knapsack_recursive(int C, int *s, int *v, int index, int n)
{
    if (index >= n)
        return 0;

    if (C - s[index] < 0)
        return 0;

    return max(v[index] + knapsack_recursive(C - s[index], s, v, index + 1, n), knapsack_recursive(C, s, v, index + 1, n));
}

int knapsack_dp(int C, int *s, int *v, int n)
{
    int **M;
    int i, j;

    M = new int*[n+1];
    for (i = 0; i <= n; ++i)
        M[i] = new int[C+1];

    for (i = 0; i <= C; ++i)
        M[0][i] = 0;

    for (i = 0; i <= n; ++i)
        M[i][0] = 0;

    for (i = 1; i <= n; ++i) {
        for (j = 1; j <= C; ++j) {
            M[i][j] = 0;
            if (j-s[i-1] >= 0)
                M[i][j] = max(M[i-1][j], v[i-1] + M[i-1][j-s[i-1]]);
        }
    }

    for (i = 0; i <= n; ++i) {
        for (j = 0; j <= C; ++j) {
            cout << M[i][j] << " ";
        }
        cout << endl;
    }

    return M[i-1][j-1];
}

int main ()
{
    int s[5] = {2, 3, 4, 5, 9};
    int v[5] = {3, 4, 5, 8, 10};
    int C = 10;

    cout << "knapsack solution- recursive: " << knapsack_recursive(C, s, v, 0, 5) << endl;
    cout << "knapsack solution- dp: " << knapsack_dp(C, s, v, 5) << endl;

    return 0;
}

