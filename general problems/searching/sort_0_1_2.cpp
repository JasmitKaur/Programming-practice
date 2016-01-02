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

void element_swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void sort_zero_one_two(int *a, int n)
{
    if (!a || n < 0)
        return;

    int left = 0, mid = 0, right = n-1;
    while (mid <= right) {
        if (a[mid] == 0) {
            element_swap(&a[left], &a[mid]);
            mid++;
            left++;
        } else if (a[mid] == 1) {
            mid++;
        } else {
            element_swap(&a[mid], &a[right]);
            right--;
        }
    }

    cout << "Sorted : ";
    print_array(a, n);
}

int main ()
{
    int a[12] = {0, 1, 1, 0, 1, 2, 1, 2, 0, 0, 0, 1};

    cout << "Original array: ";
    print_array(a, 12);

    sort_zero_one_two(a, 12);
    return 0;
}

