
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
using namespace std;

// 0 - not unique
// 1 - unique
int is_unique(string s)
{
    static int a[128];
    int i = 0;

    if (s.length() > 128)
        return 0;

    for (i = 0; i < s.length(); i++) {
        if (a[s[i]] > 0)
            return 0;
        else
            a[s[i]]++;
    }
    return 1;
}

int is_unique_x_naive(string s)
{
    int i = 0;

    if (s.length() > 128)
        return 0;

    for (i = 0; i < s.length(); i++) {
        string::size_type x = s.find_last_of(s[i]);
        if (x != i)
            return 0;
    }
    return 1;
}

int is_unique_x_bit(string s)
{
    int i = 0;
    int check = 0;

    if (s.length() > 128)
        return 0;

    for (i = 0; i < s.length(); i++) {
        int val = s[i] - 'a';
        if ((check & (1 << val)) > 1)
            return 0;
        else
            check |= (1 << val);
    }
    return 1;
}

int main()
{
    string a = "jasmit";
    cout << "With additional data structure: " << is_unique(a) << endl;
    cout << "Without additional data structure: " << is_unique_x_naive(a) << endl;
    cout << "Without additional data structure, with bit manipulation: " << is_unique_x_bit(a) << endl;

    return 0;
}
