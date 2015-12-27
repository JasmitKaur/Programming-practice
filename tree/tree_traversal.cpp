
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

void level_order_traversal(node *root)
{
    if (!root) {
        cout << "Invalid root\n";
        return;
    }

    my_queue *que = create_queue(7);
    enqueue(que, root);

    while (!is_empty(que)) {
        node *temp = dequeue(que);

        cout << temp->data << " ";

        if (temp->left)
            enqueue(que, temp->left);

        if (temp->right)
            enqueue(que, temp->right);
    }
}

void pre_order_recursive(node *root)
{
    if (!root)
        return;

    cout << root->data << " ";
    pre_order_recursive(root->left);
    pre_order_recursive(root->right);
}

void pre_order_iterative(node *root)
{
    if (!root)
        return;

    vector<node *> s;
    s.push_back(root);

    while (!s.empty()) {
        node *temp = s.back();
        s.pop_back();

        cout << temp->data << " ";
        if (temp->right)
            s.push_back(temp->right);
        if (temp->left)
            s.push_back(temp->left);
    }
    cout << endl;
}

void in_order_recursive(node *root)
{
    if (!root)
        return;

    in_order_recursive(root->left);
    cout << root->data << " ";
    in_order_recursive(root->right);
}

void in_order_iterative(node *root)
{
    if (!root)
        return;

    vector<node *> s;
    node *temp = root;

    while (1) {
        while (temp) {
            s.push_back(temp);
            temp = temp->left;
        }
        if (!s.empty()) {
            temp = s.back();
            s.pop_back();
            cout << temp->data << " ";

            temp = temp->right;
        } else {
            cout << endl;
            return;
        }
    }
}

void post_order_recursive(node *root)
{
    if (!root)
        return;

    post_order_recursive(root->left);
    post_order_recursive(root->right);
    cout << root->data << " ";
}

void post_order_iterative(node *root)
{
    if (!root)
        return;

    vector<node *> s;
    node *temp = root;

    while (1) {
        while (temp) {
            s.push_back(temp);
            temp = temp->left;
        }
        if (!s.empty()) {
            temp = s.back();
            if (!temp-> right) {
                s.pop_back();
                cout << temp->data << " ";

                if (temp == (s.back())->right) {
                    cout << (s.back())->data << " ";
                    s.pop_back();
                }
            }

            /*if (!s.empty()) {
                temp = s.back();
                if (temp->right)
                    temp = temp->right;
                else
                    temp = NULL;
            } else {
                cout << endl;
                return;
            }*/
            if (!s.empty())
                temp = (s.back())->right;
            else
                temp = NULL;

        } else {
            cout << endl;
            return;
        }
    }
}

int main ()
{
    node *root = create_node(1);
    for (int i = 2; i < 8; i++)
        insert_node(root, create_node(i));

    print_tree(root);

    cout << "Pre-order traversal(recursive): ";
    pre_order_recursive(root);
    cout << endl;
    cout << "Pre-order traversal(iterative): ";
    pre_order_iterative(root);

    cout << "In-order traversal(recursive): ";
    in_order_recursive(root);
    cout << endl;
    cout << "In-order traversal(iterative): ";
    in_order_iterative(root);

    cout << "Post-order traversal(recursive): ";
    post_order_recursive(root);
    cout << endl;
    //cout << "Post-order traversal(iterative): ";
    //post_order_iterative(root);

    return SUCCESS;
}
