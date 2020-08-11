#include <iostream>

using namespace std;

int forest(int A[], int n) {
    int *f = new int[n];
    for (int i = 0; i < n; i++) f[i] = 0;
    f[0] = A[0];
    f[1] = A[0] + A[1];
    f[2] = max(max(A[0] + A[1], A[0] + A[2]), A[1] + A[2]);

    for (int i = 3; i < n; i++) {
        f[i] = max(f[i - 1], max(A[i] + f[i - 2], A[i] + A[i - 1] + f[i - 3]));
    }

    for (int i = 0; i < n; i++) cout << f[i] << " ";
    cout << endl;

    return f[n - 1];
}


int main() {

    int n = 13;
    int A[n] = {1, 2, 100, 100, 2, 100, 1, 2, 100, 1, 1, 100, 2};
    return forest(A, n);
}