#include "math.h"
#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <climits>
#include <deque>
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
#include "queue.h"

using namespace std;

int find_max(my_queue *que, int w, int i)
{
    if (!que || w <= 0) {
        cout << "Invalid pointer to queue\n";
        return FAILURE;
    } else if ((i + w) > que->capacity) {
        cout << "Overflow\n";
        return FAILURE;
    }

    vector<int>::iterator it;
    int g_max = *(que->q.begin() + i);

    for (it = (que->q.begin() + i); it < (que->q.begin() + i + w); it++) {
        if (*it > g_max)
            g_max = *it;
    }
    return g_max;
}

int find_max_array(my_queue *que, int w)
{
    if (!que || w <= 0) {
        cout << "Invalid pointer to queue\n";
        return FAILURE;
    }

    int s = que->capacity - w + 1;
    int *m = new int[s];
    int i = 0;

    for (i = 0; i < s; i++) {
        m[i] = find_max(que, w, i);
        cout << m[i] << " ";
    }
    cout << endl;

    return SUCCESS;
}

int main ()
{
    my_queue *Q = create_queue(8);
    int i = 0;
    int a[8] = {1, 3, -1, -3, 5, 3, 6, 7};

    for (i = 0; i < 8; i++) {
        enqueue(Q, a[i]);
    }

    cout << "printing queue: ";
    print_queue(Q);

    int w;
    cout << "Enter window size: ";
    cin >> w;

    find_max_array(Q, w);

    return SUCCESS;
}
