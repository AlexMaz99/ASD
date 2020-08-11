#include <iostream>

using namespace std;


int partition_Hoare(int t[], int start, int end) {
    int x = t[start];
    int i = start - 1;
    int j = end + 1;
    while (true) {
        do j--; while (t[j] > x);
        do i++; while (t[i] < x);
        if (i < j) swap(t[i], t[j]);
        else return j;
    }
}


void quicksort(int t[], int start, int end) {
    if (start < end) {
        int mid = partition_Hoare(t, start, end);
        quicksort(t, start, mid);
        quicksort(t, mid + 1, end);
    }
}

int main() {
    int t[10] = {9, 8, 4, 1, 12, 32, 13, 22, 5, 11};
    quicksort(t, 0, 9);
    for (int i = 0; i < 10; i++)
        cout << t[i] << " ";
    return 0;
}