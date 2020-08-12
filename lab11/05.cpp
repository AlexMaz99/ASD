#include <iostream>

using namespace std;

struct node {
    int w;
    node *next;
    int cost;
};

struct edge {
    int u;
    int v;
    int cost;
    edge *next;
};

struct subset {
    subset *parent;
    int rank;
};

subset *find(subset *x) {
    if (x->parent == x) return x;
    x->parent = find(x->parent);
    return x->parent;
}

void Union(subset *x, subset *y) {
    if (x->rank > y->rank) y->parent = x;
    else {
        x->parent = y;
        if (x->rank == y->rank) y->rank++;
    }
}

void Kruskal(node **G, int n) {
    edge *first = new edge;
    first->next = NULL;
    first->u = first->v = first->cost = -1;
    edge *tmp = first;

    for (int i = 0; i < n; i++) //stworzenie listy krawedzi
    {
        node *p = G[i];

        while (p != NULL) {
            tmp = first;

            while (tmp->next != NULL && tmp->next->cost < p->cost) tmp = tmp->next;

            if ((tmp->next != NULL && (min(i, p->w) != tmp->next->u || max(i, p->w) != tmp->next->v)) ||
                tmp->next == NULL) {
                edge *n = new edge;
                n->cost = p->cost;
                n->u = min(i, p->w);
                n->v = max(i, p->w);
                n->next = tmp->next;
                tmp->next = n;
            }
            p = p->next;
        }
    }
    tmp = first;
    first = first->next;
    delete tmp;

    edge *result[n];
    subset *Subsets[n];

    for (int i = 0; i < n; i++) {
        Subsets[i] = new subset;
        result[n] = new edge;
        Subsets[i]->parent = Subsets[i];
        Subsets[i]->rank = 0;
    }

    int e = 0, v = 0;

    while (e < n - 1) {
        edge *tmp = first;
        first = first->next;

        subset *x = find(Subsets[tmp->u]);
        subset *y = find(Subsets[tmp->v]);

        if (x != y) {
            result[e++] = tmp;
            Union(x, y);
        }
    }

    for (int i = 0; i < n - 1; i++)
        cout << result[i]->u << " " << result[i]->v << " " << result[i]->cost << endl;
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

    if (graph[v] == NULL) {
        graph[v] = new node;
        graph[v]->w = u;
        graph[v]->next = NULL;
        graph[v]->cost = cost;
    } else {
        node *tmp = new node;
        tmp->w = u;
        tmp->cost = cost;
        tmp->next = graph[v];
        graph[v] = tmp;
    }
}

int main() {
    int N = 9;
    node *graph[N];

    for (int i = 0; i < N; i++) graph[i] = NULL;

    add(graph, 0, 1, 4);
    add(graph, 1, 2, 9);
    add(graph, 0, 7, 8);
    add(graph, 1, 7, 11);
    add(graph, 6, 7, 1);
    add(graph, 6, 8, 6);
    add(graph, 7, 8, 7);
    add(graph, 2, 8, 2);
    add(graph, 5, 6, 2);
    add(graph, 2, 5, 4);
    add(graph, 2, 3, 7);
    add(graph, 3, 4, 9);
    add(graph, 4, 5, 10);
    add(graph, 3, 5, 14);


    Kruskal(graph, N);
    return 0;
}