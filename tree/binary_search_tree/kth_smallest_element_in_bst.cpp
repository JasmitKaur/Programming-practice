
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

int kth_smallest_element(node *root, int k, int *count)
{
    if (!root)
        return -1;

    int left = kth_smallest_element(root->left, k, count);
    if (left != -1)
        return left;

    *count += 1;
    if (*count == k)
        return root->data;

    return kth_smallest_element(root->right, k, count);
}

//problem: kth smallest element in BST
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

    int count = 0;
    cout << "kth smallest element in BST: " << kth_smallest_element(root, k, &count) << endl;

    return 0;
}
