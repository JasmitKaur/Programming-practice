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

int create_sum_list(node **head1, node **head2)
{
    if (!*head1 || !*head2)
        return FAILURE;

    node *temp1 = *head1;
    node *temp2 = *head2;
    node *head3 = create_list();

    int carry = 0;

    while (temp1 || temp2) {
        int val = 0;
        if (temp1) {
            val += temp1->data;
            temp1 = temp1->next;
        }
        if (temp2) {
            val += temp2->data;
            temp2 = temp2->next;
        }
        if (carry)
            val += carry;

        carry = val / 10;
        val = val % 10;
        insert_add_node_at_last(&head3, create_node(val));
    }

    cout << "Printing sum list \n";
    print_list(head3);
	
	return SUCCESS;
}

int main ()
{
    node *head1 = create_list();
    node *head2 = create_list();
    int i = 0;
    int a1[4] = {7, 8, 1, 3};
    int a2[3] = {2, 5, 6};

    for (i = 0; i < 4; i++)
        insert_add_node_at_last(&head1, create_node(a1[i]));

    for (i = 0; i < 3; i++)
        insert_add_node_at_last(&head2, create_node(a2[i]));

    cout << "complete list1\n";
    print_list(head1);

    cout << "complete list2\n";
    print_list(head2);

    create_sum_list(&head1, &head2);

    return SUCCESS;
}

