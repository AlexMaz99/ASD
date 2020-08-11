#include <iostream>
#include <stack>

using namespace std;

int partition(int t[], int start, int end) {
    int x = t[end];
    int i, j;
    i = start - 1;
    for (j = start; j < end; j++) {
        if (t[j] < x) {
            i++;
            swap(t[i], t[j]);
        }
    }
    swap(t[end], t[i + 1]);
    return i + 1;
}

void quicksort(int t[], int start, int end) {
    stack<int> S;
    S.push(start);
    S.push(end);
    while (!S.empty()) {
        int right = S.top();
        S.pop();
        int left = S.top();
        S.pop();
        int mid = partition(t, left, right);
        cout << left << " " << mid << " " << right << endl;
        if (left < mid) {
            S.push(left);
            S.push(mid - 1);
        }
        if (mid + 1 < right) {
            S.push(mid + 1);
            S.push(right);
        }
    }
}

int main() {
    int t[10] = {9, 8, 4, 1, 12, 32, 13, 22, 5, 11};
    quicksort(t, 0, 9);
    for (int i = 0; i < 10; i++)
        cout << t[i] << " ";
    return 0;
}