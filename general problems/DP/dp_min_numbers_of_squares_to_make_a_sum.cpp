
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

int solution_recursive(int *a, int n, int T)
{
    int i, ans = T, temp = 0;

    if (T == 0)
        return 0;

    for (i = 0; i <= n; ++i) {
        if (T - a[i] >= 0) {
            temp = 1 + solution_recursive(a, n, T - a[i]);
            if (temp < ans) {
                ans = temp;
            }
        }
    }
    return ans;
}

int solution_dp(int *a, int n, int T)
{
    int res[T+1];
    int i, j;

    res[0] = 0;
    for (i = 1; i < T; ++i)
        res[i] = 1000;

    for (i = 1; i <= T; ++i) {
        for (j = 0; j <= n; ++j) {
            if (i - a[j] >= 0) {
                if ((1 + res[i - a[j]]) < res[i])
                    res[i] = 1 + res[i - a[j]];
            }
        }
    }

    return res[T];
}

int min_no_of_squares(int n)
{
    int i, j = -1;
    int a[n];

    for (i = 1; i * i <= n; ++i)
        a[++j] = i * i;

    return solution_dp(a, j, n);
}

int main ()
{
    // 12 = (4*4) + (4*4) + (4*4)
    cout << min_no_of_squares(12) << endl;

    return 0;
}

