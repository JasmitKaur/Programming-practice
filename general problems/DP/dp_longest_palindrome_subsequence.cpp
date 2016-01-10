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

#define MY_INT_MAX 100

int largest_palindrome_sequence_recursive(char *a, int s, int e)
{
    if (s == e)
        return 1;

    if (s + 1 == e && a[s] == a[e])
        return 2;

    if (a[s] == a[e])
        return 2 + largest_palindrome_sequence_recursive(a, s+1, e-1);

    return max(largest_palindrome_sequence_recursive(a, s+1, e), largest_palindrome_sequence_recursive(a, s, e-1));
}

int largest_palindrome_sequence_dp(char *a, int n)
{
    int M[n][n];
    int i, j, len;

    for (i = 0; i < n; ++i) {
        M[i][i] = 1;

        if (i < n-1) {
            if (a[i] == a[i+1]) {
                M[i][i+1] = 2;
            } else
                M[i][i+1] = 1;
        }
    }

    for (len = 3; len <= n; ++len) {
        for (i = 0; i <= n-len+1; ++i) {
            j = i + len - 1;
            if (a[i] == a[j]) {
                M[i][j] = 2 + M[i+1][j-1];
            } else {
                M[i][j] = max(M[i][j-1], M[i+1][j]);
            }
        }
    }

    /*for (int p = 0; p < n; ++p) {
        for (int q = 0; q < n; ++q) {
            cout << M[p][q] << " ";
        }
        cout << endl;
    }*/

    return M[0][n-1];
}

int main ()
{
    char a[15] = {'A', 'G', 'C', 'T', 'C', 'B', 'M', 'A', 'A', 'C', 'T', 'G', 'G', 'A', 'M'};
    //char a[4] = {'c', 't', 'b', 'c'};

    cout << "Length of largest palindrome sequence(recursive): " << largest_palindrome_sequence_recursive(a, 0, 14) << endl;
    cout << "Length of largest palindrome sequence(dp): " << largest_palindrome_sequence_dp(a, 15) << endl;
    return 0;
}

