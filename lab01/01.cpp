void bubble_sort(int *t, int N) {
    bool sorted;
    for (int i = 0; i < N; i++) {
        sorted = true;
        for (int j = 0; j < N - i - 1; j++) {
            if (t[j] > t[j + 1]) {
                swap(t[j], t[j + 1]);
                sorted = false;
            }
        }
        if (sorted) break;
    }
}

void insort(int *t, int N) {
    for (int i = 1; i < N; i++) {
        int k = i;
        while (k > 0 && t[k - 1] > t[k]) {
            int tmp = t[k];
            t[k] = t[k - 1];
            t[k - 1] = tmp;
            k--;
        }
    }
}

void insort2(int *t, int N) {
    for (int i = 1; i < N; i++) {
        int k = t[i];
        int j = i - 1;
        while (j >= 0 && t[j] > k) {
            t[j + 1] = t[j];
            j--;
        }
        t[j + 1] = k;
    }
}

void selection_sort(int *t, int N) {
    for (int i = 1; i < N; i++) {
        int min = i - 1;
        for (int j = i; j < N; j++)
            if (t[j] < t[min]) min = j;

        swap(t[min], t[i - 1]);
    }
}