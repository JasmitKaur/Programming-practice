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

using namespace std;

struct trie_node {
    char data;
    int is_EOS;
    trie_node *child[26];
};

void print_trie_tree(trie_node *root)
{
    if (!root) {
        cout << endl;
        return;
    } else {
        cout << root->data << " ";
        for (int i = 0; i < 26; ++i) {
            if (root->child[i])
                print_trie_tree(root->child[i]);
        }
    }
}

trie_node *create_trie()
{
    trie_node *new_node = new trie_node;
    new_node->data = 'R';
    new_node->is_EOS = 1;
    for (int i = 0; i < 26; ++i)
        new_node->child[i] = NULL;
    return new_node;
}

trie_node *insert_trie_node(trie_node *root, char *word)
{
    if (!word)
        return NULL;

    if (root && root->data == 'R') {
        root->child[*(word) - 97] = insert_trie_node(root->child[*(word) - 97], word);
    } else if (!root) {
        trie_node *new_node = new trie_node;
        new_node->data = *word;
        for (int i = 0; i < 26; ++i)
            new_node->child[i] = NULL;
        if (!*(word + 1)) {
            new_node->is_EOS = 1;
        } else {
            new_node->is_EOS = 0;
            new_node->child[*(word + 1) - 97] = insert_trie_node(new_node->child[*(word + 1) - 97], (word + 1));
        }
        return new_node;
    } else
        root->child[*(word + 1) - 97] = insert_trie_node(root->child[*(word + 1) - 97], (word + 1));
}

int search_in_trie(trie_node *root, char *word)
{
    if (!root || !*word)
        return 0;

    if (root && root->data == 'R')
        return search_in_trie(root->child[*word - 97], word);
    else if (root->data == *word && !*(word + 1) && root->is_EOS)
        return 1;
    else if (root->data == *word)
        return search_in_trie(root->child[*(word + 1) - 97], (word + 1));
    else
        return 0;
}

int main ()
{
    trie_node *root = create_trie();

    insert_trie_node(root, "jasmit");
    insert_trie_node(root, "kaur");

    print_trie_tree(root);

    int is_present = 0;
    is_present = search_in_trie(root, "kaur");
    if (is_present)
        cout << "Data exists" << endl;
    else
        cout << "Does not exists" << endl;

    return 0;
}

