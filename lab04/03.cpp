#include <iostream>

using namespace std;


bool more_than_half(int A[], int n) {
    int counter = 0;
    int max;

    for (int i = 0; i < n; i++) {
        if (counter == 0) max = i;
        if (A[i] == A[max]) counter++;
        else counter--;
    }

    counter = 0;

    for (int i = 0; i < n; i++)
        if (A[i] == A[max])
            counter++;

    return counter > n / 2;
}

int main() {
    int A[11] = {3, 2, 2, 3, 2, 3, 2, 3, 2, 3, 2};
    return more_than_half(A, 11);
}
