#include <iostream>

using namespace std;

struct data {
    int w;
    int ind;
    int tab;
};
struct tabs {
    int size;
    int t[7];
};

void heapify(data heap[], int i)  // O(logN)
{
    int l = 2 * i;
    int r = 2 * i + 1;
    int min = i;
    if (l <= heap[0].w && heap[l].w < heap[min].w) min = l;
    if (r <= heap[0].w && heap[r].w < heap[min].w) min = r;
    if (min != i) {
        swap(heap[min], heap[i]);
        heapify(heap, min);
    }
}

void build(data heap[]) //k-rozmiar kopca
{
    for (int i = heap[0].w / 2; i > 0; i--)
        heapify(heap, i);
}


int main() {
    int k = 3;
    int n = 9;
    tabs tab[k];
    tab[0].size = 2;
    tab[1].size = 3;
    tab[2].size = 4;

    tab[0].t[0] = 1;
    tab[0].t[1] = 4;
    tab[1].t[0] = 3;
    tab[1].t[1] = 9;
    tab[1].t[2] = 10;
    tab[2].t[0] = 2;
    tab[2].t[1] = 5;
    tab[2].t[2] = 8;
    tab[2].t[3] = 9;

    data heap[k + 1];
    for (int i = 0; i < k; i++) {
        heap[i + 1].w = tab[i].t[0];
        heap[i + 1].tab = i;
        heap[i + 1].ind = 0;
    }
    heap[0].w = k;
    heap[0].tab = -1;
    heap[0].ind = -1;


    build(heap);
    int m = 1;
    int result[n];
    result[0] = heap[1].w;

    while (m < n) {
        if (heap[1].ind + 1 < tab[heap[1].tab].size) {
            heap[1].w = tab[heap[1].tab].t[heap[1].ind + 1];
            heap[1].ind++;
        } else {
            heap[1] = heap[heap[0].w];
            heap[0].w--;
        }
        heapify(heap, 1);
        result[m] = heap[1].w;
        m++;
    }

    for (int i = 0; i < n; i++)
        cout << result[i] << " ";

    return 0;

}