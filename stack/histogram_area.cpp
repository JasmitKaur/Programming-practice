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
    int max_area = 0, curr_area = 0, top = -1;
    int a[7] = {3, 2, 5, 6, 1, 4, 4};
    vector<int> stk;

    for (i = 0; i <=7; i++) {
        if (!stk.empty()) {
            while (a[i] < a[stk.back()]) {

                top = pop_stack(&stk);
                cout << "top = " << top << endl;

                if (stk.empty()) {
                    curr_area = a[top] * i;
                    cout << "curr_area in if = " << curr_area << endl;
                    break;
                } else {
                    curr_area = a[top] * (i - get_top(&stk) - 1);
                    cout << "curr_area in else = " << curr_area << endl;
                }

                if (curr_area > max_area)
                    max_area = curr_area;
                cout << "max_area = " << max_area << endl;
            }
        }
        push_stack(&stk, i);
    }

    cout << "Max area = " << max_area << endl;
    return 0;
}

