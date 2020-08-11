#include <iostream>
#include <queue>
#include <stack>

using namespace std;

const int N = 5;


bool is_bipartite(bool A[N][N]) {
    queue<int> Q;
    int *color = new int[N];
    for (int i = 0; i < N; i++) color[i] = 0;
    color[0] = 1;
    Q.push(0);


    while (!Q.empty()) {
        int u = Q.front();
        Q.pop();
        if (A[u][u] == 1) return false;

        for (int v = 0; v < N; v++) {
            if (A[u][v] && color[v] == 0) {
                color[v] = color[u] * (-1);
                Q.push(v);
            } else if (A[u][v] && color[v] == color[u]) {
                delete[]color;
                return false;
            }

        }
    }

    delete[]color;
    return true;
}


int main() {
    bool t[N][N];
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            cin >> t[i][j];
    /*
    1 2 3 4 5
    1 0 1 1 0 0
    2 1 0 0 0 0
    3 1 0 0 0 0
    4 0 0 0 0 1
    5 0 0 0 1 0
    */

    return is_bipartite(t);
}