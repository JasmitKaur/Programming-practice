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

int rotated_array_find_pivot(int *a, int first, int last)
{
    if (!a || first > last)
        return -1;

    int mid = first + ((last - first)/2);
    if (a[mid] >= a[mid+1])
        return mid;
    else if (a[first] >= a[mid])
        return rotated_array_find_pivot(a, first, mid);
    else
        return rotated_array_find_pivot(a, mid, last);
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

int rotated_array_find_number(int *a, int first, int last, int data)
{
    if (!a || first > last)
        return -1;

    int pivot = rotated_array_find_pivot(a, first, last);
    if (data == a[pivot])
        return pivot;
    else if (data >= a[first])
        return binary_search_increasing(a, first, pivot-1, data);
    else
        return binary_search_increasing(a, pivot+1, last, data);
}

int rotated_array_find_number_in_one_pass(int *a, int first, int last, int data)
{
    if (!a || first > last)
        return -1;

    int mid = first + ((last - first)/2);
    if (a[mid] == data)
        return mid;
    else if (a[first] <= a[mid]) {    //first half is sorted
        if (data < a[mid] && data >= a[first])
            return rotated_array_find_number_in_one_pass(a, first, mid-1, data);
        else
            return rotated_array_find_number_in_one_pass(a, mid+1, last, data);
    } else {
        if (data > a[mid] && data <= a[last])
            return rotated_array_find_number_in_one_pass(a, mid+1, last, data);
        else
            return rotated_array_find_number_in_one_pass(a, first, mid-1, data);
    }
}

int main ()
{
    int a[12] = {15, 16, 19, 20, 25, 1, 3, 4, 5, 7, 10, 14};

    cout << "Original array: ";
    print_array(a, 12);

    cout << "pivot: " << a[rotated_array_find_pivot(a, 0, 11)] << endl;

    int data, is_present;
    cout << "Enter an element to be searched: ";
    cin >> data;
    is_present = rotated_array_find_number_in_one_pass(a, 0, 11, data);
    if (is_present != -1)
        cout << "Yes. index = " << is_present << endl;
    else
        cout << "No\n";

    return 0;
}

