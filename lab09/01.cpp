#include <iostream>

using namespace std;
const int N = 4;

struct node {
    bool val;
    node *parent; //reprezentant
    int rank;
};

node *make_set(bool val) {
    node *r = new node;
    r->parent = r;
    r->val = val;
    r->rank = 1;
    return r;
}

node *find_head(node *n) {
    if (n->parent == n) return n;
    find_head(n->parent);
}


void union_node(node *p1, node *p2) {
    node *r1 = find_head(p1);
    node *r2 = find_head(p2);

    if (r1 == r2) return;
    if (r2->rank < r1->rank) {
        r2->parent = r1;
        r1->rank += r2->rank;
    } else {
        r1->parent = r2;
        r2->rank += r1->rank;
    }

}

int how_many(bool A[][N], int x, int y) {
    node *tab[N][N];
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            tab[i][j] = make_set(A[i][j]);
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (A[i][j]) {
                if (i + 1 < N && tab[i + 1][j]->val) union_node(tab[i + 1][j], tab[i][j]);
                if (i - 1 >= 0 && tab[i - 1][j]->val) union_node(tab[i - 1][j], tab[i][j]);
                if (j + 1 < N && tab[i][j + 1]->val) union_node(tab[i][j + 1], tab[i][j]);
                if (j - 1 >= 0 && tab[i][j - 1]->val) union_node(tab[i][j - 1], tab[i][j]);
            }
        }
    }

    int count = find_head(tab[x][y])->rank - 1;
    for (int i = 0; i < N; i++) delete[]tab;
    delete[]tab;
    return count;

}

int main() {
    //int N=5;
    bool A[N][N];
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            cin >> A[i][j];

    cout << how_many(A, 0, 0);

}