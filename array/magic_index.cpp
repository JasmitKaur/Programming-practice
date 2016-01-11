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

int magic_index(int *a, int s, int e)
{
    if ((s == e) && (a[s] == s))
        return s;

    int mid = s + ((e-s)/2);
    if (a[mid] == mid)
        return mid;
    else if (a[mid] < mid)
        return magic_index(a, mid+1, e);
    else
        return magic_index(a, s, mid-1);
}

int main ()
{
    int a[6] = {-1, 0, 1, 2, 4, 10};
    cout << "Magic index is: " << magic_index(a, 0, 5) << endl;

    return 0;
}

