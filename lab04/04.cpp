#include <iostream>

using namespace std;


int binary_search(int tab[], int x, int start, int end) {
    int i = (start + end) / 2;
    if (tab[i] < x) return binary_search(tab, x, i + 1, end);
    else if (tab[i] > x) return binary_search(tab, x, start, i - 1);
    return i;
}

int main() {
    int n = 12;
    int tab[n] = {5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16};
    cout << binary_search(tab, 6, 0, n - 1);
}