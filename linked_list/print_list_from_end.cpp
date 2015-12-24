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

void print_list_from_end(node *head)
{
    if (!head)
        return;

    node *temp = head;
    print_list_from_end(temp->next);
    cout << temp->data << " ";
}

int main ()
{
    node *head = create_list();
    int i = 0;
    int a[4] = {7, 8, 1, 3};

    for (i = 0; i < 4; i++)
        insert_add_node_at_last(&head, create_node(a[i]));

    cout << "complete list\n";
    print_list(head);

    cout << "reverse list\n";
    print_list_from_end(head);

    return SUCCESS;
}

