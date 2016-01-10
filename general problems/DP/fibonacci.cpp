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

int fibonacci(int n)
{
    F[0] = 0;
    F[1] = 1;

    if (n > 0 && n < 3)
        return F[n-1];

    for (int i = 2; i < n; ++i) {
        F[i] = F[i-1] + F[i-2];
    }

    return F[n-1];
}

int fibonacci_without_memoization(int n)
{
    if (n == 1 || n == 2)
        return n-1;

    int a = 0, b = 1;
    int sum = 0;
    for (int i = 2; i < n; ++i) {
        sum = a + b;
        a = b;
        b = sum;
    }

    return sum;
}

int main ()
{
    int n;
    cout << "Enter a number: ";
    cin >> n;

    cout << n << "th term of Fibonacci series: " << fibonacci(n) << endl;
    cout << n << "th term of Fibonacci without memoization: " << fibonacci_without_memoization(n) << endl;

    return 0;
}
