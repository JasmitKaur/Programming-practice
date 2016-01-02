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

int max_diff_between_2_elements(int *a, int n)
{
    if (!a || n < 0)
        return -1;

    int max_diff = 0, i = 0;
    int min = a[0];

    for (i = 1; i < n; i++) {
        if (a[i] < min)
            min = a[i];
        else if ((a[i] - min) > max_diff)
            max_diff = a[i] - min;
    }
    return max_diff;
}

int main ()
{
    int a[7] = {2, 3, 10, 6, 4, 8, 1};

    cout << "Original array: ";
    print_array(a, 7);

    cout << "max diff = " << max_diff_between_2_elements(a, 7) << endl;
    return 0;
}

