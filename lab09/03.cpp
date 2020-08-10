#include <iostream>

using namespace std;

struct e {
    int u, v;
    int w;
};


e *delete_edges(e edges[], int N) {
    sort_e(edges, N); //sortuje krawedzie po wagach rosnaco
    int parent[N];
    int rank[N];
    for (int i = 0; i < N; i++) rank[i] = 1;

    for (int i = 0; i < N; i++)
        if (find(edges[i].u) != find(edges[i].v)) //jezeli sa to zbiory rozlaczne to je scalamy
        {
            union (edges[i].v, edges[i].u);
            cout << edge[i];
        }
}

int main() {

}