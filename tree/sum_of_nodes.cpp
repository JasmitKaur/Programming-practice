
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

int sum_of_nodes(node *root)
{
    if (!root)
        return 0;

    int sum = 0;
    my_queue *que = create_queue(MAX_LEN);
    enqueue(que, root);

    while (!is_empty(que)) {
        node *temp = dequeue(que);

        sum += temp->data;

        if (temp->left)
            enqueue(que, temp->left);

        if (temp->right)
            enqueue(que, temp->right);
    }
    return sum;
}

int main ()
{
    node *root = create_node(1);
    for (int i = 2; i < 11; i++)
        insert_node(root, create_node(i));

    print_tree(root);

    cout << "Sum of nodes: " << sum_of_nodes(root) << endl;

    return SUCCESS;
}
