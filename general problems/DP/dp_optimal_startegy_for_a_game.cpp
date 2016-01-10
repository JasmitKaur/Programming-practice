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

int game_strategy_recursive(int *a, int s, int e)
{
    if (s == e)
        return a[s];

    if (s + 1 == e)
        return max(a[s], a[e]);

    int v1 = min(game_strategy_recursive(a, s+2, e), game_strategy_recursive(a, s+1, e-1)) + a[s];  // If we pick s, he can pick s+1 or e
    int v2 = min(game_strategy_recursive(a, s+1, e-1), game_strategy_recursive(a, s, e-2)) + a[e];  // If we pick e, he can pick s or e-1
    return max(v1, v2);
}

int game_strategy_dp_bottom_up(int *a, int n)
{
    int **table;
    int i, j, v1 = 0, v2 = 0;


    table = new int*[n];
    for (i = 0; i < n; ++i)
        table[i] = new int[n];

    for (i = 0; i < n; ++i) {
        table[i][i] = a[i];    // when only 1 coin is left
        if (i < n-1)
            table[i][i+1] = max(a[i], a[i+1]);  // when 2 coins are left
    }

    for (i = n-1; i >= 0; --i) {
        for (j = i+2; j < n; ++j) {
            v1 = min(table[i+2][j], table[i+1][j-1]) + a[i];
            v2 = min(table[i+1][j-1], table[i][j-2]) + a[j];
            table[i][j] = max(v1, v2);
        }
    }

    for (i = 0; i < n; ++i) {
        for (j = 0; j < n; ++j) {
            cout << table[i][j] << " ";
        }
        cout << endl;
    }
    return table[0][n-1];
}


int main ()
{
    int a[4] = {5, 15, 3, 7};   //ans = 22
    //int b[4] = {5, 3, 7, 10};   //ans = 15

    cout << "Optimal strategy for a game - recursive: " << game_strategy_recursive(a, 0, 3) << endl;

    cout << "Optimal strategy for a game - dp (bottom_up): " << game_strategy_dp_bottom_up(a, 4) << endl;

    return 0;
}

