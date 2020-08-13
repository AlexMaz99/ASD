#include <iostream>

using namespace std;

//A[16]={1, 2, 3, 5, 8, 9, 12, 15, 16, 18, 20, 22, 24, 25, 28, 30}
//8 9 12 15   24 25 28 30   1 2 3 5   16 18 20 22

int key(int i, int tab[], int n) {
    return tab[i * n] + tab[i * n + n - 1];
}

int partition(int t[], int p, int r, int n, int A[]) {
    int x = t[r];
    int i = p - 1;
    for (int j = p; j < r; j++) {
        if (key(t[j], A, n) < key(x, A, n)) {
            i++;
            swap(t[i], t[j]);
        }
    }
    swap(t[r], t[i + 1]);
    return i + 1;
}

void quicksort(int t[], int p, int r, int n, int A[]) {
    if (p < r) {
        int q = partition(t, p, r, n, A);
        quicksort(t, p, q - 1, n, A);
        quicksort(t, q + 1, p, n, A);
    }
}

void sortNNsequence(int A[], int n) {
    int *result = new int[n * n];
    int *tab = new int[n];

    for (int i = 0; i < n; i++) tab[i] = i;

    quicksort(tab, 0, n - 1, n, A);

    for (int i = 0; i < n; i++) cout << tab[i] << " ";
    cout << endl;

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            result[i * n + j] = A[tab[n - i - 1] * n + n - 1 - j];

    for (int i = 0; i < n * n; i++)
        A[i] = result[i];

    delete[]result;
    delete[]tab;
}

int main() {
    int n = 16;
    int A[n] = {8, 9, 12, 15, 24, 25, 28, 30, 1, 2, 3, 5, 16, 18, 20, 22};

    sortNNsequence(A, 4);

    for (int i = 0; i < n; i++)
        cout << A[i] << " ";
}