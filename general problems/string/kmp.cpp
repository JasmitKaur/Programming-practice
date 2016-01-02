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

void print_int_array(int *a, int n)
{
    int i = 0;
    for (i = 0; i < n; i++)
        cout << a[i] << " ";
    cout << endl;
}

void print_char_array(char *a, int n)
{
    int i = 0;
    for (i = 0; i < n; i++)
        cout << a[i] << " ";
    cout << endl;
}

int *get_prefix_function(char *P, int n)
{
    int *F = new int[n];
    int i = 1;
    int j = 0;
    F[0] = 0;

    while (i < n) {
        if (P[i] == P[j]) {
            F[i] = j + 1;
            ++i;
            ++j;
        } else if (j > 0) {
            j = F[j-1];
        } else {
            F[i] = 0;
            ++i;
        }
    }
    return F;
}

int find_match_via_kmp(char *T, int n, char *P, int m)
{
    int *F = get_prefix_function(P, 7);
    print_int_array(F, 7);

    int i = 0;
    int j = 0;

    while (i < n) {
        if (T[i] == P[j]) {
            if (j == m - 1)
                return i - j;
            else {
                ++i;
                ++j;
            }
        } else if (j > 0) {
            j = F[j - 1];
        } else
            ++i;
    }
    return -1;
}

int main ()
{
    char T[15] = {'b', 'a', 'c', 'b', 'a', 'b', 'a', 'b', 'a', 'b', 'a', 'c', 'a', 'c', 'a'};
    char P[7] = {'a', 'b', 'a', 'b', 'a', 'c', 'a'};

    cout << "T: ";
    print_char_array(T, 15);

    cout << "P: ";
    print_char_array(P, 7);

    cout << find_match_via_kmp(T, 17, P, 7) << endl;

    return 0;
}

