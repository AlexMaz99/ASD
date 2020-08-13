#include <iostream>
#include <cmath>

using namespace std;


struct pivot {
    int i;
    int j;
};

pivot partition(int t[], int start, int end) {
    int x = t[end];
    int i = start - 1;
    pivot result;

    for (int j = start; j < end; j++) {
        if (t[j] < x) swap(t[++i], t[j]);
    }

    swap(t[++i], t[end]);
    result.i = i;
    x = t[i];

    for (int j = i + 1; j <= end; j++)
        if (t[j] == x) swap(t[++i], t[j]);

    result.j = i;
    return result;

}

void quicksort(int t[], int start, int end) {
    if (start < end) {
        pivot mid = partition(t, start, end);
        quicksort(t, start, mid.i - 1);
        quicksort(t, mid.j + 1, end);
    }
}

int main() {
    int n = 16;
    int t[n] = {3, 4, 5, 6, 6, 5, 4, 3, 5, 5, 5, 4, 3, 6, 3, 6};
    quicksort(t, 0, n - 1);
    for (int i = 0; i < n; i++) cout << t[i] << " ";
}