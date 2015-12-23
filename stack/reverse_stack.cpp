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
#include "stack.h"
#include <stdlib.h>

using namespace std;

void insert_at_bottom(vector<char> *s, char data)
{
    if (s->empty()) {
        //this is bottom
        push_stack(s, data);
        return;
    }
    char temp = pop_stack(s);
    insert_at_bottom(s, data);
    push_stack(s, temp);
}

void reverse_stack(vector<char> *s)
{
    if (s->empty())
        return;

    char temp = pop_stack(s);
    reverse_stack(s);
    insert_at_bottom(s, temp);
}

int main ()
{
    int i = 0;
    char a[5] = {'a', 'b', 'c', 'd', 'e'};
    vector<char> stk;

    stk.assign(a, a+5);

    reverse_stack(&stk);

    print_stack(&stk);

    return 0;
}

