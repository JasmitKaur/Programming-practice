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

int height_of_tree_recursive(node *root)
{
    if (!root)
        return 0;

    if (!root->left && !root->right)
        return 0;

    return max(height_of_tree_recursive(root->left) + 1, height_of_tree_recursive(root->right) + 1);
}

int height_of_tree_iterative(node *root)
{
    if (!root) {
        cout << "Invalid root\n";
        return 0;
    }

    int height = -1;
    my_queue *que = create_queue(MAX_LEN);

    //create separator node
    node *sep = create_node(-1);
    enqueue(que, root);
    enqueue(que, sep);

    while (!is_empty(que)) {
        node *temp = dequeue(que);

        if (temp->data == -1) {
            height++;
            if (!is_empty(que))
                enqueue(que, sep);
        } else {
            if (temp->left)
                enqueue(que, temp->left);

            if (temp->right)
                enqueue(que, temp->right);
        }
    }
    return height;
}

int main ()
{
    node *root = create_node(1);
    for (int i = 2; i < 8; i++)
        insert_node(root, create_node(i));

    print_tree(root);

    cout << "Height(iterative): " << height_of_tree_iterative(root) << endl;
    cout << "Height(recursive): " << height_of_tree_recursive(root) << endl;

    return SUCCESS;
}
