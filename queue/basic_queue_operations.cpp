#include "math.h"
#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <climits>
#include <deque>
//#include <queue>
//#include <stack>
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

int main ()
{
    my_queue *Q = create_queue(5);
    int i = 0;

    for (i = 1; i < 6; i++) {
        enqueue(Q, i);
    }

    cout << "printing queue: ";
    print_queue(Q);

    cout << "dequeueing once : " << dequeue(Q) << endl;
    cout << "remaining queue: ";
    print_queue(Q);

    for (i = 1; i < 6; i++) {
        cout << "dequeueing : " << dequeue(Q) << endl;
    }
    cout << "remaining queue: ";
    print_queue(Q);

    return SUCCESS;
}

