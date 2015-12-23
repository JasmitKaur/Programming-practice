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
//#include <set>
#include "stack.h"
#include <stdlib.h>

using namespace std;

int main ()
{
    int i = 0;
    string str = "ababsXbadba";
    vector<char> stk;

    cout << str.at(i) << endl;

    while (str.at(i) != 'X') {
        push_stack(&stk, str.at(i));
        i++;
    }
    i++;

    cout << i << endl;

    while ((i < str.length()) && (pop_stack(&stk) == str.at(i)))
        i++;

    if ((i == str.length()) || stk.empty())
        cout << "Palindrom" << endl;
    else
        cout << "Nope" << endl;

    print_stack(&stk);

    return 0;
}

