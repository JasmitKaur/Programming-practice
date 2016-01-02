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
    int i = 0;
    for (i = 0; i < n; i++)
        cout << a[i] << " ";
    cout << endl;
}

void find_2_repeated_numbers(int *a, int n, int *X, int *Y)
{
    if (!a || n < 0)
        return;

    int xored = a[0];
    int i, rightmost_bit_set;
    *X = 0;
    *Y = 0;

    for (i = 1; i <= n-2; i++)
        xored ^= i;

    for (i = 1; i < n; i++)
        xored ^= a[i];

    rightmost_bit_set = xored & ~(xored - 1);

    for (i = 1; i <= n-2; i++) {
        if (i & rightmost_bit_set)
            *X ^= i;
        else
            *Y ^= i;
    }
    for (i = 0; i < n; i++) {
        if (a[i] & rightmost_bit_set)
            *X ^= a[i];
        else
            *Y ^= a[i];
    }
}

int main ()
{
    int a[12] = {1,2,3,3,4,5,6,7,8,8,9,10};
    int m = 0, n = 0;

    find_2_repeated_numbers(a, 10, &m, &n);
    cout << "Repeated numbers are: " << m << " and " << n << endl;

    return 0;
}

