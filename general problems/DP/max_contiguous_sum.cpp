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

int max_cont_sum(int *a, int n, int *s, int * e)
{
    int i = 0, max_sum = -100, sum = 0;
    *s = 0;

    for (i = 0; i < n; ++i) {
        sum += a[i];
        if (sum < 0) {
            sum = 0;
            *s = i + 1;
        }

        if (sum > max_sum) {
            max_sum = sum;
            *e = i;
        }
    }
    return max_sum;
}

int main ()
{
    //int a[6] = {-2, 11, -4, 13, -5, 2};
    int a[6] = {1, -3, 4, -2, -1, 6};

    int i, j;
    cout << "Max contiguos sum is: " << max_cont_sum(a, 6, &i, &j) << endl;
    cout << "\nFrom indexes " << i << " to " << j << endl;
    return 0;
}

