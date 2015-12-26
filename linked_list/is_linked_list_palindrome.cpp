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

node *get_middle(node *head)
{
    if (!head)
        return NULL;

    node *fast = head;
    node *slow = head;

    while (fast && fast->next) {
        fast = fast->next->next;
        slow = slow->next;
    }
    return slow;
}

int is_palindrome(node *head)
{
    if (!head)
        return 0;

    node *middle = get_middle(head);
    node *reversed = reverse_list_recursive(middle);
    node *temp1 = head;
    node *temp2 = reversed;

    while (temp1 && temp2 && temp1->data == temp2->data) {
        temp1 = temp1->next;
        temp2 = temp2->next;
    }

    if (!temp1 && !temp2)
        return 1;
    else if (!temp1->next && !temp2)
        return 1;
    else
        return 0;
}

int main ()
{
    node *head = create_list();
    int i = 0;
    int a[4] = {1, 2, 2, 1};

    for (i = 0; i < 4; i++)
        insert_add_node_at_last(&head, create_node(a[i]));

    cout << "complete list1\n";
    print_list(head);

    cout << "is palindrome?" << endl;
    if (is_palindrome(head))
        cout << "YES" << endl;
    else
        cout << "NO" << endl;

    return SUCCESS;
}

