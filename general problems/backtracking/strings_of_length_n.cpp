
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

int size;

void n_strings(int *a, int n, int k)
{
    if (n < 0) {
        for (int i = 0; i < size; ++i)
            cout << a[i] << " ";
        cout << endl;
        return;
    }
    for (int j = 0; j < k; ++j) {
        a[n] = j;
        n_strings(a, n-1, k);
    }
}

//problem: Generate all strings of length 'size' drawn from 0 to k-1
int main ()
{
    int k;
    cout << "Enter size and k ";
    cin >> size >> k;

    int *a = new int[size];
    n_strings(a, size-1, k);
    return 0;
}
