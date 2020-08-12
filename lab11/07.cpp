#include <iostream>

using namespace std;

struct node {
    int w;
    int cost;
    node *next;
};

bool BellmanFord(node **G, int n, int s) {
    int *d = new int[n];
    int *parent = new int[n];
    bool test = true;

    for (int i = 0; i < n; i++) {
        d[i] = INT_MAX;
        parent[i] = -1;
    }

    d[s] = 0;

    for (int i = 1; i < n; i++) {
        test = true;

        for (int v = 0; v < n; v++) {
            for (node *p = G[v]; p != NULL; p = p->next) {
                if (d[v] != INT_MAX && d[p->w] > d[v] + p->cost) {
                    test = false;
                    d[p->w] = d[v] + p->cost;
                    parent[p->w] = v;
                }
            }
        }

        if (test) break;
    }

    for (int i = 0; i < n; i++)
        cout << d[i] << " ";
    cout << endl;

    for (int i = 0; i < n; i++)
        cout << parent[i] << " ";

    for (int i = 0; i < n; i++)
        for (node *p = G[i]; p != NULL; p = p->next)
            if (d[p->w] > d[i] + p->cost) return false;

    return true;
}


void add(node **graph, int u, int v, int cost) {
    if (graph[u] == NULL) {
        graph[u] = new node;
        graph[u]->w = v;
        graph[u]->next = NULL;
        graph[u]->cost = cost;
    } else {
        node *tmp = new node;
        tmp->w = v;
        tmp->cost = cost;
        tmp->next = graph[u];
        graph[u] = tmp;
    }

}

int main() {
    int N = 6;
    node *graph[N];

    for (int i = 0; i < N; i++) graph[i] = NULL;

    add(graph, 0, 1, 5);
    add(graph, 1, 3, 3);
    add(graph, 1, 4, 9);
    add(graph, 4, 2, -1);
    add(graph, 3, 5, 2);
    add(graph, 5, 2, 8);
    add(graph, 2, 1, -4);
    add(graph, 2, 0, 3);
    add(graph, 4, 5, -5);
    add(graph, 5, 0, 9);
    add(graph, 3, 4, 3);

    BellmanFord(graph, N, 0);
    return 0;
}