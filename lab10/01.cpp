#include <iostream>
#include <queue>
#include <stack>

using namespace std;

struct node {
    int w;
    node *next;
};

bool is_bipartite(node **A, int n) {
    queue<int> Q;
    int *color = new int[n];
    int v;
    for (int i = 0; i < n; i++) color[i] = 0;

    for (int i = 0; i < n; i++) {
        if (color[i] == 0) {
            color[i] = 1;
            Q.push(i);

            while (!Q.empty()) {
                v = Q.front();
                Q.pop();

                for (node *p = A[v]->next; p != NULL; p = p->next) {
                    if (color[p->w] == color[v]) {
                        delete[]color;
                        return false;
                    }

                    if (color[p->w] == 0) {
                        color[p->w] = color[v] * (-1);
                        Q.push(p->w);
                    }
                }
            }
        }
    }

    delete[]color;
    return true;
}

void add_edge(node **graph, int st, int nd) {  // for undirected graphs
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

int calculate_components(node **A, int n) {
    int *count = new int[n];
    for (int i = 0; i < n; i++) count[i] = 0;
    int counter = 0, v;
    stack<int> S;

    for (int i = 0; i < n; i++) {
        if (count[i] == 0) {
            counter++;
            count[i] += counter;
            S.push(i);
            while (!S.empty()) {
                v = S.top();
                S.pop();
                for (node *p = A[v]->next; p != NULL; p = p->next) {
                    if (count[p->w] == 0) {
                        S.push(p->w);
                        count[p->w] = counter;
                    }
                }
            }
        }
    }
    delete[]color;
    return true;
}

int main() {
    int N = 9;
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
    add_edge(graph, 7, 8);

    //print(graph,N);

    cout << calculate_components(graph, N);
    return is_bipartite(graph, N);

}