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

int max_conti_sum_recursive(int *a, int i, int j)
{
    int sum = 0;

    if (i == j) {
        if (a[i] > sum)
            return a[i];
        else
            return sum;
    } else if (i > j) {
        return sum;
    } else {
        return max(a[i] + max_conti_sum_recursive(a, i+2, j), max_conti_sum_recursive(a, i+1, j));
    }
}

int max_conti_sum_dp(int *a, int i, int j)
{
    int *res = new int[j-i+1];
    int k;

    if (a[j] > 0)
        res[j] = a[j];
    else
        res[j] = 0;

    res[j-1] = (max(a[j], a[j-1]) > 0) ? max(a[j], a[j-1]) : 0;

    for (k = j-2; k >= i; --k) {
        res[k] = max(a[k] + res[k+2], res[k+1]);
    }

    for (k = i; k <= j; ++k)
        cout << res[k] << " ";
    cout << endl;

    return res[i];
}

int main ()
{
    int a[6] = {-2, 11, -4, 13, -5, 2};

    cout << "max conti sum: recursive: " << max_conti_sum_recursive(a, 0, 5) << endl;

    cout << "max conti sum using dp: " << max_conti_sum_dp(a, 0, 5) << endl;

    return 0;
}

