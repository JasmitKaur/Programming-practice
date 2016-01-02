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

void sep_even_odd(int *a, int n)
{
    if (!a || n < 0)
        return;

    int left = 0, right = n-1;
    while (left < right) {
        while (!(a[left] & 1))
            left++;
        while (a[right] & 1)
            right--;
        if (left < right)
            element_swap(&a[left], &a[right]);
    }

    cout << "Separated even & odd numbers: ";
    print_array(a, n);
}

int main ()
{
    int a[7] = {12, 34, 45, 9, 8, 90, 3};

    cout << "Original array: ";
    print_array(a, 7);

    sep_even_odd(a, 7);
    return 0;
}

