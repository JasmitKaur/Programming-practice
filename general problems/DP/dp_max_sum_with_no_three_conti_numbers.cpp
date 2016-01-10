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
    int n1, n2, n3, n4;

    if (i == j) {
        return a[i];
    } else if (i == j-1) {
        n1 = a[i] + a[j];
        return max(a[i], max(a[j], n1));
    } else if (i == j-2) {
        n1 = a[i] + a[i+1];
        n2 = a[i] + a[i+2];
        n3 = a[i+1] + a[i+2];
        return max(max(max(a[i], a[i+1]), max(a[j], n1)), max(n2, n3));
    } else {
        n1 = a[i] + max_conti_sum_recursive(a, i+3, j); //skipped a[i+1] and a[i+2]
        n2 = a[i] + a[i+1] + max_conti_sum_recursive(a, i+3, j); //skipped a[i+2]
        n3 = a[i] + max_conti_sum_recursive(a, i+2, j); //skipped a[i+1]
        n4 = max_conti_sum_recursive(a, i+1, j);

        return max(max(n1, n2), max(n3, n4));
    }
}

int max_conti_sum_dp(int *a, int i, int j)
{
    int *res = new int[j-i+1];
    int k;

    res[j] = a[j];
    res[j-1] = max(a[j-1], max(a[j], a[j] + a[j-1]));
    res[j-2] = max(max(max(a[j], a[j-1]), max(a[j], a[j] + a[j-1])), max(a[j] + a[j-2], a[j-1] + a[j-2]));

    for (k = j-3; k >= i; --k) {
        res[k] = max(max(a[k] + res[k+3], a[k] + a[k+1] + res[k+3]), max(a[k] + res[k+2], res[k+1]));
    }

    for (k = i; k <= j; ++k)
        cout << res[k] << " ";
    cout << endl;

    return res[i];
}

int main ()
{
    //problem is to find out max contiguous sum with no three continuous numbers
    // but we can select 2 contiguous numbers and skip the third one
    int a[6] = {-2, 11, -4, 13, -5, 2};

    cout << "max contiguous sum with no three continuous numbers: recursive: " << max_conti_sum_recursive(a, 0, 5) << endl;

    cout << "max contiguous sum with no three continuous numbers using dp: " << max_conti_sum_dp(a, 0, 5) << endl;

    return 0;
}
