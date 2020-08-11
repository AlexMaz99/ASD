#include <iostream>

using namespace std;

struct node {
    int w;
    int cost;
    node *next;
};

int min_distance(int *d, bool *visited, int n) {
    int min = INT_MAX;
    int min_index = 0;
    for (int v = 0; v < n; v++)
        if (!visited[v] && d[v] < min) {
            min = d[v];
            min_index = v;
        }
    return min_index;
}

void Dijkstra(node **G, int n, int s) {
    int *d = new int[n];
    int *parent = new int[n];
    bool *visited = new bool[n];
    for (int i = 0; i < n; i++) {
        d[i] = INT_MAX;
        parent[i] = -1;
        visited[i] = false;
    }
    d[s] = 0;

    for (int i = 0; i < n - 1; i++) {
        int u = min_distance(d, visited, n);
        visited[u] = true;

        for (node *p = G[u]; p != NULL; p = p->next) {
            if (!visited[p->w] && d[u] != INT_MAX && d[p->w] > d[u] + p->cost) {
                d[p->w] = d[u] + p->cost;
                parent[p->w] = u;
            }
        }
    }

    for (int i = 0; i < n; i++) cout << d[i] << " ";
    cout << endl;
    for (int i = 0; i < n; i++) cout << parent[i] << " ";
}

void add_edge(node **graph, int u, int v, int cost) {
    if (graph[u] == NULL) {
        graph[u] = new node;
        graph[u]->w = v;
        graph[u]->next = NULL;
        graph[u]->cost = cost;
        return;
    }

    node *tmp = new node;
    tmp->w = v;
    tmp->cost = cost;
    tmp->next = graph[u];
    graph[u] = tmp;
}

int main() {
    int n = 6;
    node *graph[n];
    for (int i = 0; i < n; i++) graph[i] = NULL;

    add_edge(graph, 0, 1, 3);
    add_edge(graph, 0, 4, 3);
    add_edge(graph, 1, 2, 1);
    add_edge(graph, 2, 3, 3);
    add_edge(graph, 2, 5, 1);
    add_edge(graph, 3, 1, 3);
    add_edge(graph, 4, 5, 2);
    add_edge(graph, 5, 3, 1);

    Dijkstra(graph, n, 0);

}