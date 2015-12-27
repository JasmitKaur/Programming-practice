
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

int find_max_value(node *root)
{
    if (!root) {
        cout << "Invalid root\n";
        return -1;
    }

    int g_max = 0;
    my_queue *que = create_queue(7);
    enqueue(que, root);

    while (!is_empty(que)) {
        node *temp = dequeue(que);

        if (temp->data > g_max)
            g_max = temp->data;

        if (temp->left)
            enqueue(que, temp->left);

        if (temp->right)
            enqueue(que, temp->right);
    }
    return g_max;
}

int main ()
{
    node *root = create_node(1);
    for (int i = 2; i < 8; i++)
        insert_node(root, create_node(i));

    print_tree(root);

    cout << "Max value: " << find_max_value(root) << endl;

    return SUCCESS;
}
