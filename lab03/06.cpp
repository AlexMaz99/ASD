#include <iostream>

using namespace std;


void merge(int t[], int start, int mid, int end) {
    int *tmp = new int[end - start + 1];
    int i = start;
    int j = mid + 1;
    int k = 0;

    while (i <= mid && j <= end) {
        if (t[i] < t[j]) tmp[k++] = t[i++];
        else tmp[k++] = t[j++];
    }
    while (i <= mid) tmp[k++] = t[i++];
    while (j <= end) tmp[k++] = t[j++];

    k = 0;

    for (int m = start; m <= end; m++)
        t[m] = tmp[k++];

    {}
    delete tmp;
}

// O(NlogN)
void MergeSort(int t[], int start, int end) {
    int mid;
    if (start != end) {
        mid = (start + end) / 2;
        MergeSort(t, start, mid);
        MergeSort(t, mid + 1, end);
        merge(t, start, mid, end);
    }
}


int partition(int t[], int start, int end) {
    int x = t[end];
    int i, j;
    i = start - 1;
    for (j = start; j < end; j++) {
        if (t[j] < x)
            swap(t[++i], t[j]);
    }
    swap(t[end], t[++i]);
    return i;
}

// O(NlogN)
void QuickSort(int t[], int start, int end) {
    if (start < end) {
        int i = rand() % (end - start + 1) + start;
        swap(t[i], t[end]);
        int mid = partition(t, start, end);
        quicksort(t, start, mid - 1);
        quicksort(t, mid + 1, end);
    }
}


//O(N)
void CountingSort(int A[], int N, int k) // wartosci elementow w tablicy sa od 0 do k-1
{
    int B[N];
    int C[k];
    for (int i = 0; i < k; i++) C[i] = 0;
    for (int i = 0; i < N; i++) C[A[i]]++;
    for (int i = 1; i < k; i++) C[i] += C[i - 1];

    for (int i = N - 1; i >= 0; i--) B[--C[A[i]]] = A[i];
    for (int i = 0; i < N; i++) A[i] = B[i];
}


int digit(int n, int pos) {
    while (pos != 0) {
        n /= 10;
        pos--;
    }
    return n % 10;
}

void sort_by_position(int tab[], int n, int pos) {
    int k = 10;
    int *counters = new int[k];
    int *result = new int[n];

    for (int i = 0; i < k; i++) counters[i] = 0;
    for (int i = 0; i < n; i++) counters[digit(tab[i], pos)]++;
    for (int i = 1; i < k; i++) counters[i] += counters[i - 1];
    for (int i = n - 1; i >= 0; i--) result[--counters[digit(tab[i], pos)]] = tab[i];
    for (int i = 0; i < n; i++) tab[i] = result[i];
    delete[] counters;
    delete[] result;
}


//O(N)
void RadixSort(int tab[], int n, int length) //legth to dlugosc najdluzszej liczby
{
    for (int i = 0; i < length; i++)
        sort_by_position(tab, n, i);
}


int main() {
    int N = 10;
    int t[N] = {11, 25, 47, 28, 12, 13, 45, 11, 15, 45};

    QuickSort(t, 0, N - 1);
    MergeSort(t, 0, N - 1);
    CountingSort(t, N, 16);
    RadixSort(t, N, 2);

    for (int i = 0; i < N; i++) cout << t[i] << " ";
}