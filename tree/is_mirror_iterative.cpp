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

int is_struct_same(node *root1, node *root2)
{
    my_queue *q1 = create_queue(10);
    my_queue *q2 = create_queue(10);
    node *t1, *t2;

    if (root1 && root2) {
        enqueue(q1, root1);
        enqueue(q2, root2);

        while (!is_empty(q1) && !is_empty(q2)) {
            t1 = dequeue(q1);
            t2 = dequeue(q2);

            if (t1->data == t2->data) {
                if (t1->left && t2->left) {
                    enqueue(q1, t1->left);
                    enqueue(q2, t2->left);
                } else if (t1->left || t2->left)
                    return 0;
                if (t1->right && t2->right) {
                    enqueue(q1, t1->right);
                    enqueue(q2, t2->right);
                } else if (t1->right || t2->right)
                    return 0;
            } else
                return 0;
        }
        if (is_empty(q1) && is_empty(q2))
            return 1;
        else
            return 0;
    } else if (!root1 && !root2) {
        return 1;   //both trees are empty
    } else {
        return 0;   //not same
    }
}

int is_mirror(node *root1, node *root2)
{
    my_queue *q1 = create_queue(10);
    my_queue *q2 = create_queue(10);
    node *t1, *t2;

    if (root1 && root2) {
        enqueue(q1, root1);
        enqueue(q2, root2);

        while (!is_empty(q1) && !is_empty(q2)) {
            t1 = dequeue(q1);
            t2 = dequeue(q2);

            if (t1->data == t2->data) {
                if (t1->left && t2->right) {
                    enqueue(q1, t1->left);
                    enqueue(q2, t2->right);
                } else if (t1->left || t2->right)
                    return 0;
                if (t1->right && t2->left) {
                    enqueue(q1, t1->right);
                    enqueue(q2, t2->left);
                } else if (t1->right || t2->left)
                    return 0;
            } else
                return 0;
        }
        if (is_empty(q1) && is_empty(q2))
            return 1;
        else
            return 0;
    } else if (!root1 && !root2) {
        return 1;   //both trees are empty
    } else {
        return 0;   //not same
    }
}

//problem: check if trees are have same structure (iteratively)
int main ()
{
    node *root1 = create_node(1);
    for (int i = 2; i < 8; i++)
        insert_node(root1, create_node(i));
    print_tree(root1);

    node *root2 = create_node(1);
    node *temp;
    temp = create_node(3);
    root2->left = temp;
    temp = create_node(2);
    root2->right = temp;
    temp = create_node(7);
    root2->left->left = temp;
    temp = create_node(6);
    root2->left->right = temp;
    temp = create_node(5);
    root2->right->left = temp;
    temp = create_node(4);
    root2->right->right = temp;
    print_tree(root2);

    cout << "Is structure similar: " << is_struct_same(root1, root2) << endl;
    cout << "Is mirror: " << is_mirror(root1, root2) << endl;

    return 0;
}

