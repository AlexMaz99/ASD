#include <iostream>
#include <queue>

using namespace std;

struct node {
    int w;
    node *next;
};

void BFS(node **A, int n, int s) {
    queue<int> Q;
    bool *visited = new bool[n];
    int *parent = new int[n];
    int *d = new int[n];

    for (int i = 0; i < n; i++) {
        visited[i] = false;
        parent[i] = 0;
        d[i] = 0;
    }

    visited[s] = true;
    Q.push(s);

    while (!Q.empty()) {
        s = Q.front();
        cout << s << " ";
        Q.pop();

        for (node *p = A[s]->next; p != NULL; p = p->next) {
            if (!visited[p->w]) {
                visited[p->w] = true;
                parent[p->w] = s;
                d[p->w] = d[s] + 1;
                Q.push(p->w);
            }
        }
    }

    delete[]visited;
    delete[]parent;
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


    BFS(graph, N, 0);

}