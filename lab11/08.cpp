#include <iostream>

using namespace std;
const int n = 5;

void FloydWarshall(int G[n][n]) {
    for (int k = 0; k < n; k++)
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++) {
                if (G[i][k] != INT_MAX && G[k][j] != INT_MAX)
                    G[i][j] = min(G[i][j], G[i][k] + G[k][j]);
            }
}


void add(int G[n][n], int u, int v, int cost) {
    G[u][v] = cost;
}

int main() {
    int graph[n][n];

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            graph[i][j] = INT_MAX;
        graph[i][i] = 0;
    }

    add(graph, 0, 1, 5);
    add(graph, 1, 0, -4);
    add(graph, 0, 2, 4);
    add(graph, 2, 4, 2);
    add(graph, 4, 2, 4);
    add(graph, 3, 4, -1);
    add(graph, 4, 3, 2);
    add(graph, 3, 1, 2);
    add(graph, 3, 0, -1);
    add(graph, 0, 3, 8);
    add(graph, 2, 3, 5);
    add(graph, 1, 4, 5);
    add(graph, 1, 2, -2);

    FloydWarshall(graph);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            cout << graph[i][j] << " ";
        cout << endl;
    }
    return 0;
}