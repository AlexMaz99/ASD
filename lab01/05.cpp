#include <iostream>

using namespace std;

bool pair_exist(int t[], int N, int &a, int &b, int x) {
    int i = 0, j = N - 1;
    while (i < j) {
        if (t[i] + t[j] > x) j--;
        else if (t[i] + t[j] < x) i++;
        else {
            a = t[i];
            b = t[j];
            return true;
        }
    }
    return false;
}

int main() {
    int t[10] = {3, 5, 6, 8, 10, 11, 13, 19, 100, 210};
    int a, b;
    cout << pair_exist(t, 10, a, b, 106) << endl;
    cout << a << " " << b;
    return 0;
}