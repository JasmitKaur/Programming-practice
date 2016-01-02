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

void bubble_sort(int *a, int n)
{
    int pass, i;
    int swapped = 1;

    for (pass = n-1; pass > 0 && swapped; pass--) {
        swapped = 0;
        for (i = 0; i < pass; i++) {
            if (a[i] > a[i+1]) {
                element_swap(&a[i], &a[i+1]);
                swapped = 1;
            }
        }
    }
}

int sum_closest_to_zero(int *a, int n)
{
    if (!a || n < 0)
        return -1;

    bubble_sort(a, n);

    int i, j;
    int x_p, y_p, x_n, y_n, closest_sum = 0;
    int pos_sum = 1000, neg_sum = -1000;
    int local_sum = 0;

    for (i = 0, j = n-1; i < j; ) {
        local_sum = a[i] + a[j];
        if (local_sum > 0) {
            if (local_sum < pos_sum) {
                pos_sum = local_sum;
                x_p = a[i];
                y_p = a[j];
            }
            j--;
        } else if (local_sum < 0) {
            if (local_sum > neg_sum) {
                neg_sum = local_sum;
                x_n = a[i];
                y_n = a[j];
            }
            i++;
        }
    }
    if (abs(neg_sum) < pos_sum) {
        closest_sum = abs(neg_sum);
        cout << x_n << " + " << y_n << " = " << closest_sum << endl;
    } else {
        closest_sum = pos_sum;
        cout << x_p << " + " << y_p << " = " << closest_sum << endl;
    }
    return closest_sum;
}

int main ()
{
    int a[6] = {1, 60, -10, 70, -80, 85};
    cout << "original array: ";
    print_array(a, 6);

    cout << "Sum closest to zero: " << sum_closest_to_zero(a, 6) << endl;

    return 0;
}

