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

int subset_sum_recursive_without_result(int s, int *a, int index, int n)
{
    if (s == 0)
        return 1;

    if (index >= n)
        return 0;

    int i;
    for (i = index; i < n; ++i) {
        if ((s - a[index] >= 0 && subset_sum_recursive_without_result(s - a[index], a, index+1, n))
            || subset_sum_recursive_without_result(s, a, index+1, n))
                return 1;
    }

    return 0;
}

int subset_sum_recursive_with_result(int s, int *a, int index, int n, int *res, int *r_i)
{
    if (s == 0)
        return 1;

    if (index >= n)
        return 0;

    int i;
    for (i = index; i < n; ++i) {
        if (s - a[index] >= 0) {
            res[*r_i] = a[index];
            *r_i += 1;
            if (subset_sum_recursive_with_result(s - a[index], a, index+1, n, res, r_i))
                return 1;
            else
                *r_i -= 1;;
        }

        if (subset_sum_recursive_with_result(s, a, index+1, n,res, r_i))
            return 1;
    }

    return 0;
}

int subset_sum_dp_bottom_up(int s, int *a, int n)
{
    int **table;
    int i, j;


    table = new int*[n+1];
    for (i = 0; i <= n; ++i)
        table[i] = new int[s+1];

    for (i = 0; i <= n; ++i)
        table[i][0] = 1;    //0 sum can always be represented by empty subset

    for (j = 1; j <= s; ++j)
        table[0][j] = 0;    // any other sum can not be represented by empty subset

    for (j = 1; j <= s; ++j) {
        for (i = 1; i <= n; ++i) {
             table[i][j] = table[i-1][j]; // if sum = j can be made using subset till index i - 1, then its also true for index i
            if ((table[i][j] == 0) && ((j - a[i-1]) > 0))
                table[i][j] = table[i][j] || table[i-1][j - a[i]];
        }
    }

    // printing table array
    /*for (j = 0; j <= n; ++j) {
        for (i = 0; i <= s; ++i) {
             cout << table[j][i] << " ";
        }
        cout << endl;
    }*/

    //printing solution if one exists
    if (table[n][s]) {
        i = n;
        j = s;
        while (i > 0 && j > 0) {
            while (table[i-1][j])
                --i;
            cout << a[i-1] << " ";
            --i;
            j = j - a[i];
        }
        cout << endl;
    }

    return table[n][s];
}


int main ()
{
    int a[4] = {3, 2, 7, 1};
    int i, S = 13;
    int res[4] = {0, };
    int r_i = 0;

    cout << "subset sum - recursive: " << subset_sum_recursive_with_result(S, a, 0, 4, res, &r_i) << endl;
    for (i = 0; i < r_i; i++)
        cout << res[i] << " ";
    cout << endl;

    cout << "subset sum - dp (bottom_up): " << subset_sum_dp_bottom_up(S, a, 4) << endl;

    return 0;
}

