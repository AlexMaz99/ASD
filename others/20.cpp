#include <iostream>
#include <queue>

using namespace std;

struct node {
    int w;
    node *next;
};

void add_edge(node **graph, int st, int nd) {
    node *n = new node;
    n->w = nd;
    n->next = NULL;

    if (graph[st] == NULL) graph[st] = n;
    else {
        node *curr = graph[st];
        while (curr->next != NULL) curr = curr->next;
        curr->next = n;
    }


    node *m = new node;
    m->w = st;
    m->next = NULL;

    if (graph[nd] == NULL) graph[nd] = m;
    else {
        node *curr = graph[nd];
        while (curr->next != NULL) curr = curr->next;
        curr->next = m;
    }
}


int min_path(node **G, int v, int u, int n) {
    bool *visited = new bool[n];
    int *d = new int[n];
    int *counter = new int[n];

    for (int i = 0; i < n; i++) {
        visited[i] = false;
        d[i] = INT_MAX;
        counter[i] = 0;
    }

    queue<int> Q;
    Q.push(v);
    visited[v] = true;
    d[v] = 0;
    counter[v] = 1;

    while (!Q.empty()) {
        v = Q.front();
        Q.pop();
        for (node *p = G[v]; p != NULL; p = p->next) {
            if (d[v] + 1 < d[p->w]) {
                d[p->w] = d[v] + 1;
                counter[p->w] = counter[v];
            } else if (d[v] + 1 == d[p->w]) counter[p->w] += counter[v];
            if (!visited[p->w]) {
                visited[p->w] = true;
                Q.push(p->w);
            }

        }
    }
    //v = d[u]; dlugosc najkrotszej sciezki
    v = counter[u]; //ilosc najkrotszych sciezek
    delete[]counter;
    delete[]d;
    delete[]visited;
    return v;
}

int main() {
    int N = 7;
    node *graph[N];

    for (int i = 0; i < N; i++) {
        graph[i] = NULL;
    }

    add_edge(graph, 0, 2);
    add_edge(graph, 1, 2);
    add_edge(graph, 1, 4);
    add_edge(graph, 2, 3);
    add_edge(graph, 4, 5);
    add_edge(graph, 4, 6);
    add_edge(graph, 5, 6);
    add_edge(graph, 4, 3);

    cout << min_path(graph, 2, 6, N);
    return 0;
}