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
#include "tree_queue.h"

using namespace std;

int max_level_sum(node *root, int *level)
{
    if (!root) {
        *level = 0;
        return 0;
    }

    int max_sum = 0;
    int level_sum = 0;
    int l = -1;
    my_queue *que = create_queue(MAX_LEN);
    enqueue(que, root);

    //create separator node
    node *sep = create_node(-1);
    enqueue(que, sep);

    while (!is_empty(que)) {
        node *temp = dequeue(que);

        if (temp->data == -1) {
            l++;
            if (level_sum > max_sum) {
                max_sum = level_sum;
                *level = l;
            }
            level_sum = 0;

            if (!is_empty(que))
                enqueue(que, sep);
        } else {
            level_sum += temp->data;

            if (temp->left)
                enqueue(que, temp->left);

            if (temp->right)
                enqueue(que, temp->right);
        }
    }
    return max_sum;
}

int main ()
{
    node *root = create_node(1);
    for (int i = 2; i < 11; i++)
        insert_node(root, create_node(i));

    print_tree(root);

    int l = 0;
    cout << "Max level sum: " << max_level_sum(root, &l);
    cout << " for level: " << l << endl;

    return SUCCESS;
}

