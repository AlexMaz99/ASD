#include <iostream>

using namespace std;


bool exist_range(int t[], int n, int k) {
    int max = t[0];
    int min = t[0];

    for (int i = 1; i < n; i++) {
        if (t[i] < min) min = t[i];
        else if (t[i] > max) max = t[i];
    }

    int *counter = new int[max - min + 1];

    for (int i = 0; i < max - min + 1; i++) counter[i] = 0;
    for (int i = 0; i < n; i++) counter[t[i] - min]++;

    int count = 0;

    for (int i = 0; i < max - min + 1; i++) {
        if (counter[i] != 0) count++;
        else count = 0;
        if (count == k) {
            delete[]counter;
            return true;
        }
    }

    delete[]counter;
    return false;
}

int main() {
    int n = 20;
    int tab[n] = {-1, -2, -3, -4, 0, 46, 23, 12, 5, 6, 12, 4, 5, 6, 7, 8, 9, 10, -20, 6};
    return exist_range(tab, n, 6);
}