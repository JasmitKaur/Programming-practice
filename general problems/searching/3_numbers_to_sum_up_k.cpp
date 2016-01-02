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

void find_3_numbers_to_sum_k(int *a, int n, int data)
{
    bubble_sort(a, n);
    print_array(a, n);

    int i = 0, j = 0, k = 0;
    for (i = 0; i < n; i++) {
        for (j = i+1, k = n-1; j < k; ) {
            if (a[i] + a[j] + a[k] == data) {
                cout << a[i] << " + " << a[j] << " + " << a[k] << " = " << data << endl;
                return;
            } else if (a[i] + a[j] + a[k] > data)
                k--;
            else
                j++;
        }
    }
    cout << "No such data!" << endl;
}

int main ()
{
    int a[12] = {5, 19, 3, 12, 9, 6, 4, 29, 43, 7, 14, 17};

    int k = 0;
    cout << "Enter k = ";
    cin >> k;

    find_3_numbers_to_sum_k(a, 12, k);

    return 0;
}

