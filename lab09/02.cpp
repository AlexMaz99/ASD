#include <iostream>

using namespace std;

struct node {
    int n;
    int N;
    int *key; //key[N]
    node **child; //child[N+1]
    bool leaf;
};

bool is_b_tree(node *p, int min, int max, int lvl, int &leaf_lvl) {
    if (lvl != 0 && ((p->N + 1) / 2 > p->n || p->n >= p->N)) return false;
    if (p->leaf) {
        if (leaf_lvl == -1) {
            leaf_lvl = lvl;
            return true;
        }
        if (lvl == leaf_lvl) return true;
        return false;
    }
    if (p->key[0] < min) return false;
    if (!is_b_tree(p->child[0], min, p->key[0], lvl + 1, leaf_lvl)) return false;
    for (int i = 0; i < p->n; i++) {
        if (p->key[i - 1] > p->key[i]) return false;
        if (!is_b_tree(p->child[i], p->key[i - 1], p->key[i], lvl + 1, leaf_lvl)) return false;
    }
    if (p->key[p->n - 1] > max) return false;
    if (!is_b_tree(p->child[p->n], p->key[p->n - 1], max, lvl + 1, leaf_lvl)) return false;
    return true;
}

int main() {


}