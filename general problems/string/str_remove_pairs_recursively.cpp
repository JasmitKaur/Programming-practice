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

void print_array(char *a, int n)
{
    for (int i = 0; i < n; i++)
        cout << a[i];
    cout << endl;
}

void remove_pair_recursively(char *a, int *n)
{
    if (!*a)
        return;

    int j = 0;
    int counter = 0;
    for (int i = 1; i < *n; ++i) {
        if (a[j] == a[i]) {
            --j;
            ++i;
            ++counter;
        }
        a[++j] = a[i];
    }
    *n -= (2 * counter);
    if (counter)
        remove_pair_recursively(a, n);
}

int main ()
{
    char a[9] = {'a', 'b', 'c', 'c', 'c', 'c', 'b', 'c', 'd'};

    cout << "Given array: ";
    print_array(a, 9);

    int n = 9;
    remove_pair_recursively(a, &n);
    cout << "After removing pairs: ";
    print_array(a, n);

    return 0;
}

