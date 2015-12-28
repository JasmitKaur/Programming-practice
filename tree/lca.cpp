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

int LCA(node *root, int a, int b)
{
    if (!root)
        return 0;

    if (root->data == a || root->data == b)
        return root->data;

    int left_lca = LCA(root->left, a, b);
    int right_lca = LCA(root->right, a, b);

    if (left_lca && right_lca)
        return root->data;
    else if (left_lca)
        return left_lca;
    else if (right_lca)
        return right_lca;
    else
        return 0;
}

int main ()
{
    node *root = create_node(1);
    for (int i = 2; i < 11; i++)
        insert_node(root, create_node(i));

    print_tree(root);

    cout << "LCA: " << LCA(root, 7, 3) << endl;

    return SUCCESS;
}

