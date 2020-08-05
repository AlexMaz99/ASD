#include <iostream>
#include <cmath>

using namespace std;


int count_inversion(int t[], int N) {
    int result = 0;
    for (int i = 0; i < N; i++) {
        for (int j = i + 1; j < N; j++) {
            if (t[i] > t[j]) result++;
        }
    }
    return result;
}

int merge(int t[], int first, int mid, int last) {
    int result = 0;
    int *tmp = new int[last - first + 1];
    int i = first;
    int j = mid + 1;
    int k = 0;

    while (i <= mid && j <= last) {
        if (t[i] < t[j]) tmp[k++] = t[i++];
        else {
            tmp[k++] = t[j++];
            result += mid + 1 - i;
        }
    }
    while (i <= mid) tmp[k++] = t[i++];
    while (j <= last) tmp[k++] = t[j++];

    for (int x = 0; x < last - first + 1; x++) t[first + x] = tmp[x];
    delete[]tmp;
    return result;
}


int merge_sort(int t[], int first, int last) {
    int mid;
    int result = 0;
    if (first != last) {
        mid = (first + last) / 2;
        result += merge_sort(t, first, mid);
        result += merge_sort(t, mid + 1, last);
        result += merge(t, first, mid, last);
    }
    return result;
}


int main() {
    int t[10] = {1, 2, 6, 4, 3, 5, 3, 9, 10, 1};
    cout << count_inversion(t, 10);
//    cout << merge_sort(t, 0, 10 - 1);
}