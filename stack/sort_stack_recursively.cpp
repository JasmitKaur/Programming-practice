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

void sorted_push_recursively(vector<int> *v, int data)
{
    if (v->empty() || data > v->back()) {
        v->push_back(data);
        return;
    }

    int temp = v->back();
    v->pop_back();
    sorted_push_recursively(v, data);
    v->push_back(temp);
}

void sort_stack_recursively(vector<int> *v)
{
    if (!v->empty()) {
        int data = v->back();
        v->pop_back();
        sort_stack_recursively(v);
        sorted_push_recursively(v, data);
    }
}

void print_vector(vector<int> v)
{
    vector<int>::iterator it;
    for (it = v.begin(); it < v.end(); ++it)
        cout << *it << " ";
    cout << endl;
}

//problem: sort stack recursively
int main ()
{
    vector<int> v;
    v.push_back(-3);
    v.push_back(14);
    v.push_back(18);
    v.push_back(5);
    v.push_back(-30);

    cout << "Input stack: ";
    print_vector(v);

    sort_stack_recursively(&v);

    cout << "Output stack: ";
    print_vector(v);

    return 0;
}

