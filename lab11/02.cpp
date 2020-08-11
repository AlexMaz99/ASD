#include <iostream>

using namespace std;

const int n = 5;

void DFS_visit(bool graph[n][n], int v, int *result, bool *visited, int &ind) {
    visited[v] = true;

    for (int i = 0; i < n; i++)
        if (graph[v][i] && !visited[i])
            DFS_visit(graph, i, result, visited, ind);

    result[ind--] = v;
}


bool is_hamiltonian(bool graph[n][n]) {
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
            DFS_visit(graph, i, result, visited, ind);

    for (int i = 0; i < n; i++) cout << result[i] << " "; //sortowanie topologiczne

    for (int i = 0; i < n - 1; i++)
        if (!graph[result[i]][result[i + 1]]) {
            res = false;
            break;
        }

    delete[]visited;
    delete[]result;
    return res;
}


int main() {
    bool graph[n][n];

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            graph[i][j] = false;

    graph[1][4] = graph[2][1] = graph[2][3] = graph[3][0] = graph[3][1] = graph[4][0] = true;

    return is_hamiltonian(graph);
}