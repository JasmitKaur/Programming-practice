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

node *find_kth_node(node *head, int k)
{
    if (!head)
        return NULL;

    node *temp = head;
    int counter = 0;
    while (temp && counter < k) {
        counter += 1;
        if (counter == k) {
            node *next = temp->next;
            temp->next = NULL;
            temp = next;
        } else
            temp = temp->next;
    }
    if (counter == k)
        return temp;
    else
        return head;
}

node *reverse_k_pairs(node *head, int k)
{
    if (!head)
        return NULL;
    else if (!head->next)
        return head;

    node *temp = head;

    node *next = find_kth_node(head, k);

    if (next == head)   //length of the list is < k
        return head;

    node *reversed = reverse_list_recursive(temp);

    node *rest = reverse_k_pairs(next, k);

    insert_add_node_at_last(&reversed, rest);

    return reversed;
}

int main ()
{
    node *head = create_list();
    int i = 0;
    int a[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    for (i = 0; i < 10; i++)
        insert_add_node_at_last(&head, create_node(a[i]));

    cout << "complete list1\n";
    print_list(head);

    int k = 0;
    cout << "Enter k for reversal: ";
    cin >> k;

    node *new_head = reverse_k_pairs(head, k);
    cout << "after reversal of " << k << " pairs \n";
    print_list(new_head);

    return SUCCESS;
}

