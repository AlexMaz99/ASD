#include <iostream>

using namespace std;

int forest(int A[], int n) {
    int *f = new int[n];
    for (int i = 0; i < n; i++) f[i] = 0;
    f[0] = A[0];
    f[1] = A[0] + A[1];
    f[2] = A[2] + max(A[0], A[1]);

    int result = 0;
    int max1 = f[0];
    int max2 = max(f[0], f[1]);

    for (int i = 3; i < n; i++) {
        f[i] = A[i] + max(A[i - 1] + max1, max2);
        max1 = max(max1, f[i - 2]);
        max2 = max(max2, f[i - 1]);
    }

    for (int i = 0; i < n; i++) cout << f[i] << " ";
    cout << endl;
    max2 = max(max2, f[n - 1]);
    result = max2;

    return result;
}


int main() {

    int n = 13;
    int A[n] = {5, 10, 20, 1, 40, 3, 80, 20, 1, 2, 50, 100, 4};
    return forest(A, n);
}