int parent(int i) {
    return i / 2;
}

int left(int i) {
    return i * 2;
}

int right(int i) {
    return i * 2 + 1;
}

#define size t[0];

void heapify(int t[], int i)  // O(logN)
{
    int l = left(i);
    int r = right(i);
    int max = i;
    if (l <= size && t[l] > t[max]) max = l;
    if (r <= size && t[r] > t[max]) max = r;
    if (max != i) {
        swap(t[max], t[i]);
        heapify(t, max);
    }
}

void built(int t[]) // O(N)
{
    for (int i = size/2; i > 0; i--)
    heapify(t, i);
}

void heapsort(int t[]) // O(NlogN)
{
    built(t);
    for (int i = size; i > 1; i--)
    {
        swap(t[1], t[i])
        size --;
        heapify(t, 1);
    }
}