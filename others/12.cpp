#include <iostream>
#include <cmath>

using namespace std;

/*
Przyklad:
{-1,-1,0,0,1,1,1} wynik=2;
{1,1,1} wynik=1;
*/

int findDistrict(int A[], int n) {
    int i = 0;
    int j = n - 1;
    int prev = -1;
    int counter = 0;

    while (i <= j) {
        if (abs(A[i]) < abs(A[j])) {
            if (abs(A[j]) != prev) {
                prev = abs(A[j]);
                counter++;
            }
            j--;
        } else {
            if (abs(A[i]) != prev) {
                prev = abs(A[i]);
                counter++;
            }
            i++;
        }
    }

    return counter;
}

int main() {
    int n = 10;
    int A[n] = {-3, -2, -1, -1, 0, 0, 1, 1, 1, 5};
    cout << findDistrict(A, n);
}
