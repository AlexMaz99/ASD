#include <iostream>

using namespace std;

struct node {
    node *parent;
    int rank;
};
const int N = 4;

node *find(node *p) {
    if (p->parent == p) return p;
    p->parent = find(p->parent);
    return p->parent;
}

void union(node *x, node *y) {
    node *xp = find(x);
    node *yp = find(y);
    if (xp == yp) return;
    if (xp->rank > yp->rank) yp->parent = xp;
    else {
        xp->parent = yp;
        if (xp->rank == yp->rank) yp->rank++;
    }
}

bool can_dock(int tab[N][N], int x, int y, int t) {
    node *S[N][N];
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++) {
            S[i][j] = new node;
            S[i][j]->parent = S[i][j];
            S[i][j]->rank = 0;
        }
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++) {
            if (tab[i][j] >= t) {
                if (i + 1 < N && tab[i + 1][j] >= t) union(S[i][j], S[i + 1][j]);
                if (j + 1 < N && tab[i][j + 1] >= t) union(S[i][j], S[i][j + 1]);
            }
        }
    bool result = false;
    if (find(S[x][y]) == find(S[0][0])) result = true;
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            delete S[i][j];
    return result;
}


int main() {
    int tab[N][N];
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            cin >> tab[i][j];
    return can_dock(tab, 3, 3, 5);

}
