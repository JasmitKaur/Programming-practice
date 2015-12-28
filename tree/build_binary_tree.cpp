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

int search_index(int *in_order, int val, int in_s_index, int in_e_index)
{
    int i = 0;
    for (i = in_s_index; i <= in_e_index; i++) {
        if (in_order[i] == val)
            return i;
    }
    return FAILURE;
}

node *build_binary_tree(int *in_order, int *pre_order, int in_s_index, int in_e_index, int *pre_index)
{
    if (!pre_order[*pre_index])
        return NULL;

    int in_index = search_index(in_order, pre_order[*pre_index], in_s_index, in_e_index);
    if (in_index != FAILURE) {
        node *new_node = create_node(pre_order[*pre_index]);
        *pre_index += 1;
        new_node->left = build_binary_tree(in_order, pre_order, in_s_index, in_index - 1, pre_index);
        new_node->right = build_binary_tree(in_order, pre_order, in_index + 1, in_e_index, pre_index);
        return new_node;
    } else
        return NULL;
}

int main ()
{
    int in_order[6] = {4,2,5,1,6,3};
    int pre_order[6] = {1,2,4,5,3,6};
    int pre_index = 0;

    node *root = build_binary_tree(in_order, pre_order, 0, 5, &pre_index);
    cout << "Build binary tree is: ";
    print_tree(root);
    return SUCCESS;
}

