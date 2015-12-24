
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

void find_start_of_circle(node **head)
{
    if (!*head)
        return;

    node *fast = *head;
    node *slow = *head;

    do {
        fast = fast->next->next;
        slow = slow->next;
    } while (fast && fast->next && slow && fast != slow);

    if (fast == slow) {
        fast = *head;
        while (fast != slow) {
            fast = fast->next;
            slow = slow->next;
        }
        cout << "Start of circle: " << fast->data << endl;
    }
}

int does_loop_exist(node **head)
{
    if (!*head)
        return FAILURE;

    node *fast = *head;
    node *slow = *head;

    do {
        fast = fast->next->next;
        slow = slow->next;
    } while (fast && fast->next && slow && fast != slow);

    if (fast == slow) {
        cout << "Loop exists\n";
        return 1;
    } else {
        cout << "Loop does not exist\n";
        return 0;
    }
}

node *find_middle_node(node **head)
{
    if (!*head)
        return NULL;

    node *fast = *head;
    node *slow = *head;

    while (fast && fast->next) {
        fast = fast->next->next;
        slow = slow->next;
    }

    return slow;
}

int main ()
{
    node *head = create_list();
    int i = 0;

    for (i = 1; i < 8; i++)
        insert_add_node_at_last(&head, create_node(i));

    node *middle = find_middle_node(&head);

    //add 2 more nodes
    insert_add_node_at_last(&head, create_node(8));
    insert_add_node_at_last(&head, create_node(9));

    cout << "complete list\n";
    print_list(head);

    // join last & previously found middle node
    // this is for practice of loop problems
    node *temp = head;
    while (temp && temp->next)
        temp = temp->next;
    temp->next = middle;

    int loop_exists = does_loop_exist(&head);
    if (loop_exists) {
        find_start_of_circle(&head);
    }

    return SUCCESS;
}
