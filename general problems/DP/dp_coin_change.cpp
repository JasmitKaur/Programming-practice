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

int coin_change_recursive(int v, int *coins, int n)
{
    if (v == 0)
        return 0;

    int min_coins = MY_INT_MAX;
    int i, temp;

    for (i = 0; i < n; ++i) {
        if (v - coins[i] >= 0) {
            temp = 1 + coin_change_recursive(v - coins[i], coins, n);
            if (temp < min_coins)
                min_coins = temp;
        }
    }

    return min_coins;
}

int coin_change_dp_top_down(int v, int *res, int *coins, int n)
{
    if (res[v] < MY_INT_MAX) {
        //cout << "returning for v = " << v << endl;
        return res[v];
    }

    if (v == 0)
        return 0;

    int i, temp;
    for (i = 0; i < n; ++i) {
        if (v - coins[i] >= 0) {
            temp = 1 + coin_change_dp_top_down(v - coins[i], res, coins, n);
            if (temp < res[v])
                res[v] = temp;
        }
    }
    return res[v];
}

int coin_change_dp_bottom_up(int v, int *res, int *coins, int n)
{
    int i, j, temp;
    res[0] = 0;
    for (i = 1; i <= v; ++i) {
        for (j = 0; j < n; ++j) {
            if (i - coins[j] >= 0) {
                temp = 1 + res[i - coins[j]];
                if (temp < res[i])
                    res[i] = temp;
            }
        }
    }

    for (i = 0; i <= v; ++i)
        cout << res[i] << " ";
    cout << endl;

    return res[v];
}

int main ()
{
    //int coins[3] = {25, 10, 5};
    //int v = 30;

    int coins[4] = {9, 5, 6, 1};
    int i, v = 11;
    int *res = new int[v+1];
    for (i = 0; i <= v; ++i)
        res[i] = MY_INT_MAX;

    cout << "Min number of coins required - recursive: " << coin_change_recursive(v, coins, 4) << endl;
    cout << "Min number of coins required - dp (top_down): " << coin_change_dp_top_down(v, res, coins, 4) << endl;
    cout << "Min number of coins required - dp (bottom_up): " << coin_change_dp_bottom_up(v, res, coins, 4) << endl;

    return 0;
}

