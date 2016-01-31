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

// Checking if during inorder traversal prev value is less than root value
// if yes, then BST. else not BST
int isBST_inorder(node *root, int *prev)
{
    if (!root)
        return 1;

    int left = isBST_inorder(root->left, prev);
    if (left && root->data > *prev) {
        *prev = root->data;
        return isBST_inorder(root->right, prev);
    } else
        return 0;
}

// Checking if value of root is between min and max
int isBST(node *root, int min, int max)
{
    if (!root)
        return 1;

    return (root->data >= min && root->data < max && isBST(root->left, min, root->data) && isBST(root->right, root->data + 1, max));
}

//problem: check if tree is BST
int main ()
{
    int a[7] = {9, 7, 15, 2, 8, 10, 2};

    node *root = create_node(a[0]);
    for (int i = 1; i < 7; i++)
        insert_node(root, create_node(a[i]));
    print_tree(root);

    cout << "isBST: " << isBST(root, INT_MIN, INT_MAX) << endl;

    int prev = INT_MIN;
    cout << "isBST_inorder: " << isBST_inorder(root, &prev) << endl;

    return 0;
}

