#include <iostream>

using namespace std;

struct node {
    int w;
    node *next;
};

void dfs_visit(node **G, int n, int v, bool *visited, node *&first) {
    visited[v] = true;

    for (node *p = G[v]; p != NULL; p = p->next)
        if (!visited[p->w])
            dfs_visit(G, n, p->w, visited, first);

    node *tmp = new node;
    tmp->w = v;
    tmp->next = first;
    first = tmp;
}

node *sort_top(node **G, int n) {
    bool *visited = new bool[n];

    for (int i = 0; i < n; i++) visited[i] = false;

    node *first = NULL;

    for (int i = 0; i < n; i++)
        if (!visited[i])
            dfs_visit(G, n, i, visited, first);

    return first;
}

int main() {

}