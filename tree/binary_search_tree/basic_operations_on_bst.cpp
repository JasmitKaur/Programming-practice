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

int main ()
{
    int a[7] = {6, 4, 10, 2, 8, 11, 5};
    int i = 0;

    bst_node *root = bst_create_node(6);
    for (i = 1; i < 7; i++)
        bst_insert_a_node(root, a[i]);

    /*bst_node *root = bst_create_node(10);
    for (i = 9; i > 4; i--)
        bst_insert_a_node(root, i);*/

    cout << "Original tree is: ";
    bst_print_tree(root);

    cout << "Max value: " << (bst_find_max(root))->data << endl;
    cout << "Min value: " << (bst_find_min(root))->data << endl;

    bst_node *parent = NULL;
    bst_node *temp = bst_find_node(root, 5, &parent);
    if (temp) {
        cout << "Found " << temp->data << "!" << endl;
        if (parent)
            cout << "parent of " << temp->data << " is: " << parent->data << endl;
    } else
        cout << "NOT Found!" << endl;

    cout << "Parent of 8: " << (bst_get_parent(root, temp))->data << endl;
    cout << "bst_first_left_ancestor of 8: " << (bst_first_left_ancestor(root, temp))->data << endl;
    cout << "bst_first_right_ancestor of 5: " << (bst_first_right_ancestor(root, temp))->data << endl;
    cout << "inorder predecessor of 8: " << (bst_find_inorder_predecessor(root, 8))->data << endl;
    cout << "inorder successor of 8: " << (bst_find_inorder_successor(root, 8))->data << endl;

    bst_node *new_root = bst_delete_a_node(root, 6);
    cout << "After deleting 6: ";
    bst_print_tree(new_root);

    return SUCCESS;
}

