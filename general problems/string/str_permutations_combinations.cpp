
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

void permutate_string(char *org, char *perm, int *used, int i_p, int n)
{
    if (!*org)
        return;

    if (i_p == n) {
        print_array(perm, n);
        return;
    }

    for (int i = 0; i < n; ++i) {
        if (!used[i]) {
            used[i] = 1;
            perm[i_p] = org[i];
            if (i_p < n)
                permutate_string(org, perm, used, i_p + 1, n);
            used[i] = 0;
        }
    }
}

void chars_combination(char *org, int start, int n, char *combi, int i_c)
{
    if (!org)
        return;

    for (int i = start; i < n; ++i) {
        combi[i_c] = org[i];
        print_array(combi, i_c+1);

        if (i < n)
            chars_combination(org, i + 1, n, combi, i_c + 1);
    }
}

int main ()
{
    char a[3] = {'a', 'b', 'c'};

    cout << "Given array: ";
    print_array(a, 3);

    char *perm = new char[3];
    int used[3] = {0,0,0};
    cout << "Printing permutations: \n";
    permutate_string(a, perm, used, 0, 3);

    char b[3] = {'a', 'b', 'c'};
    char *combi = new char[3];
    cout << "Printing combinations: \n";
    chars_combination(a, 0, 3, combi, 0);

    return 0;
}
