#include <iostream>

using namespace std;

struct node {
    int w;
    node *next;
};

void find_bridges(node **G, int n, int v, int *visited, int *low, int *parent, int *d, int &time) {
    visited[v] = 1;
    d[v] = low[v] = ++time;

    for (node *p = G[v]; p != NULL; p = p->next) {
        if (visited[p->w] == 0) {
            parent[p->w] = v;
            find_bridges(G, n, p->w, visited, low, parent, d, time);
            visited[v] = 2;
            low[v] = min(low[v], low[p->w]);
            //if (low[p->w]>d[v]) cout<<p->w<<" "<<v<<endl;
        } else if (p->w != parent[v])
            low[v] = min(low[v], d[p->w]);
    }

    if (low[v] == d[v] && parent[v] != -1) cout << parent[v] << " " << v << endl;
}

void Tarjan(node **G, int n) {
    int *visited = new int[n];
    int *low = new int[n];
    int *d = new int[n];
    int *parent = new int[n];
    int time = 0;

    for (int i = 0; i < n; i++) {
        visited[i] = d[i] = 0;
        low[i] = INT_MAX;
        parent[i] = -1;
    }

    find_bridges(G, n, 1, visited, low, parent, d, time);

    delete[]visited;
    delete[]low;
    delete[]d;
    delete[]parent;
}

void add_edge(node **graph, int u, int v) {
    if (graph[u] == NULL) {
        graph[u] = new node;
        graph[u]->w = v;
        graph[u]->next = NULL;
    } else {
        node *tmp = new node;
        tmp->w = v;
        tmp->next = graph[u];
        graph[u] = tmp;
    }

    if (graph[v] == NULL) {
        graph[v] = new node;
        graph[v]->w = u;
        graph[v]->next = NULL;
    } else {
        node *p = new node;
        p->w = u;
        p->next = graph[v];
        graph[v] = p;
    }


}

int main() {
    int N = 7;
    node *graph[N];

    for (int i = 0; i < N; i++) {
        graph[i] = NULL;
    }

    add_edge(graph, 1, 2);
    add_edge(graph, 2, 3);
    add_edge(graph, 1, 4);
    add_edge(graph, 3, 4);
    add_edge(graph, 4, 5);
    add_edge(graph, 5, 6);
    add_edge(graph, 0, 6);
    add_edge(graph, 0, 5);

    Tarjan(graph, N);

    return 0;
}