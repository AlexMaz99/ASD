#include <iostream>

using namespace std;

struct HT {
    int *table;
    int size;
};

int hash(int x) {
    return x;
}

void insert_hash(int *tab, int n, int x) {
    int h = hash(x) % n;
    int j = h;
    while (tab[h] >= 0) {
        h = (h + 1) % n;
        if (h == j) return;
    }
    tab[h] = x;
}

void enlarge(HT *ht) {
    int *res = new int[2 * ht->size];

    for (int i = 0; i < 2 * ht->size; i++) res[i] = -1;

    for (int i = 0; i < ht->size; i++) {
        int h = hash(ht->table[i]) % (2 * ht->size);
        if (ht->table[i] >= 0 && res[h] < 0) {
            res[h] = ht->table[i];
            ht->table[i] = -1;
        }
    }

    for (int i = 0; i < ht->size; i++) {
        if (ht->table[i] >= 0)
            insert_hash(res, 2 * ht->size, ht->table[i]);
    }

    ht->size *= 2;
    delete[]ht->table;
    ht->table = new int[ht->size * 2];
    for (int i = 0; i < ht->size * 2; i++)ht->table[i] = res[i];
    delete[]res;
}

int main() {
    HT *ht = new HT;
    ht->table = new int[10];
    ht->size = 10;

    for (int i = 0; i < ht->size; i++) ht->table[i] = -1;

    insert_hash(ht->table, 10, 5);
    insert_hash(ht->table, 10, 15);
    insert_hash(ht->table, 10, 25);
    insert_hash(ht->table, 10, 35);
    insert_hash(ht->table, 10, 4);
    insert_hash(ht->table, 10, 6);
    insert_hash(ht->table, 10, 14);

    for (int i = 0; i < ht->size; i++)
        cout << ht->table[i] << " ";
    cout << endl;

    enlarge(ht);

    for (int i = 0; i < ht->size; i++)
        cout << ht->table[i] << " ";
    cout << endl;

    return 0;
}