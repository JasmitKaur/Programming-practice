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

void print_all_ancestors_of(node *root, vector<int> path, int n)
{
    if (!root)
        return;

    if (root->data == n) {
        //path.push_back(root->data);
        vector<int>::iterator it;
        for (it = path.begin(); it < path.end(); it++)
            cout << *it << " ";
        cout << endl;
        return;
    }

    path.push_back(root->data);
    if (root->left) {
        print_all_ancestors_of(root->left, path, n);
    }
    if (root->right) {
        print_all_ancestors_of(root->right, path, n);
    }
}

int main ()
{
    node *root = create_node(1);
    for (int i = 2; i < 11; i++)
        insert_node(root, create_node(i));

    print_tree(root);

    vector<int> path;
    print_all_ancestors_of(root, path, 10);

    return SUCCESS;
}

