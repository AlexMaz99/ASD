#include <iostream>

using namespace std;

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

void Dijkstra(int **G, int n, int s) {
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

        for (int v = 0; v < n; v++) {
            if (!visited[v] && G[u][v] >= 0 && d[u] != INT_MAX && d[v] > d[u] + G[u][v]) {
                d[v] = d[u] + G[u][v];
                parent[v] = u;
            }
        }
    }

    for (int i = 0; i < n; i++) cout << d[i] << " ";
    cout << endl;
    for (int i = 0; i < n; i++) cout << parent[i] << " ";

}

int main() {
    int n = 6;
    int **G = new int *[n];
    for (int i = 0; i < n; i++) G[i] = new int[n];
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> G[i][j];
    Dijkstra(G, n, 0);

    int parent[n] = {-1, 0, 1, 5, 0, 4};
    int i = 3;
    while (i != -1) {
        cout << i << " ";
        i = parent[i];
    }
}
