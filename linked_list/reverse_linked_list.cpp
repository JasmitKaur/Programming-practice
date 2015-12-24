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
#include "linked_list.h"

using namespace std;

node *reverse_list_recursive(node *head)
{
    if (!head->next)
        return head;

    node *temp = reverse_list_recursive(head->next);
    head->next = NULL;
    insert_add_node_at_last(&temp, head);
    return temp;
}

void reverse_list_iterative(node **head)
{
    if (!*head)
        return;

    node *temp = *head;
    node *prev = NULL;
    node *next = NULL;

    while (temp) {
        next = temp->next;
        temp->next = prev;
        prev = temp;
        temp = next;
    }
    *head = prev;
}

int main ()
{
    node *head = create_list();
    int i = 0;
    int a[4] = {1, 2, 3, 4};

    for (i = 0; i < 4; i++)
        insert_add_node_at_last(&head, create_node(a[i]));

    cout << "complete list1\n";
    print_list(head);

    cout << "reversed list iterative\n";
    reverse_list_iterative(&head);
    print_list(head);

    cout << "reversed list recursive\n";
    print_list(reverse_list_recursive(head));

    return SUCCESS;
}

