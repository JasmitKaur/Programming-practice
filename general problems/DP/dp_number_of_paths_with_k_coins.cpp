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

int a[3][3] = { {1, 2, 3},
                {4, 6, 5},
                {3, 2, 1}};

int is_valid(int index)
{
    if (index >= 0 && index < 3)
        return 1;
    else
        return 0;
}

int number_of_paths_recursive(int k, int i, int j, vector<int> *path)
{
    if (i == 0 && j == 0 && k == a[i][j]) {
        path->push_back(a[i][j]);
        vector<int>::iterator it;
        for (it = path->begin(); it < path->end(); it++)
            cout << *it << " ";
        cout << endl;
        path->pop_back();
        return 1;
    }

    if (i == 0 && j == 0 && k != a[i][j])
        return 0;

    int p1 = 0;
    int p2 = 0;
    if (is_valid(j-1)) {
        path->push_back(a[i][j]);
        p1 = number_of_paths_recursive(k-a[i][j], i, j-1, path);
        path->pop_back();
    }
    if (is_valid(i-1)) {
        path->push_back(a[i][j]);
        p2 = number_of_paths_recursive(k-a[i][j], i-1, j, path);
        path->pop_back();
    }
    return p1 + p2;
}

int paths[3][3][12] = {0, };
int number_of_paths_dp(int k, int i, int j)
{
    if (paths[i][j][k])
        return paths[i][j][k];

    if (i == 0 && j == 0 && k == a[i][j]) {
        paths[0][0][k] = 1;
        return paths[0][0][k];
    }

    if (i == 0 && j == 0 && k != a[i][j]) {
        paths[0][0][k] = 0;
        return 0;
    }

    if (is_valid(j-1)) {
        paths[i][j-1][k-a[i][j]] = number_of_paths_dp(k-a[i][j], i, j-1);
    }
    if (is_valid(i-1)) {
        paths[i-1][j][k-a[i][j]] = number_of_paths_dp(k-a[i][j], i-1, j);
    }
    paths[i][j][k] = paths[i][j-1][k-a[i][j]] + paths[i-1][j][k-a[i][j]];
    return  paths[i][j][k];
}


int main ()
{
    // Number of paths with exactly k coins
    vector<int> *path = new vector<int>;
    cout << "number of paths with sum 12: " << number_of_paths_recursive(12, 2, 2, path) << endl;
    cout << "number of paths using DP with sum 12: " << number_of_paths_dp(12, 2, 2) << endl;

    return 0;
}
