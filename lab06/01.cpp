#include <iostream>

using namespace std;

struct data {
    int w;
    bool taken;
    bool deleted;
};

int hash(int a, int n) {
    return a % n;
}

void insert(data T[], int n, int a) {
    int h = hash(a, n);
    int j = h;
    do {
        if (!T[j].taken) {
            T[j].w = a;
            T[j].taken = true;
            T[j].deleted = false;
            break;
        }
        if (!T[j].deleted && T[j].w == a) break;
        j = (j + 1) % 10;
    } while (j != h);

}

int find(data T[], int n, int a) {
    int key = hash(a, n);
    int h = key;
    while (T[key].taken || T[key].deleted) {
        if (T[key].w == a) return key;
        key = (key + 1) % n;
        if (h == key) return -1;
    }
}

void delete_n(data T[], int n, int a) {
    a = find(T, n, a);
    if (a == -1) return;
    T[a].taken = false;
    T[a].deleted = true;
}

void reorganizate(data T[], int n) {
    for (int i = 0; i < n; i++) {
        if (T[i].deleted) {
            T[i].deleted = false;
            int j = i + 1;
            while (i < n && j < n && (T[j].taken || T[j].deleted)) {
                if (hash(T[j].w, n) == hash(T[i].w, n)) {
                    T[i] = T[j];
                    T[j].taken = T[j].deleted = false;
                    i = j;
                }
                j++;
            }

        }

    }
}

void reorganizate2(data T[], int n) {
    data *tmp = new data[n];
    for (int i = 0; i < n; i++) {
        tmp[i].w = 0;
        tmp[i].taken = tmp[i].deleted = false;
    }
    for (int i = 0; i < n; i++) {
        if (T[i].taken)
            insert(tmp, n, T[i].w);
    }
    for (int i = 0; i < n; i++)
        T[i] = tmp[i];
    delete[]tmp;
}

void display(data T[], int n) {
    for (int i = 0; i < n; i++) {
        if (T[i].taken)
            cout << T[i].w << " ";
        else cout << "0 ";
    }
    cout << endl;
}

int main() {
    int n = 12;
    data T[n];
    for (int i = 0; i < n; i++) {
        T[i].w = 0;
        T[i].taken = T[i].deleted = false;
    }

    insert(T, n, 24);
    insert(T, n, 15);
    insert(T, n, 12);
    insert(T, n, 3);
    insert(T, n, 2);
    insert(T, n, 1);

    display(T, n);
    delete_n(T, n, 24);
    display(T, n);
    insert(T, n, 48);
    display(T, n);
    reorganizate2(T, n);
    insert(T, n, 24);
    delete_n(T, n, 1);
    delete_n(T, n, 48);
    display(T, n);
    reorganizate(T, n);
    display(T, n);

}