
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

#include "stack.h"

using namespace std;

vector<int> input;
vector<int> m;

int main ()
{
    int val;
    cout << "Enter 5 values: " << endl;
    for (int i = 0; i < 5; i++) {
        cin >> val;
        push_stack(&input, val);

        if (get_top(&m) > val)
            push_stack(&m, val);
        else
            push_stack(&m, get_top(&m));
    }
    print_stack(&input);
    print_stack(&m);

    cout << "min number is : " << get_top(&m) << endl;
    return 0;
}
