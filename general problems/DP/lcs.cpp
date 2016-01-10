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

int **LCS;

int length_of_LCS(char *X, int m, char *Y, int n)
{
    int i, j;

    LCS = new int*[m+1];
    for (i = 0; i < m+1; ++i)
        LCS[i] = new int[n+1];

    for (i = 0; i < m+1; ++i)
        LCS[i][0] = 0;

    for (j = 0; j < n+1; ++j)
        LCS[0][j] = 0;


    for (i = 1; i < m+1; ++i) {
        for (j = 1; j < n+1; ++j) {
            if (X[i-1] == Y[j-1])
                LCS[i][j] = 1 + LCS[i-1][j-1];
            else
                LCS[i][j] = max(LCS[i-1][j], LCS[i][j-1]);
        }
    }
    return LCS[m][n];
}

void print_LCS(char *X, int m, int n)
{
    int i = 0, j = 0;

    while (i < m && j < n) {
        if (LCS[i+1][j+1] == 1 + LCS[i][j]) {
            cout << X[i-1];
            ++i;
            ++j;
        } else if (LCS[i+1][j+1] == LCS[i+1][j]) {
            ++i;
        } else if (LCS[i+1][j+1] == LCS[i][j+1]) {
            ++j;
        }
    }
    /*for (i = 0; i < m+1; ++i) {
        for (j = 0; j < n+1; ++j) {
            cout << LCS[i][j] << " ";
        }
        cout << endl;
    }*/
}

int main ()
{
    char X[7] = {'A', 'B', 'C', 'B', 'D', 'A', 'B'};
    char Y[6] = {'B', 'D', 'C', 'A', 'B', 'A'};

    int len = 0;
    len = length_of_LCS(X, 7, Y, 6);
    cout << "length of LCS: " << len << endl;
    print_LCS(X, 7, 6);

    return 0;
}

