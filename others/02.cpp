#include <iostream>

using namespace std;


int partition(int A[], int start, int end) {
    int x = A[end];
    int i = start - 1;
    for (int j = start; j < end; j++)
        if (A[j] < x)
            swap(A[++i], A[j]);
    swap(A[++i], A[end]);
    return i;

}

void quickselect(int A[], int start, int end, int indx) {
    if (start != end) {
        int i = rand() % (end - start + 1) + start;
        swap(A[i], A[end]);
        int mid = partition(A, start, end);
        if (mid > indx) quickselect(A, start, mid - 1, indx);
        else if (mid < indx) quickselect(A, mid + 1, end, indx);
    }
}

int SumBetween(int A[], int n, int from, int to) {
    quickselect(A, 0, n - 1, from);
    quickselect(A, from + 1, n - 1, to);
    int sum = 0;
    for (int i = from; i <= to; i++)
        sum += A[i];
    return sum;
}

int main() {
    int n = 10;
    int tab[n] = {5, 1, 8, 10, 2, 4, 6, 7, 12, 3};
    cout << SumBetween(tab, n, 4, 8);
}