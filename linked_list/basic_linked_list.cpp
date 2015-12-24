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

using namespace std;

struct node {
    int data;
    struct node *next;
};

#define FAILURE -1;
#define SUCCESS 0

node *create_list()
{
    node *head = new node;
    head = NULL;
    cout << "List created\n";
    return head;
}

node *create_node(int val)
{
    node *new_node = new node;
    new_node->data = val;
    new_node->next = NULL;
    cout << "Node created\n";
    return new_node;
}

int delete_node(node *n)
{
    if (!n)
        return FAILURE;

    n->data = 0;
    n->next = NULL;
    delete n;
    return SUCCESS;
}

int insert_add_node_at_last(node **head, node *new_node)
{
    if (!new_node)
        return FAILURE;

    node *temp = *head;
    while (temp && temp->next)
        temp = temp->next;

    if (!temp) {
        *head = new_node;
    } else {
        temp->next = new_node;
    }

    return SUCCESS;
}

int insert_add_node_at_first(node **head, node *new_node)
{
    if (!*head || !new_node)
        return FAILURE;

    new_node->next = *head;
    *head = new_node;
    return SUCCESS;
}

int remove_last_node(node **head)
{
    if (!*head)
        return FAILURE;

    node *temp = *head;
    node *prev = NULL;

    while (temp->next) {
        prev = temp;
        temp = temp->next;
    }

    prev->next = NULL;
    delete_node(temp);
    return SUCCESS;
}

int remove_first_node(node **head)
{
    if (!*head)
        return FAILURE;

    node *temp = *head;
    node *prev = NULL;

    *head = temp->next;
    delete_node(temp);
    return SUCCESS;
}

int remove_this_node(node **head, int val)
{
    if (!*head)
        return FAILURE;

    node *temp = *head;
    node *prev = NULL;

    while (temp->next && temp->data != val) {
        cout << "inside while\n";
        prev = temp;
        temp = temp->next;
    }

    if (prev == NULL && temp->data == val) {   //first element to be deleted
        *head = temp->next;
    } else if (temp->data == val) {
        prev->next = temp->next;
    } else {
        cout << "Node not found\n";
        return FAILURE;
    }

    delete_node(temp);
    return SUCCESS;
}

void print_list(node *head)
{
    node *temp = head;
    while (temp) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main ()
{
    node *head = create_list();
    int i = 0;

    for (i = 1; i < 6; i++)
        insert_add_node_at_last(&head, create_node(i));

    insert_add_node_at_first(&head, create_node(6));

    cout << "complete list\n";
    print_list(head);

    remove_first_node(&head);
    cout << "after removing first node\n";
    print_list(head);

    remove_last_node(&head);
    cout << "after removing last node\n";
    print_list(head);

    remove_this_node(&head, 2);
    cout << "after removing this(val = 2) node\n";
    print_list(head);

    return SUCCESS;
}

