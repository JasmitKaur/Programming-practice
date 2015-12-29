#ifndef _BINARY_SEARCH_TREE_
#define _BINARY_SEARCH_TREE_

#include <iostream>
#include <vector>

struct bst_node {
    int data;
    bst_node *left;
    bst_node *right;
};

struct my_queue {
    int capacity;
    int front;
    int rear;
    std::vector<bst_node *> q;
};

#define FAILURE -1
#define SUCCESS 0
#define MAX_LEN 30

my_queue *create_queue(int cap)
{
    my_queue *que = new my_queue;
    que->capacity = cap;
    que->front = -1;
    que->rear = -1;
    return que;
}

int is_full(my_queue *que)
{
    if (!que) {
        std::cout << "Invalid pointer to queue\n";
        return FAILURE;
    }

    if (que->rear == que->capacity - 1)
        return 1;
    else
        return 0;
}

int is_empty(my_queue *que)
{
    if (!que) {
        std::cout << "Invalid pointer to queue\n";
        return FAILURE;
    }

    if (que->front == -1)
        return 1;
    else
        return 0;
}

int enqueue(my_queue *que, bst_node *n)
{
    if (!que || !n) {
        std::cout << "Invalid pointers\n";
        return FAILURE;
    }

    if (is_full(que) == 1) {
        std::cout << "Queue is full\n";
        return FAILURE;
    }

    que->rear++;
    que->q.push_back(n);

    if (que->front == -1)   //for first element
        que->front = que->rear;

    return SUCCESS;
}

bst_node *dequeue(my_queue *que)
{
    if (!que) {
        std::cout << "Invalid pointer to queue\n";
        return NULL;
    }

    if (is_empty(que) == 1) {
        std::cout << "Queue is empty\n";
        return NULL;
    }

    bst_node *n = que->q.front();
    que->q.erase(que->q.begin());

    if (que->front == que->rear) {  //last element is being deleted
        que->front = -1;
        que->rear = -1;
    } else
        que->front++;

    return n;
}

bst_node *bst_create_node(int val)
{
    bst_node *new_node = new bst_node;
    new_node->data = val;
    new_node->left = NULL;
    new_node->right = NULL;
    return new_node;
}

bst_node *bst_find_node(bst_node *root, int val, bst_node **parent)
{
    if (!root)
        return NULL;

    if (val == root->data) {
        return root;
    } else if (val > root->data) {
        *parent = root;
        return bst_find_node(root->right, val, parent);
    } else {
        *parent = root;
        return bst_find_node(root->left, val, parent);
    }
}

bst_node *bst_find_max(bst_node *root)
{
    if (!root)
        return NULL;

    if (!root->right)
        return root;
    else
        return bst_find_max(root->right);
}

bst_node *bst_find_min(bst_node *root)
{
    if (!root)
        return NULL;

    if (!root->left)
        return root;
    else
        return bst_find_min(root->left);
}

bst_node *bst_get_parent(bst_node *root, bst_node *n)
{
    if (!root || !n)
        return NULL;

    if (root == n)
        return NULL;

    if (root->left == n || root->right == n)
        return root;
    else if (n->data > root->data)
        return bst_get_parent(root->right, n);
    else
        return bst_get_parent(root->left, n);
}

bst_node *bst_first_left_ancestor(bst_node *root, bst_node *n)
{
    if (!root || !n)
        return NULL;

    bst_node *parent = bst_get_parent(root, n);
    if (parent->right == n)
        return parent;
    else
        return bst_first_left_ancestor(root, parent);
}

bst_node *bst_find_inorder_predecessor(bst_node *root, int val)
{
    if (!root)
        return NULL;

    bst_node *parent = NULL;
    bst_node *val_node = bst_find_node(root, val, &parent);
    if (!val_node) {
        std::cout << "given value does not exists in the tree!" << std::endl;
        return NULL;
    } else if (val_node->left) {
        return bst_find_max(val_node->left);
    } else {    //when left is null, find first left ancestor
        return bst_first_left_ancestor(root, val_node);
    }
}

bst_node *bst_first_right_ancestor(bst_node *root, bst_node *n)
{
    if (!root || !n)
        return NULL;

    bst_node *parent = bst_get_parent(root, n);
    if (parent->left == n)
        return parent;
    else
        return bst_first_right_ancestor(root, parent);
}

bst_node *bst_find_inorder_successor(bst_node *root, int val)
{
    if (!root)
        return NULL;

    bst_node *parent = NULL;
    bst_node *val_node = bst_find_node(root, val, &parent);
    if (!val_node) {
        std::cout << "given value does not exists in the tree!" << std::endl;
        return NULL;
    } else if (val_node->right) {
        return bst_find_min(val_node->right);
    } else {    //when right is null, find first right ancestor
        return bst_first_right_ancestor(root, val_node);
    }
}

bst_node *bst_insert_a_node(bst_node *root, int val)
{
    if (!root)
        return bst_create_node(val);

    if (val > root->data)
        root->right = bst_insert_a_node(root->right, val);
    else
        root->left = bst_insert_a_node(root->left, val);

    return root;
}

bst_node *bst_delete_a_node(bst_node *root, int val)
{
    if (!root)
        return NULL;

    if (root->data == val && !root->left && !root->right) {
        delete root;
        return NULL;
    } else if (val == root->data) {
        bst_node *left_pred = bst_find_max(root->left);
        if (left_pred) {
            int temp = root->data;
            root->data = left_pred->data;
            left_pred->data = temp;
            root->left = bst_delete_a_node(root->left, val);
        } else {
            bst_node *right_succ = bst_find_min(root->right);
            int temp = root->data;
            root->data = right_succ->data;
            right_succ->data = temp;
            root->right = bst_delete_a_node(root->right, val);
        }
    } else if (val > root->data) {
        root->right = bst_delete_a_node(root->right, val);
    } else {
        root->left = bst_delete_a_node(root->left, val);
    }
    return root;
}

void bst_print_tree(bst_node *root)
{
    if (!root) {
        std::cout << "Invalid root\n";
        return;
    }

    my_queue *que = create_queue(MAX_LEN);
    enqueue(que, root);
    while (!is_empty(que)) {
        bst_node *temp = dequeue(que);
        std::cout << temp->data << " ";
        if (temp->left)
            enqueue(que, temp->left);
        if (temp->right)
            enqueue(que, temp->right);
    }
    std::cout << std::endl;
}

#endif // _BINARY_SEARCH_TREE_
