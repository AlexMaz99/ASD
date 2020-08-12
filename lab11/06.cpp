#include <iostream>

using namespace std;


int min_key(int *key, bool *visited, int N) {
    int mini = INT_MAX, min_index;

    for (int i = 0; i < N; i++)
        if (!visited[i] && key[i] < mini) {
            mini = key[i];
            min_index = i;
        }
    return min_index;
}


void primMST(int **G, int N) {
    int *parent = new int[N];
    int *key = new int[N];
    bool *visited = new bool[N];

    for (int i = 0; i < N; i++) {
        key[i] = INT_MAX;
        visited[i] = false;
    }

    key[0] = 0;
    parent[0] = -1;

    for (int i = 0; i < N - 1; i++) {
        int u = min_key(key, visited, N);
        visited[u] = true;

        for (int v = 0; v < N; v++)
            if (G[u][v] > 0 && !visited[v] && G[u][v] < key[v]) {
                parent[v] = u;
                key[v] = G[u][v];
            }
    }

    for (int i = 0; i < N; i++)
        cout << parent[i] << " " << i << endl;

    delete[]parent;
    delete[]key;
    delete[]visited;
}


void add(int **G, int u, int v, int w) {
    G[u][v] = G[v][u] = w;
}

int main() {
    int N = 9;
    int **graph = new int *[N];

    for (int i = 0; i < N; i++) graph[i] = new int[N];
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            graph[i][j] = -1;

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

    primMST(graph, N);
    return 0;
}