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

#define MY_INT_MAX 100

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

    L[0] = 1;
    L[1] = 3;
    adj[0] = create_adj_list(L, 2);

    L[0] = 3;
    L[1] = 4;
    adj[1] = create_adj_list(L, 2);

    L[0] = 0;
    L[1] = 5;
    adj[2] = create_adj_list(L, 2);

    L[0] = 5;
    L[1] = 6;
    adj[3] = create_adj_list(L, 2);

    adj[4] = create_graph_node(6);

    adj[6] = create_graph_node(5);

    return adj;
}

graph *create_graph()
{
    graph *G = new graph;
    G->V = 7;
    G->E = 10;
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

void fill_indegree(int *indegree)
{
    indegree[0] = 1;
    indegree[1] = 1;
    indegree[2] = 0;
    indegree[3] = 2;
    indegree[4] = 1;
    indegree[5] = 3;
    indegree[6] = 2;
}

void topological_sorting(graph *G, int * indegree)
{
    queue<int> que;
    int i, curr, count = 0;
    int visited[G->V];

    for (i = 0; i < G->V; ++i)
        visited[i] = 0;

    for (i = 0; i < G->V; ++i) {
        if (!indegree[i])
            que.push(i);
    }

    cout << "Topological sorting: ";
    while (!que.empty()) {
        curr = que.front();
        que.pop();
        ++count;

        if (!visited[curr]) {

            visited[curr] = 1;
            cout << curr << " ";

            graph_node *temp = G->adj[curr];
            while (temp) {
                if(--indegree[temp->vertex_no] == 0)
                    que.push(temp->vertex_no);
                temp = temp->next;
            }
        }
    }
    if (count != G->V)
        cout << endl << "Graph has cycle" << endl;
    else
        cout << endl;
}

// all node shortest path from s, in unweighted graph
void shortest_path(graph *G, int s, int *distance)
{
    int i, j, curr, index;
    int visited[G->V];
    queue<int> que;
    int path[G->V][G->V];

    for (i = 0; i < G->V; ++i)
        distance[i] = -1;
    distance[s] = 0;

    for (i = 0; i < G->V; ++i)
        visited[i] = 0;

    // using 0th index to store index of path to be inserted
    for (i = 0; i < G->V; ++i)
        path[i][0] = 0;

    que.push(s);
    index = ++path[s][0];
    path[s][index] = s;

    while (!que.empty()) {
        curr = que.front();
        que.pop();

        if (!visited[curr]) {
            visited[curr] = 1;

            graph_node *temp = G->adj[curr];
            while (temp) {
                if (distance[temp->vertex_no] == -1) {
                    distance[temp->vertex_no] = distance[curr] + 1;

                    for (i = 1; i <= path[curr][0]; ++i) {
                        index = ++path[temp->vertex_no][0];
                        path[temp->vertex_no][index] = path[curr][i];
                    }
                    index = ++path[temp->vertex_no][0];
                    path[temp->vertex_no][index] = temp->vertex_no;
                }

                que.push(temp->vertex_no);
                temp = temp->next;
            }
        }
    }

    for (i = 0; i < G->V; ++i) {
        cout << i << "  |  " << distance[i] << "  |  ";
        for (j = 1; j <= path[i][0]; ++j)
            cout << path[i][j] << " ";
        cout << endl;
    }
}

int main ()
{
    graph *G = create_graph();
    print_adjacency_list(G);

    BFS_traversal(G);
    DFS_traversal(G);

    int indegree[G->V];
    fill_indegree(indegree);
    topological_sorting(G, indegree);

    int distance[G->V];
    shortest_path(G, 2, distance);

    return 0;
}

