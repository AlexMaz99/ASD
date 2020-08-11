#include <iostream>
#include <math.h>

using namespace std;
const int N = 5;

struct point {
    int x;
    int y;
};

int min_key(double *key, bool *visited) {
    int mini = INT_MAX, min_index;

    for (int i = 0; i < N; i++)
        if (!visited[i] && key[i] < mini) {
            mini = key[i];
            min_index = i;
        }

    return min_index;
}

double distance(int x1, int y1, int x2, int y2) {
    return sqrt(double((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2)));
}

double primMST(point *points) {
    double **graph = new double *[N];
    int *parent = new int[N];
    double *key = new double[N];
    bool *visited = new bool[N];

    for (int i = 0; i < N; i++) graph[i] = new double[N];

    for (int i = 0; i < N; i++)
        for (int j = i; j < N; j++)
            graph[i][j] = graph[j][i] = distance(points[i].x, points[i].y, points[j].x, points[j].y);

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cout << graph[i][j] << " ";
        }
        cout << endl;
    }

    for (int i = 0; i < N; i++) {
        key[i] = INT_MAX;
        visited[i] = false;
    }

    key[0] = 0;
    parent[0] = -1;

    for (int i = 0; i < N - 1; i++) {
        int u = min_key(key, visited);
        visited[u] = true;

        for (int v = 0; v < N; v++)
            if (graph[u][v] > 0 && !visited[v] && graph[u][v] < key[v]) {
                parent[v] = u;
                key[v] = graph[u][v];
            }
    }

    double sum = 0;
    for (int i = 0; i < N; i++)
        sum += graph[i][parent[i]];

    delete[]parent;
    delete[]key;
    delete[]visited;

    for (int i = 0; i < N; i++) delete[]graph[i];
    delete[]graph;

    return sum;
}

int main() {
    point points[N];
    for (int i = 0; i < N; i++)
        cin >> points[i].x >> points[i].y;

    cout << primMST(points);
}