
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

int longest_increasing_subsequence(int *a, int n)
{
    int i, j;
    int LIS[n];

    for (i = n-1; i >= 0; --i)
        LIS[i] = 1;

    for (i = n-1; i >= 0; --i) {
        for (j = i + 1; j < n; ++j) {
            int local_max = 0;
            if (a[i] < a[j] && LIS[i] < 1 + LIS[j]) {
                LIS[i] = 1 + LIS[j];
            }
        }
    }

    int max_lis = 0, max_i = 0;
    for (i = 0; i < n; ++i) {
        if (LIS[i] > max_lis) {
            max_lis = LIS[i];
            max_i = i;
        }
    }

    return max_lis;
}

int main ()
{
    int a[11] = {5, 6, 2, 3, 4, 1, 9, 9, 8, 9, 5};

    cout << "len of LIS is: " << longest_increasing_subsequence(a, 11) << endl;

    return 0;
}
