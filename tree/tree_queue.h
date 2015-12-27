#ifndef _QUEUE_H_
#define _QUEUE_H_

#include <iostream>
#include <vector>

struct node {
    int data;
    node *left;
    node *right;
};

struct my_queue {
    int capacity;
    int front;
    int rear;
    std::vector<node *> q;
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

int enqueue(my_queue *que, node *n)
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

node *dequeue(my_queue *que)
{
    if (!que) {
        std::cout << "Invalid pointer to queue\n";
        return NULL;
    }

    if (is_empty(que) == 1) {
        std::cout << "Queue is empty\n";
        return NULL;
    }

    node *n = que->q.front();
    que->q.erase(que->q.begin());

    if (que->front == que->rear) {  //last element is being deleted
        que->front = -1;
        que->rear = -1;
    } else
        que->front++;

    return n;
}

void print_tree(node *root)
{
    if (!root) {
        std::cout << "Invalid root\n";
        return;
    }

    my_queue *que = create_queue(MAX_LEN);
    enqueue(que, root);
    while (!is_empty(que)) {
        node *temp = dequeue(que);
        std::cout << temp->data << " ";
        if (temp->left)
            enqueue(que, temp->left);
        if (temp->right)
            enqueue(que, temp->right);
    }
    std::cout << std::endl;
}

node *create_node(int val)
{
    node *new_node = new node;
    new_node->data = val;
    new_node->left = NULL;
    new_node->right = NULL;
    return new_node;
}

int insert_node(node *root, node *n)
{
    if (!root) {
        std::cout << "Invalid root\n";
        return FAILURE;
    }

    my_queue *que = create_queue(7);
    enqueue(que, root);
    while (!is_empty(que)) {
        node *temp = dequeue(que);
        if (!temp->left) {
            temp->left = n;
            return SUCCESS;
        } else if (!temp->right) {
            temp->right = n;
            return SUCCESS;
        } else {
            enqueue(que, temp->left);
            enqueue(que, temp->right);
        }
    }
}

#endif  // _QUEUE_H_

