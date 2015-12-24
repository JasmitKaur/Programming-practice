
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

void find_middle_node(node **head)
{
    if (!*head)
        return;

    node *fast = *head;
    node *slow = *head;

    while (fast && fast->next) {
        fast = fast->next->next;
        slow = slow->next;
    }

    if (!fast)
        cout << "List is of even length" << endl;
    else
        cout << "List is of odd length" << endl;

    cout << "Middle value = " << slow->data << endl;
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

    find_middle_node(&head);

    return SUCCESS;
}
