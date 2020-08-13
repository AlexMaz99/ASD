#include <iostream>

using namespace std;

int goodThief(int A[], int n) {
    int *f = new int[n];
    for (int i = 0; i < n; i++) f[i] = 0;
    f[0] = A[0];
    f[1] = A[1];
    int max_profit = A[0];
    int result = 0;

    for (int i = 2; i < n; i++) {
        f[i] = max_profit + A[i];
        max_profit = max(max_profit, f[i - 1]);
    }

    // for (int i=0; i<n; i++) cout<<f[i]<<" ";
    // cout<<endl;

    max_profit = max(max_profit, f[n - 1]);
    result = max_profit;

    for (int i = n - 1; i >= 0 && max_profit != 0; i--) {
        while (i > 0 && max_profit != f[i]) {
            i--;
        }
        cout << A[i] << " ";
        max_profit -= A[i];
    }

    return result;
}

int main() {
    int n = 10;
    int A[n] = {1, 10, 3, 4, 20, 25, 1, 2, 90, 6};
    return goodThief(A, n);
}