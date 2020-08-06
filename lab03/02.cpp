#include <iostream>

using namespace std;


void counting_sort(int A[], int N) {
    int B[N];
    int C[N * N];

    for (int i = 0; i < N * N; i++) C[i] = 0;
    for (int i = 0; i < N; i++) C[A[i]]++;
    for (int i = 1; i < N * N; i++) C[i] += C[i - 1];
    for (int i = N - 1; i >= 0; i--) {
        C[A[i]]--;
        B[C[A[i]]] = A[i];
    }
    for (int i = 0; i < N; i++) A[i] = B[i];
}

int main() {
    int n = 10;
    int A[n] = {99, 24, 1, 55, 79, 64, 23, 12, 5, 67};

    counting_sort(A, n);
    for (int i = 0; i < n; i++) cout << A[i] << " ";

    return 0;
}