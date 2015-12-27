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
#include "tree_queue.h"

using namespace std;

int is_mirror(node *root1, node *root2)
{
    if (!root1 && !root2) {
        return 1;
    } else if (root1->data == root2->data &&
        is_mirror(root1->left, root2->right) &&
        is_mirror(root1->right, root2->left)) {
        return 1;
    } else {
        return 0;
    }
}

int main ()
{
    node *root = create_node(1);
    //for (int i = 2; i < 11; i++)
    //    insert_node(root, create_node(i));

    insert_node(root, create_node(2));
    insert_node(root, create_node(2));

    insert_node(root, create_node(3));
    insert_node(root, create_node(4));

    insert_node(root, create_node(4));
    insert_node(root, create_node(3));

    print_tree(root);

    cout << "IS mirror?: " << is_mirror(root->left, root->right) << endl;

    return SUCCESS;
}
