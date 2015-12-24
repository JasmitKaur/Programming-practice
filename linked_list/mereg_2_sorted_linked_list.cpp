
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

node *remove_first(node **head)
{
    if (!*head)
        return NULL;

    node *temp = *head;
    *head = temp->next;
    temp->next = NULL;
    return temp;
}

void merge_list(node **head1, node **head2, node **head3)
{
    if (!*head1 && !*head2) {
        return;
    } else if (!*head1 && *head2) {
        insert_add_node_at_last(head3, *head2);
        return;
    } else if (*head1 && !*head2) {
        insert_add_node_at_last(head3, *head1);
        return;
    } else {
        if ((*head1)->data < (*head2)->data) {
            node *first = remove_first(head1);
            insert_add_node_at_last(head3, first);
        } else {
            node *first = remove_first(head2);
            insert_add_node_at_last(head3, first);
        }
        merge_list(head1, head2, head3);
    }
}

int main ()
{
    node *head1 = create_list();
    node *head2 = create_list();
    node *head3 = create_list();
    int i = 0;
    int a1[4] = {1, 3, 7, 8};
    int a2[3] = {2, 5, 6};

    for (i = 0; i < 4; i++)
        insert_add_node_at_last(&head1, create_node(a1[i]));

    for (i = 0; i < 3; i++)
        insert_add_node_at_last(&head2, create_node(a2[i]));

    cout << "complete list1\n";
    print_list(head1);

    cout << "complete list2\n";
    print_list(head2);

    cout << "merged list\n";
    merge_list(&head1, &head2, &head3);
    print_list(head3);

    return SUCCESS;
}
