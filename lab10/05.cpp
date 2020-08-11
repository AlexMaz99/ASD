#include <iostream>
#include <queue>

using namespace std;

struct node {
    int w;
    node *next;
};

void dfs_visit(node **A, int n, int &time, bool *visited, int *d, int v) {
    visited[v] = true;
    cout << v << " ";
    time++;
    d[v] = time;

    for (node *p = A[v]->next; p != NULL; p = p->next)
        if (!visited[p->w])
            dfs_visit(A, n, time, visited, d, p->w);
}

void DFS(node **A, int n) {
    bool *visited = new bool[n];
    int *d = new int[n];

    for (int i = 0; i < n; i++) {
        visited[i] = false;
        d[i] = 0;
    }

    int time = 0;

    for (int v = 0; v < n; v++)
        if (!visited[v])
            dfs_visit(A, n, time, visited, d, v);

    delete[]visited;
    delete[]d;
}

void add_edge(node **graph, int st, int nd) {            // for undirected graphs
    node *n = new node;
    n->w = nd;
    n->next = NULL;

    node *curr = graph[st];
    while (curr->next != NULL)
        curr = curr->next;

    curr->next = n;

    node *m = new node;
    m->w = st;
    m->next = NULL;

    curr = graph[nd];
    while (curr->next != NULL)
        curr = curr->next;

    curr->next = m;
}


int main() {
    int N = 8;
    node *graph[N];

    for (int i = 0; i < N; i++) {
        graph[i] = new node;
        graph[i]->next = NULL;
    }

    add_edge(graph, 0, 1);
    add_edge(graph, 0, 2);
    add_edge(graph, 3, 4);
    add_edge(graph, 3, 5);
    add_edge(graph, 5, 6);
    add_edge(graph, 7, 4);
    add_edge(graph, 4, 5);
    add_edge(graph, 2, 4);

    DFS(graph, N);
}