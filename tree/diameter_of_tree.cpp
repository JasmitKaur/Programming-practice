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

int height_of_tree(node *root)
{
    if (!root)
        return 0;

    if (!root->left && !root->right)
        return 1;

    return max(height_of_tree(root->left) + 1, height_of_tree(root->right) + 1);
}

int diameter_of_tree(node *root)
{
    if (!root)
        return 0;

    if (!root->left && !root->right)
        return 1;

    int a = diameter_of_tree(root->left);
    int b = diameter_of_tree(root->right);
    int c = height_of_tree(root->left) + 1 + height_of_tree(root->right);

    int max_d = 0;
    if (a > max_d)
        max_d = a;
    if (b > max_d)
        max_d = b;
    if (c > max_d)
        max_d = c;
    return max_d;
}

int main ()
{
    node *root = create_node(1);
    for (int i = 2; i < 11; i++)
        insert_node(root, create_node(i));

    print_tree(root);

    cout << "Diameter(recursive): " << diameter_of_tree(root) << endl;

    return SUCCESS;
}

/*

int diameter_of_tree(node *root, int *height)
{
    if (!root) {
        *height = 0;
        return 0;
    }

    int lh = 0;
    int rh = 0;
    int dia_l = diameter_of_tree(root->left, &lh);
    int dia_r = diameter_of_tree(root->right, &rh);

    *height = 1 + max(lh, rh);

    return max(lh + rh + 1, max(dia_l, dia_r));
}

int main ()
{
    node *root = create_node(1);
    for (int i = 2; i < 11; i++)
        insert_node(root, create_node(i));

    print_tree(root);

    int h = 0;
    cout << "Diameter(recursive): " << diameter_of_tree(root, &h) << endl;

    return SUCCESS;
}

*/
