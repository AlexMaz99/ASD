#include <iostream>

using namespace std;

struct node {
    int w;
    node *next;
};

void DFS_visit(node **graph, int n, int v, int *result, bool *visited, int &ind) {
    visited[v] = true;

    for (node *p = graph[v]; p != NULL; p = p->next)
        if (!visited[p->w])
            DFS_visit(graph, n, p->w, result, visited, ind);

    result[ind--] = v;
}

bool exist(node **graph, int v, int u) {
    while (graph[v] != NULL) {
        if (graph[v]->w == u) return true;
        graph[v] = graph[v]->next;
    }
    return false;
}

bool is_hamiltonian(node **graph, int n) {
    bool *visited = new bool[n];
    int *result = new int[n];
    int ind = n - 1;
    bool res = true;

    for (int i = 0; i < n; i++) {
        visited[i] = false;
        result[i] = -1;
    }
    for (int i = 0; i < n; i++)
        if (!visited[i])
            DFS_visit(graph, n, i, result, visited, ind);

    for (int i = 0; i < n; i++) cout << result[i] << " "; //sortowanie topologiczne

    for (int i = 0; i < n - 1; i++)
        if (!exist(graph, result[i], result[i + 1])) {
            res = false;
            break;
        }

    delete[]visited;
    delete[]result;
    return res;
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
    int N = 5;
    node *graph[N];

    for (int i = 0; i < N; i++) {
        graph[i] = NULL;
    }

    add_edge(graph, 1, 4);
    add_edge(graph, 2, 3);
    add_edge(graph, 2, 1);
    add_edge(graph, 3, 1);
    add_edge(graph, 3, 0);
    add_edge(graph, 4, 0);

    return is_hamiltonian(graph, N);
}