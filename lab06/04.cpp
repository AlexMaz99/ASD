#include <iostream>

using namespace std;


struct node {
    int key;
    bool taken;
};

void rebuild(node *tab, int n) {
    node *n_tab = new node[n];
    for (int i = 0; i < n; i++) n_tab[i]->taken = false;
    for (int i = 0; i < n; i++) {
        int index = hash(tab[i]->key);
        if (tab[i]->taken && !n_tab[index]->taken) {
            n_tab[index] = tab[i];
            tab[i]->taken = false;
        }
    }

    for (int i = 0; i < n; i++)
        if (tab[i]->taken) insert(n_tab, tab[i]->key);
    for (int i = 0; i < n; i++) tab[i] = n_tab[i];
    delete[]n_tab;
}


int main() {

}
