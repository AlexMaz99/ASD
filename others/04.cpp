#include <iostream>

using namespace std;

int partition(int t[], int start, int end) {
    int x = t[end];
    int i, j;
    i = start - 1;
    for (j = start; j < end; j++) {
        if (t[j] < x) {
            i++;
            swap(t[i], t[j]);
        }
    }
    swap(t[end], t[i + 1]);
    return i + 1;
}

void quicksort(int t[], int start, int end) {
    if (start < end) {
        int mid = partition(t, start, end);
        quicksort(t, start, mid - 1);
        quicksort(t, mid + 1, end);
    }
}

void sort_tab(int A[], int n) {
    int *even = new int[n / 2];
    int *odd = new int[n];
    int even_size = 0;
    int odd_size = 0;
    int i, j;

    for (i = 0; i < n; i++) {
        if (A[i] % 2 == 0) even[even_size++] = A[i];
        else odd[odd_size++] = A[i];
    }

    i = 0, j = 0;

    quicksort(even, 0, even_size - 1);

    while (i < even_size && j < odd_size) {
        if (even[i] < odd[j]) A[i + j] = even[i++];
        else A[i + j] = odd[j++];
    }

    while (i < even_size) A[i + j] = even[i++];
    while (j < odd_size) A[i + j] = odd[j++];

    delete[]even;
    delete[]odd;
}


int main() {
    int n = 16;
    int tab[n] = {10, 1, 3, 6, 5, 9, 11, 13, 15, 17, 8, 21, 23, 25, 2, 27};
    sort_tab(tab, n);
    for (int i = 0; i < n; i++) cout << tab[i] << " ";
}