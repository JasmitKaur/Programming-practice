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

int sorted_array_first_occurrence(int *a, int first, int last, int data)
{
    if (!a || first > last)
        return -1;

    if (first == last && a[first] == data)
        return first;

    int mid = first + ((last - first)/2);
    if (a[mid] == data && a[mid-1] != data)
        return mid;
    else if (a[mid] < data)
        return sorted_array_first_occurrence(a, mid+1, last, data);
    else
        return sorted_array_first_occurrence(a, first, mid-1, data);
}

int sorted_array_last_occurrence(int *a, int first, int last, int data)
{
    if (!a || first > last)
        return -1;

    if (first == last && a[first] == data)
        return first;

    int mid = first + ((last - first)/2);
    if (a[mid] == data && a[mid+1] != data)
        return mid;
    else if (a[mid] > data)
        return sorted_array_last_occurrence(a, first, mid-1, data);
    else
        return sorted_array_last_occurrence(a, mid+1, last, data);
}

int main ()
{
    int a[12] = {1, 2, 3, 3, 4, 5, 5, 6, 6, 6, 9, 9};

    cout << "Original array: ";
    print_array(a, 12);

    int data, is_present;
    cout << "Enter an element to be searched: ";
    cin >> data;
    is_present = sorted_array_first_occurrence(a, 0, 11, data);
    if (is_present != -1) {
        cout << "Found!\nfirst occurrence = " << is_present << endl;
        cout << "last occurrence = " << sorted_array_last_occurrence(a, 0, 11, data) << endl;
    } else
        cout << "Not found" << endl;

    return 0;
}

