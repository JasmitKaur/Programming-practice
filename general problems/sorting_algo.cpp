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

void selection_sort(int *a, int n)
{
    int i, j, min_i;
    for (i = 0; i < n-1; i++) {
        min_i = i;
        for (j = i+1; j < n; j++) {
            if (a[j] < a[min_i])
                min_i = j;
        }
        if (min_i != i)
            element_swap(&a[min_i], &a[i]);
    }
}

void insertion_sort(int *a, int n)
{
    int i, j, val;
    for (i = 1; i < n; i++) {
        val = a[i];
        j = i;
        while (a[j-1] > val && j > 0) {
            a[j] = a[j-1];
            j--;
        }
        a[j] = val;
    }
}

void merge_helper(int *a, int *temp, int low, int mid, int high)
{
    int i, low_end = mid - 1, temp_pos = low, size = high - low + 1;

    while (low <= low_end && mid <= high) {
        if (a[low] <= a[mid]) {
            temp[temp_pos] = a[low];
            low++;
        } else {
            temp[temp_pos] = a[mid];
            mid++;
        }
        temp_pos++;
    }

    while (low <= low_end) {
        temp[temp_pos] = a[low];
        temp_pos++;
        low++;
    }

    while (mid <= high) {
        temp[temp_pos] = a[mid];
        temp_pos++;
        mid++;
    }

    temp_pos--;
    for (i = 0; i < size; i++) {
        a[temp_pos] = temp[temp_pos];
        temp_pos--;
    }
}

void merge_sort(int *a, int *temp, int low, int high)
{
    int mid;
    if (low < high) {
        mid = (low + high)/2;
        merge_sort(a, temp, low, mid);
        merge_sort(a, temp, mid+1, high);
        merge_helper(a, temp, low, mid+1, high);
    }
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

void counting_sort(int *a, int *b, int n, int k)
{
    int *c = new int[k];
    int i = 0;

    for (i = 0; i < k; i++)
        c[i] = 0;

    for (i = 0; i < n; i++)
        c[a[i]]++;

    for (i = 1; i < k; i++)
        c[i] += c[i-1];

    for (i = 0; i < n; i++) {
        b[c[a[i]] - 1] = a[i];
        c[a[i]] -= 1;
    }
}

int main ()
{
    //int a[8] = {6, 8, 1, 4, 5, 3, 7, 2};
    int a[8] = {2, 1, 19, 3, 8, 14, 9, 6};

    cout << "Original array: ";
    print_array(a, 8);

    bubble_sort(a, 8);
    cout << "Bubble sorted: ";;
    print_array(a, 8);

    selection_sort(a, 8);
    cout << "Selection sorted: ";;
    print_array(a, 8);

    insertion_sort(a, 8);
    cout << "Insertion sorted: ";;
    print_array(a, 8);

    int temp[8];
    merge_sort(a, temp, 0, 7);
    cout << "Merge sorted: ";;
    print_array(a, 8);

    quick_sort(a, 0, 7);
    cout << "Quick sorted: ";;
    print_array(a, 8);

    int b[8];
    counting_sort(a, b, 8, 20);
    cout << "Counting sorted: ";;
    print_array(b, 8);

    return 0;
}

