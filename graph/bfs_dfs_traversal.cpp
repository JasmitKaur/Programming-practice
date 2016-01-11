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

struct graph_node {
    int vertex_no;      // current vertex number > work as data in node
    graph_node *next;   // pointer to next node in adjacency list
};

struct graph {
    int V;              // no of nodes
    int E;              // no of edges
    graph_node **adj;   // adjacency list
};

graph_node *create_graph_node(int i)
{
    graph_node *node = new graph_node;
    node->vertex_no = i;
    node->next = NULL;
    return node;
}

graph_node *create_adj_list(int *L, int n)
{
    int i = 0;
    graph_node *head = create_graph_node(L[i]);
    graph_node *prev = head;
    graph_node *temp = NULL;
    for (i = 1; i < n; ++i) {
        temp = create_graph_node(L[i]);
        prev->next = temp;
        prev = temp;
        temp = temp->next;
    }
    return head;
}

graph_node **create_adjacency_list(graph *G)
{
    if (!G)
        return NULL;

    graph_node **adj = new graph_node*[G->V];
    int L[G->V];
    int i;
    for (i = 0; i < G->V; ++i)
        adj[i] = NULL;

    adj[0] = create_graph_node(1);

    L[0] = 0;
    L[1] = 2;
    L[2] = 7;
    adj[1] = create_adj_list(L, 3);

    L[0] = 1;
    L[1] = 3;
    L[2] = 4;
    adj[2] = create_adj_list(L, 3);

    adj[3] = create_graph_node(2);

    L[0] = 2;
    L[1] = 5;
    L[2] = 6;
    L[3] = 7;
    adj[4] = create_adj_list(L, 4);

    adj[5] = create_graph_node(4);

    adj[6] = create_graph_node(4);

    L[0] = 1;
    L[1] = 4;
    adj[7] = create_adj_list(L, 2);

    return adj;
}

graph *create_graph()
{
    graph *G = new graph;
    G->V = 8;   // i.e. nodes from 0 to 7
    G->E = 8;
    G->adj = create_adjacency_list(G);
    return G;
}

void print_adjacency_list(graph *G)
{
    int i;
    graph_node *temp = NULL;

    for (i = 0; i < G->V; ++i) {
        cout << i << "  |  ";
        temp = G->adj[i];
        while (temp) {
            cout << temp->vertex_no << " ";
            temp = temp->next;
        }
        cout << endl;
    }
}

void DFS(graph *G, int *visited, int i)
{
    visited[i] = 1;
    cout << i << " ";

    graph_node *temp = G->adj[i];
    while (temp) {
        if (!visited[temp->vertex_no])
            DFS(G, visited, temp->vertex_no);
        temp = temp->next;
    }
}

void DFS_traversal(graph *G)
{
    int i;
    int visited[G->V];

    for (i = 0; i < G->V; ++i)
        visited[i] = 0;

    cout << "DFS traversal: ";
    for (i = 0; i < G->V; ++i) {
        if (!visited[i])
            DFS(G, visited, i);
    }
    cout << endl;
}

void BFS(graph *G, int *visited, int i)
{
    int curr;
    queue<int> que;
    que.push(i);

    while (!que.empty()) {
        curr = que.front();
        que.pop();

        if (!visited[curr]) {
            visited[curr] = 1;
            cout << curr << " ";

            graph_node *temp = G->adj[curr];
            while (temp) {
                que.push(temp->vertex_no);
                temp = temp->next;
            }
        }
    }
}

void BFS_traversal(graph *G)
{
    int i;
    int visited[G->V];

    for (i = 0; i < G->V; ++i)
        visited[i] = 0;

    cout << "BFS traversal: ";
    for (i = 0; i < G->V; ++i) {
        if (!visited[i])
            BFS(G, visited, i);
    }
    cout << endl;
}

int main ()
{
    graph *G = create_graph();
    print_adjacency_list(G);

    BFS_traversal(G);
    DFS_traversal(G);

    return 0;
}

