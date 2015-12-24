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

void find_common_start(node **head1, node **head2)
{
    vector<int> stack1;
    vector<int> stack2;

    node *temp = NULL;

    /* Initialize stack1 */
    temp = *head1;
    while (temp) {
        stack1.push_back(temp->data);
        temp = temp->next;
    }

    /* Initialize stack2 */
    temp = *head2;
    while (temp) {
        stack2.push_back(temp->data);
        temp = temp->next;
    }

    /* print stack1 */
    cout << "Printing stack 1 \n";
    for (vector<int>::iterator it = stack1.begin(); it != stack1.end(); it++)
        cout << *it << " ";
    cout << endl;

    /* print stack2 */
    cout << "Printing stack 2 \n";
    for (vector<int>::iterator it = stack2.begin(); it != stack2.end(); it++)
        cout << *it << " ";
    cout << endl;

    int common_node_data = -1;
    while (stack1.back() == stack2.back()) {
        common_node_data = stack1.back();
        stack1.pop_back();
        stack2.pop_back();
    }

    if (common_node_data != -1)
        cout << "common_node_data = " << common_node_data << endl;
    else
        cout << "common point does not exists" << endl;
}

int main ()
{
    node *head1 = create_list();
    node *head2 = create_list();
    int i = 0;

    for (i = 1; i < 3; i++)
        insert_add_node_at_last(&head1, create_node(i));

    for (i = 3; i < 6; i++)
        insert_add_node_at_last(&head2, create_node(i));

    node *common_start = create_node(6);
    node *last1 = get_last_node(head1);
    node *last2 = get_last_node(head2);

    last1->next = common_start;
    last2->next = common_start;

    common_start->next = create_node(7);

    /* Created linked list as shown below:
            1 -> 2
                  \
                    6 -> 7
                  /
       3 -> 4 -> 5
    */

    cout << "complete list1\n";
    print_list(head1);

    cout << "complete list2\n";
    print_list(head2);

    find_common_start(&head1, &head2);

    return SUCCESS;
}

