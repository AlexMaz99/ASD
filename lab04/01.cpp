#include <iostream>

using namespace std;

bool indexes_exist(int A[], int N, int x) {
    int i = 0;
    int j = N - 1;

    while (i < j) {
        if (A[i] + A[j] == x) {
            cout << i << " " << j;
            return true;
        } else if (A[i] + A[j] > x) j--;
        else i++;
    }
    return false;
}

int main() {
    int A[10] = {1, 3, 5, 6, 10, 12, 16, 25, 40, 50};
    int x;
    cin >> x;
    return indexes_exist(A, 10, x);
}
