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

int binary_search_increasing(int *a, int first, int last, int data)
{
    if (!a || first > last)
        return -1;

    int mid = first + ((last - first)/2);
    if (a[mid] == data)
        return mid;
    else if (a[mid] < data)
        return binary_search_increasing(a, mid+1, last, data);
    else
        return binary_search_increasing(a, first, mid-1, data);
}

int binary_search_decreasing(int *a, int first, int last, int data)
{
    if (!a || first > last)
        return -1;

    int mid = first + ((last - first)/2);
    if (a[mid] == data)
        return mid;
    else if (a[mid] < data)
        return binary_search_increasing(a, first, mid-1, data);
    else
        return binary_search_increasing(a, mid+1, last, data);
}

int bitonic_find_max(int *a, int first, int last)
{
    if (!a || first > last)
        return -1;

    if (first == last)
        return first;

    if (first == last - 1)
        return (a[first] > a[last]) ? first : last;

    int mid = first + ((last - first)/2);
    if (a[mid -1] < a[mid] && a[mid] > a[mid + 1])
        return mid;
    else if (a[mid -1] < a[mid] && a[mid] < a[mid + 1])
        return bitonic_find_max(a, mid+1, last);
    else
        return bitonic_find_max(a, first, mid-1);
}

int bitonic_search(int *a, int first, int last, int data)
{
    if (!a || first > last)
        return -1;

    int pivot = bitonic_find_max(a, first, last);

    if (data == a[pivot])
        return pivot;
    else if (a[first] <= data && data < a[pivot])
        return binary_search_increasing(a, first, pivot-1, data);
    else
        return binary_search_decreasing(a, pivot+1, last, data);
}

int main ()
{
    int a[10] = {24, 75, 90, 62, 48, 30, 12, 5, 3, 2};

    cout << "Original array: ";
    print_array(a, 10);

    int data, is_present;
    cout << "Enter an element to be searched: ";
    cin >> data;
    is_present = bitonic_search(a, 0, 9, data);
    if (is_present != -1)
        cout << "Yes. index = " << is_present << endl;
    else
        cout << "No\n";

    return 0;
}

