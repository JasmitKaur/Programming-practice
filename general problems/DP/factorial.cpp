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

int F[100];

int factorial(int n)
{
    F[0] = 1;
    if (n < 1)
        return F[0];

    if (F[n])
        return F[n];

    for (int i = 1; i <= n; ++i)
        F[i] = i * F[i-1];

    return F[n];
}

int main ()
{
    int n;
    cout << "Enter a number: ";
    cin >> n;

    cout << n << "th factorial: " << factorial(n) << endl;

    return 0;
}

