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
    for (int i = 0; i < n; i++)
        cout << a[i] << " ";
    cout << endl;
}

int can_place(int *queens, int x, int y)
{
    int i;
    for (i = 0; i < x; ++i) {
        if (queens[i] == y)
            return 0;
        else if (abs(i - x) == abs(queens[i] - y))
            return 0;
    }
    return 1;
}

int place_queens(int *queens, int s, int n)
{
    int i;
    for (i = 1; i < n; ++i) {
        if (can_place(queens, s, i)) {
            queens[s] = i;
            if (s == n - 1) {
                print_array(queens, n);
            }
            place_queens(queens, s+1, n);
        }
    }
    return 1;
}

int main ()
{
    int queens[5];
    int i;

    for (i = 0; i < 5; ++i)
        queens[i] = 0;

    cout << "N- queens: " << place_queens(queens, 1, 5) << endl;
    // time complexity: n! ie n * (n-1) * (n-2) * ...
    return 0;
}

