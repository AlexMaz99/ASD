#include <iostream>

using namespace std;

int partition(double A[], int start, int end) {
    int x = A[end];
    int i = start - 1;

    for (int j = start; j < end; j++)
        if (A[j] < x)
            swap(A[++i], A[j]);
    swap(A[++i], A[end]);

    return i;

}

void quickselect(double A[], int start, int end, int indx) {
    int mid = partition(A, start, end);
    if (mid > indx) quickselect(A, start, mid - 1, indx);
    else if (mid < indx) quickselect(A, mid + 1, end, indx);
}

double AverageScore(double A[], int n, int lowest, int highest) {
    quickselect(A, 0, n - 1, lowest);
    quickselect(A, lowest + 1, n - 1, n - highest - 1);

    double sum = 0.0;

    for (int i = lowest; i < n - highest; i++)
        sum += A[i];

    return sum / (n - highest - lowest);
}

int main() {
    int n = 10;
    double tab[n] = {5, 1, 8, 10, 2, 4, 6, 7, 12, 3};
    cout << AverageScore(tab, n, 2, 4);
}