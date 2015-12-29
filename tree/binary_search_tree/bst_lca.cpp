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
#include "binary_search_tree.h"

using namespace std;

bst_node *bst_find_lca(bst_node *root, bst_node *node1, bst_node *node2)
{
    if (!root || !node1 || !node2)
        return NULL;

    if ((root->data == node1->data) || (root->data == node2->data) ||
        (root->data > node1->data && root->data < node2->data) ||
        (root->data < node1->data && root->data > node2->data))
        return root;
    else if (root->data > node1->data && root->left)
        return bst_find_lca(root->left, node1, node2);
    else
        return bst_find_lca(root->right, node1, node2);
}

int main ()
{
    //int a[7] = {6, 4, 10, 2, 8, 11, 5};
    int a[7] = {6, 7, 8, 9, 10, 11, 12};
    int i = 0;

    bst_node *root = bst_create_node(6);
    for (i = 1; i < 7; i++)
        bst_insert_a_node(root, a[i]);

    cout << "Original tree is: ";
    bst_print_tree(root);

    bst_node *parent = NULL;
    bst_node *node1 = bst_find_node(root, 12, &parent);
    bst_node *node2 = bst_find_node(root, 10, &parent);
    bst_node *lca = bst_find_lca(root, node1, node2);
    if (lca)
        cout << "LCA = " << lca->data;

    return SUCCESS;
}

