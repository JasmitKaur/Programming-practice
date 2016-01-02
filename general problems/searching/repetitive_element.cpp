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

int quick_partition(int *a, int low, int high)
{
    int p_item = a[low], p_pos = low;
    while (low < high) {
        while (a[low] <= p_item)
            low++;
        while (a[high] > p_item)
            high--;
        if (low < high)
            element_swap(&a[low], &a[high]);
    }
    element_swap(&a[p_pos], &a[high]);
    return high;
}

void quick_sort(int *a, int low, int high)
{
    int pivot;
    if (low < high) {
        pivot = quick_partition(a, low, high);
        quick_sort(a, low, pivot - 1);
        quick_sort(a, pivot + 1, high);
    }
}

int does_duplicate_exist(int *a, int n)
{
    if (!a || n < 0) {
        cout << "Invalid inputs!\n";
        return -1;
    }

    int i;

    quick_sort(a, 0, n-1);
    for (i = 0; i < n-1; i++) {
        if (a[i] == a[i+1])
            return i;
    }
    return -1;
}

int find_max_repetitive_element(int *a, int n)
{
    if (!a || n < 0) {
        cout << "Invalid inputs!\n";
        return -1;
    }

    int i, curr = 1, max_c = 1, max_i = -1;

    quick_sort(a, 0, n-1);

    for (i = 0; i < n-1; i++) {
        if (a[i] == a[i+1]) {
            curr++;
            if (curr > max_c) {
                max_c = curr;
                max_i = i;
            }
        } else {
            curr = 1;
        }
    }
    return max_i;
}

int find_max_repetitive_element_hash(int *a, int n)
{
    map<int, int> mp;
    int i, max_c = 1, max_i = -1;

    for (i = 0; i < n; i++) {
        if (mp[a[i]]) {
            mp[a[i]] += 1;
            if (mp[a[i]] > max_c) {
                max_c = mp[a[i]];
                max_i = i;
            }
        } else
            mp[a[i]] = 1;
    }
    return max_i;
}

int main ()
{
    //int a[8] = {6, 8, 1, 4, 5, 3, 7, 2};
    int a[8] = {2, 1, 8, 3, 8, 3, 8, 6};
    //int a[8] = {1, 2, 3, 3, 6, 8, 9, 19};

    cout << "Original array: ";
    print_array(a, 8);

    quick_sort(a, 0, 7);
    /*cout << "sorted array : " << endl;
    print_array(a, 8);*/

    cout << "Does duplicate exists?" << endl;
    int exists = does_duplicate_exist(a, 8);
    if (exists != -1)
        cout << "YES. \nRepeated element is " << a[exists] << endl;
    else
        cout << "NO" << endl;

    cout << "Max repetitive element:" << endl;
    exists = find_max_repetitive_element(a, 8);
    if (exists != -1)
        cout << "YES. \nMax repeated element is " << a[exists] << endl;
    else
        cout << "NO" << endl;

    cout << "Max repetitive element using hash:" << endl;
    exists = find_max_repetitive_element_hash(a, 8);
    if (exists != -1)
        cout << "YES. \nMax repeated element is " << a[exists] << endl;
    else
        cout << "NO" << endl;
    return 0;
}

