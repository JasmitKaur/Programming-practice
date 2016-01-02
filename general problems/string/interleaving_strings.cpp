
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

void interleaving_strings(char *str1, int m, char *str2, int n, char *res, int r)
{
    if (m == 0 && n == 0) {
        print_array(res, r);
        return;
    }

    if (m != 0) {
        res[r] = str1[0];
        interleaving_strings(str1 + 1, m - 1, str2, n, res, r + 1);
    }

    if (n != 0) {
        res[r] = str2[0];
        interleaving_strings(str1, m, str2 + 1, n - 1, res, r + 1);
    }
}

int main ()
{
    char str1[2] = {'a', 'b'};
    char str2[2] = {'c', 'd'};

    cout << "Given arrays:\nstr1: ";
    print_array(str1, 2);
    cout << "str2: ";
    print_array(str2, 2);

    int len = 4;
    char *res = new char[len];
    interleaving_strings(str1, 2, str2, 2, res, 0);

    return 0;
}
