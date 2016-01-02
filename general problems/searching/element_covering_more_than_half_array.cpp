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

int find_element_covering_half_array(int *a, int n)
{
    if (!a || n < 0)
        return -1;

    bubble_sort(a, n);

    int i = 0, element = 0, counter = 0;
    for (i = 0; i < n; i++) {
        if (counter == 0) {
            element = a[i];
            counter++;
        } else if (element == a[i]) {
            counter++;
        } else
            counter--;
    }
    return element;
}

int main ()
{
    int a[12] = {5, 19, 5, 5, 5, 6, 4, 5, 5, 5, 14, 17};
    cout << "original array: ";
    print_array(a, 12);

    cout << "Element is: " << find_element_covering_half_array(a, 12) << endl;

    return 0;
}

