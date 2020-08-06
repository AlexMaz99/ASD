#include <iostream>

using namespace std;

struct point {
    int w;
    int index;
};

struct interval {
    int l;
    int r;
};

int partition(point t[], int start, int end) {
    int x = t[end].w;
    int i, j;
    i = start - 1;
    for (j = start; j < end; j++) {
        if (t[j].w < x) {
            i++;
            swap(t[i], t[j]);
        }
    }
    swap(t[end], t[i + 1]);
    return i + 1;
}

void quicksort(point t[], int start, int end) {
    if (start < end) {
        int mid = partition(t, start, end);
        quicksort(t, start, mid - 1);
        quicksort(t, mid + 1, end);
    }
}

interval biggest_interval(interval t[], int n) {
    point start[n];
    point end[n];
    int indexes[n];
    for (int i = 0; i < n; i++) {
        start[i].w = t[i].l;
        end[i].w = t[i].r;
        start[i].index = end[i].index = i;
    }
    quicksort(start, 0, n - 1);
    quicksort(end, 0, n - 1);

    for (int i = 0; i < n; i++)
        indexes[start[i].index] = i;

    int max = -1, j;
    for (int i = 0; i < n; i++) {
        if (max < i - indexes[end[i].index]) {
            max = i - indexes[end[i].index];
            j = i;
        }
    }
    interval result;
    result.l = start[indexes[end[j].index]].w;
    result.r = end[j].w;
    return result;
}

int main() {
    int n = 6;
    interval t[n];
    for (int i = 0; i < n; i++) cin >> t[i].l >> t[i].r;
    interval result = biggest_interval(t, n);

    cout << result.l << " " << result.r;

    return 0;
}