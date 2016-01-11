
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

void arrange(int *a, int s, int n, int is_greater)
{
    if (s + 2 == n)
        return;

    int temp;
    if (is_greater) {   //ie a[s+1] > a[s] & a[s+1] > a[s+2]
        if (a[s+1] < a[s+2]) {
            temp = a[s+1];
            a[s+1] = a[s+2];
            a[s+2] = temp;
        } else if (a[s+1] < a[s]) {
            temp = a[s+1];
            a[s+1] = a[s];
            a[s] = temp;
        }
    } else {
        if (a[s+1] > a[s+2]) {
            temp = a[s+1];
            a[s+1] = a[s+2];
            a[s+2] = temp;
        } else if (a[s+1] > a[s]) {
            temp = a[s+1];
            a[s+1] = a[s];
            a[s] = temp;
        }
    }
    arrange(a, s+1, n, 1-is_greater);
    return;
}

int main ()
{
    int a[10] = {15, 3, 57, 29, 89, 12, 45, 9, 8, 23};

    /* arrange array in given order:
        a < b > c < d > e ...
    */

    arrange(a, 0, 10, 1);
    print_array(a, 10);
    return 0;
}

