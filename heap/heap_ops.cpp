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

struct heap {
    int *a;
    int capacity;
    int count;
    int is_max_heap;
};

#define FAILURE -1
#define SUCCESS 0

heap *create_heap(int capacity, int is_max_heap)
{
    heap *h = new heap;
    h->capacity = capacity;
    h->is_max_heap = is_max_heap;
    h->count = 0;
    h->a = new int[capacity];
    return h;
}

int left_child(heap *h, int i)
{
    int c = (2 * i) + 1;
    if (c < h->count)
        return c;
    else
        return -1;
}

int right_child(heap *h, int i)
{
    int c = (2 * i) + 2;
    if (c < h->count)
        return c;
    else
        return -1;
}

int parent(heap *h, int i)
{
    int p = (i - 1) / 2;
    if (p < 0)
        return -1;
    else
        return p;
}

void print_heap(heap *h)
{
    int i = 0;
    cout << "Count: " << h->count << endl;
    cout << "Capacity: " << h->capacity << endl;
    cout << "Is_max_heap: " << h->is_max_heap << endl;
    cout << "Array: ";
    for (i = 0; i < h->count; i++)
        cout << h->a[i] << " ";
    cout << endl;
}

int insert_into_heap(heap *h, int val)
{
    if (!h || h->capacity == h->count)
        return FAILURE;

    h->a[h->count] = val;
    h->count++;
    return SUCCESS;
}

void percolate_down(heap *h, int i)
{
    if (!h || i >= h->count)
        return;

    int l_child, r_child, min_i;
    l_child = left_child(h, i);
    r_child = right_child(h, i);

    if (l_child == -1 && r_child == -1)
        return;

    if (l_child != -1 && h->a[l_child] < h->a[i])
        min_i = l_child;
    else
        min_i = i;

    if (r_child != -1 && h->a[r_child] < h->a[min_i])
        min_i = r_child;

    if (min_i != i) {
        int temp = h->a[min_i];
        h->a[min_i] = h->a[i];
        h->a[i] = temp;
        percolate_down(h, min_i);
    }
    return;
}

void percolate_up(heap *h, int i)
{
    if (!h || i >= h->count || i <= 0)
        return;

    int p_id;
    p_id = parent(h, i);
    if (p_id == -1)
        return;

    if (h->a[p_id] > h->a[i]) {
        int temp = h->a[p_id];
        h->a[p_id] = h->a[i];
        h->a[i] = temp;
        percolate_up(h, p_id);
    }
    return;
}

void delete_element(heap *h, int i)
{
    if (!h || i < 0 || i >= h->count)
        return;

    int last_i = h->count - 1;

    // swap last_i and i
    int temp = h->a[last_i];
    h->a[last_i] = h->a[i];
    h->a[i] = temp;

    // reduce count
    h->count--;

    percolate_down(h, i);
}

void insert_element(heap *h, int data)
{
    if (!h || h->capacity == h->count)
        return;

    int last_i = h->count;

    // insert at last_i
    h->a[last_i] = data;

    // increase count
    h->count++;

    percolate_up(h, last_i);
}

void build_heap(heap *h, int *given_array, int size)
{
    if (!h || !given_array || size > h->capacity || size <= 0)
        return;

    h->count = size;
    int i = 0;
    for (i = 0; i < size; i++)
        h->a[i] = given_array[i];

    for (i = (size - 1)/2; i >= 0; i--)
        percolate_down(h, i);
}

void heap_sort(int *arr, int size)
{
    if (!arr || size <= 0)
        return;

    heap *h = create_heap(size, 0);
    build_heap(h, arr, size);

    int org_size = h->count;
    int i = 0;
    for (i = size - 1; i > 0; i--) {
        //swap 0 and i
        int temp = h->a[0];
        h->a[0] = h->a[i];
        h->a[i] = temp;

        h->count--;

        percolate_down(h, 0);
    }

    h->count = org_size;

    cout << "Sorting done: ";
    print_heap(h);
}

int main ()
{
    heap *h = create_heap(7, 0);    //creating min heap
    int i = 0;
    int temp[7] = {2, 5, 10, 8, 9, 11, 15};

    for (i = 0; i < 7; i++)
        insert_into_heap(h, temp[i]);

    cout << "Original heap: ";
    print_heap(h);

    delete_element(h, 0);
    cout << "After deleting 2: ";;
    print_heap(h);

    insert_element(h, 2);
    cout << "After inserting 2: ";;
    print_heap(h);

    int temp2[7] = {10, 8, 2, 5, 9, 15, 11};
    build_heap(h, temp2, 7);
    cout << "After building heap: ";
    print_heap(h);

    heap_sort(temp2, 7);


    return SUCCESS;
}

