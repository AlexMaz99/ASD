#include <iostream>

using namespace std;


struct node {
    int w;
    node *next;
};

void DFS(node **G, int n, int v, bool *visited, int *low, int *parent, int *d, int &time, bool *point) {
    visited[v] = true;
    int children = 0;
    d[v] = low[v] = ++time;

    for (node *p = G[v]; p != NULL; p = p->next) {
        if (!visited[p->w]) {
            children++;
            parent[p->w] = v;
            DFS(G, n, p->w, visited, low, parent, d, time, point);

            low[v] = min(low[v], low[p->w]);
            if (parent[v] != -1 && low[p->w] >= d[v]) point[v] = true;
            else if (parent[v] == -1 && children > 1) point[v] = true;
        } else if (p->w != parent[v]) low[v] = min(low[v], d[p->w]);
    }

}

void articulation_points(node **G, int n) {
    bool *visited = new bool[n];
    bool *point = new bool[n];
    int *low = new int[n];
    int *d = new int[n];
    int *parent = new int[n];
    int time = 0;

    for (int i = 0; i < n; i++) {
        visited[i] = point[i] = false;
        d[i] = 0;
        low[i] = INT_MAX;
        parent[i] = -1;
    }

    for (int i = 0; i < n; i++)
        if (!visited[i])
            DFS(G, n, 0, visited, low, parent, d, time, point);

    for (int i = 0; i < n; i++)
        if (point[i])
            cout << i << endl;

    delete[]visited;
    delete[]low;
    delete[]d;
    delete[]parent;
    delete[]point;
}


void add_edge(node **graph, int u, int v) {
    if (graph[u] == NULL) {
        graph[u] = new node;
        graph[u]->w = v;
        graph[u]->next = NULL;
        return;
    }

    node *tmp = new node;
    tmp->w = v;
    tmp->next = graph[u];
    graph[u] = tmp;
}

int main() {
    int n = 5;
    node *graph[n];

    for (int i = 0; i < n; i++) graph[i] = NULL;

    add_edge(graph, 0, 1);
    add_edge(graph, 1, 2);
    add_edge(graph, 0, 2);
    add_edge(graph, 0, 3);
    add_edge(graph, 3, 4);


    articulation_point(graph, n);
    return 0;
}