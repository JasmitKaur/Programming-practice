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

void print_2d_array(int **a, int m, int n)
{
    int i = 0, j = 0;
    for (i = 0; i < m; i++) {
        for (j = 0; j < n; j++) {
            cout << a[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

int search_in_2d_array(int **a, int r_s, int r_e, int c_s, int c_e, int *r, int *c, int data)
{
    if (!a || r_s > r_e || c_s > c_e)
        return 0;

    int i = r_e, j = c_s;
    if (a[i][j] == data) {
        *r = i;
        *c = j;
        return 1;
    } else if (a[i][j] < data) {
        j++;
        return search_in_2d_array(a, r_s, i, j, c_e, r, c, data);
    } else if (a[i][j] > data) {
        i--;
        return search_in_2d_array(a, r_s, i, j, c_e, r, c, data);
    }
    return 0;
}

int main ()
{
    int b[5][5] = { {2, 6, 8, 16, 19},
                    {4, 9, 12, 22, 24},
                    {7, 10, 14, 25, 26},
                    {15, 17, 21, 28, 29},
                    {18, 20, 23, 30, 32}};
    int **a;
    int i, j;
    int m = 5, n = 5;

    a = new int *[m];
    for (int i = 0; i < m; i++)
        a[i] = new int[n];

    for (i = 0; i < m; i++) {
        for (j = 0; j < n; j++) {
            a[i][j] = b[i][j];
        }
    }

    cout << "Original 2D array:\n";
    print_2d_array(a, 5, 5);

    int data, is_present;
    i = 0;
    j = 0;
    cout << "Enter an element to be searched: ";
    cin >> data;
    is_present = search_in_2d_array(a, 0, m-1, 0, n-1, &i, &j, data);
    if (is_present)
        cout << "Yes. i= " << i << " j= " << j << endl;
    else
        cout << "No\n";

    return 0;
}

