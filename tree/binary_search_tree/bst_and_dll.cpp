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

bst_node *bst_to_DLL(bst_node *root)
{
    if (!root)
        return NULL;

    if (!root->left && !root->right)
        return root;

    bst_node *lhead, *rhead;
    lhead = bst_to_DLL(root->left);
    rhead = bst_to_DLL(root->right);

    if (lhead) {
        bst_node *temp = lhead;
        while (temp && temp->right)
            temp = temp->right;
        root->left = temp;
        temp->right = root;
    }
    if (rhead) {
        root->right = rhead;
        rhead->left = root;
    }
    return lhead;
}

void print_DLL(bst_node *head)
{
    if (!head)
        return;
    while (head) {
        cout << head->data << " ";
        head = head->right;
    }
    cout << endl;
}

bst_node *find_middle(bst_node *lptr)
{
    if (!lptr)
        return NULL;

    bst_node *fast = lptr;
    bst_node *slow = lptr;

    while (fast && fast->right && slow) {
        fast = fast->right->right;
        slow = slow->right;
    }
    return slow;
}

bst_node *DLL_to_bst(bst_node *lptr)
{
    if (!lptr)
        return NULL;

    if (!lptr->left && !lptr->right)
        return lptr;

    bst_node *temp = find_middle(lptr);
    if (temp->left)
        temp->left->right = NULL;
    if (temp->right)
        temp->right->left = NULL;

    temp->left = DLL_to_bst(lptr);
    temp->right = DLL_to_bst(temp->right);
    return temp;
}

int main ()
{
    int a[7] = {6, 4, 10, 2, 8, 11, 5};
    //int a[7] = {6, 7, 8, 9, 10, 11, 12};
    int i = 0;

    bst_node *root = bst_create_node(6);
    for (i = 1; i < 7; i++)
        bst_insert_a_node(root, a[i]);

    cout << "Original tree is: ";
    bst_print_tree(root);

    cout << "DLL traversal: ";
    bst_node *lptr = bst_to_DLL(root);
    print_DLL(lptr);

    cout << "New tree: ";
    bst_node *new_root = DLL_to_bst(lptr);
    bst_print_tree(new_root);
    return SUCCESS;
}

