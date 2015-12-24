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

void reverse_pair_recursive(node **head)
{
    if (!*head || !(*head)->next)
        return;

    node *temp1 = *head;
    node *curr = NULL;

    *head = temp1->next;
    curr = (*head)->next;
    if (curr)
        temp1->next = curr->next;
    else
        temp1->next = curr;

    (*head)->next = temp1;

    reverse_pair_recursive(&curr);
}

void reverse_pair_iterative(node **head)
{
    if (!*head)
        return;

    node *temp1 = *head;
    node *temp2 = NULL;
    node *curr = NULL;

    *head = temp1->next;

    while (temp1 && temp1->next) {
        temp2 = temp1->next;
        curr = temp2->next;
        if (temp2->next)
            temp1->next = temp2->next->next;
        else
            temp1->next = temp2->next;
        temp2->next = temp1;

        temp1 = curr;
    }
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

    cout << "pair-wise reversed list\n";
    reverse_pair_iterative(&head);
    print_list(head);

    cout << "pair-wise reversed list (recursive) \n";
    reverse_pair_recursive(&head);
    print_list(head);

    return SUCCESS;
}

