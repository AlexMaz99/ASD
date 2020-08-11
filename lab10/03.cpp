#include <iostream>

using namespace std;


const int N = 5;

bool is_sink(bool A[N][N], int i) {
    for (int j = 0; j < N; j++) {
        if (A[i][j]) return false;
        if (!A[j][i] && j != i) return false;
    }
    return true;
}

int eliminate(bool A[N][N]) {
    int i = 0, j = 0;
    while (i < N && j < N) {
        if (A[i][j]) i++;
        else j++;
    }

    if (i > N || !is_sink(A, i)) return -1;

    return i;
}

int graph_sink(bool A[N][N]) {
    int vertex = eliminate(A);
    if (vertex >= 0) return vertex + 1;
    return -1;
}


int main() {
    bool t[N][N];
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            cin >> t[i][j];
    /* 
      1 2 3 4 5
    1 0 0 0 1 0
    2 0 0 0 1 0
    3 0 0 0 1 0
    4 0 0 0 0 0
    5 0 0 0 1 0 */

    return graph_sink(t);
}