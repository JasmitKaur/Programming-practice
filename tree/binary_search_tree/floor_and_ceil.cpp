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

int find_floor(node *root, int k, int *prev)
{
    if (!root)
        return -1;

    int left = find_floor(root->left, k, prev);
    if (left != -1)
        return left;

    if (root->data == k)
        return root->data;

    if (root->data > k)
        return *prev;

    *prev = root->data;
    return find_floor(root->right, k, prev);
}

int find_ceil(node *root, int k, int *prev)
{
    if (!root)
        return -1;

    int left = find_ceil(root->left, k, prev);
    if (left != -1)
        return left;

    if (root->data == k)
        return root->data;

    if (*prev < k && root->data > k)
        return root->data;

    *prev = root->data;
    return find_ceil(root->right, k, prev);
}

//problem: find floor & ceil of an element in BST
int main ()
{
    int a[7] = {9, 7, 15, 2, 8, 10, 20};

    node *root = create_node(a[0]);
    for (int i = 1; i < 7; i++)
        insert_node(root, create_node(a[i]));
    print_tree(root);

    int k;
    cout << "Enter k: ";
    cin >> k;

    int prev = 0;
    cout << "floor of " << k << " is: " << find_floor(root, k, &prev) << endl;

    prev = 0;
    cout << "Ceil of " << k << " is: " << find_ceil(root, k, &prev) << endl;

    return 0;
}

