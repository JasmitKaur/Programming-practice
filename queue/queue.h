#ifndef _QUEUE_H_
#define _QUEUE_H_

#include <iostream>
#include <vector>

struct my_queue {
    int capacity;
    int front;
    int rear;
    std::vector<int> q;
};

#define FAILURE -1;
#define SUCCESS 0;

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

int enqueue(my_queue *que, int val)
{
    if (!que) {
        std::cout << "Invalid pointer to queue\n";
        return FAILURE;
    }

    if (is_full(que) == 1) {
        std::cout << "Queue is full\n";
        return FAILURE;
    }

    que->rear++;
    que->q.push_back(val);

    if (que->front == -1)   //for first element
        que->front = que->rear;

    return SUCCESS;
}

int dequeue(my_queue *que)
{
    if (!que) {
        std::cout << "Invalid pointer to queue\n";
        return FAILURE;
    }

    if (is_empty(que) == 1) {
        std::cout << "Queue is empty\n";
        return FAILURE;
    }

    int val = que->q.front();
    que->q.erase(que->q.begin());

    if (que->front == que->rear) {  //last element is being deleted
        que->front = -1;
        que->rear = -1;
    } else
        que->front++;

    return val;
}

void print_queue(my_queue *que)
{
    if (!que) {
        std::cout << "Invalid pointer to queue\n";
        return;
    }

    if (is_empty(que) == 1) {
        std::cout << "Queue is empty\n";
        return;
    }

    std::vector<int>::iterator it;
    for (it = que->q.begin(); it < que->q.end(); it++)
        std::cout << *it << " ";
    std::cout << std::endl;
}

#endif  // _QUEUE_H_
