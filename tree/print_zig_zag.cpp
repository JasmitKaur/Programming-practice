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

void swap_ptrs(vector<node *> **ptr1, vector<node *> **ptr2)
{
    vector<node *> *temp = *ptr1;
    *ptr1 = *ptr2;
    *ptr2 = temp;
}

void print_zig_zag(node *root)
{
    if (!root)
        return;

    vector<node *> *current = new vector<node *>;
    vector<node *> *next = new vector<node *>;
    int left_to_right = 1;

    current->push_back(root);
    while (!current->empty()) {
        node *temp = current->back();
        current->pop_back();

        cout << temp->data << " ";

        if (left_to_right) {
            if (temp->left)
                next->push_back(temp->left);
            if (temp->right)
                next->push_back(temp->right);
        } else {
            if (temp->right)
                next->push_back(temp->right);
            if (temp->left)
                next->push_back(temp->left);
        }

        if (current->empty()) {
            left_to_right = 1 - left_to_right;
            swap_ptrs(&current, &next);
        }
    }

}

int main ()
{
    node *root = create_node(1);
    for (int i = 2; i < 11; i++)
        insert_node(root, create_node(i));

    cout << "Original tree is: ";
    print_tree(root);

    cout << "Zig zag printing: ";
    print_zig_zag(root);

    return SUCCESS;
}

