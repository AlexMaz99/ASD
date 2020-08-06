#include <iostream>
#include <cmath>

using namespace std;

struct data {
    int w;
    bool taken;
};

int hash(int a, int n) {
    return abs(a % n);
}

void insert(data T[], int n, int a) {
    int h = hash(a, n);
    int j = h;
    do {
        if (!T[j].taken) {
            T[j].w = a;
            T[j].taken = true;
            return;
        }
        j = (j + 1) % n;
    } while (j != h);

}

int find(data T[], int n, int a) {
    int key = hash(a, n);
    int h = key;
    int counter = 0;
    while (T[key].taken) {
        if (T[key].w == a) counter++;
        key = (key + 1) % n;
        if (h == key) break;
    }
    return counter;
}


void display(data T[], int n) {
    for (int i = 0; i < n; i++) {
        if (T[i].taken)
            cout << T[i].w << " ";
        else cout << "0 ";
    }
    cout << endl;
}

int count_sum(int A[], int N, int sum) {
    int n = N + N / 2;
    data *T = new data[n];
    for (int i = 0; i < n; i++) {
        T[i].w = 0;
        T[i].taken = false;
    }
    int count = 0;
    for (int i = 0; i < N; i++) {
        int tmp = sum - A[i];
        count += find(T, n, tmp);
        insert(T, n, A[i]);
    }
    display(T, n);
    delete[]T;
    return count;

}

int main() {
    int N = 10;
    int A[N] = {3, 4, 4, 5, 3, 6, 4, 10, -2, 8};
    int sum = 8;
    return count_sum(A, N, sum);
}