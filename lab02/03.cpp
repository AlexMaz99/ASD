int *heap_max;
int *heap_min;
#define max_size heap_max[0];
#define min_size heap_min[0];

int parent(int i) {
    return i / 2;
}

int left(int i) {
    return i * 2;
}

int right(int i) {
    return i * 2 + 1;
}

void heapify_min(int *heap_min, int i)  // O(logN)
{
    int l = left(i);
    int r = right(i);
    int min = i;
    if (l <= min_size && heap_min[l] < heap_min[min]) min = l;
    if (r <= min_size && heap_min[r] < heap_min[min]) min = r;
    if (min != i) {
        swap(heap_min[min], heap_min[i]);
        heapify_min(heap_min, min);
    }
}

void heapify_max(int *heap_max, int i)  // O(logN)
{
    int l = left(i);
    int r = right(i);
    int max = i;
    if (l <= max_size && heap_max[l] > heap_max[max]) max = l;
    if (r <= max_size && heap_max[r] > heap_max[max]) max = r;
    if (max != i) {
        swap(heap_max[max], heap_max[i]);
        heapify_max(heap_max, max);
    }
}

void insert_max(int *heap_max, int k) {
    max_size ++;
    heap_max[max_size] = k;
    int i = max_size;
    while (i > 1 && heap_max[i] > heap_max[i / 2]) {
        swap(heap_max[i], heap_max[i / 2]);
        i = i / 2;
    }
}

void insert_min(int *heap_min, int k) {
    min_size ++;
    heap_min[min_size] = k;
    int i = min_size;
    while (i > 1 && heap_min[i] < heap_min[i / 2]) {
        swap(heap_min[i], heap_min[i / 2]);
        i = i / 2;
    }
}

void balance(int *max_heap, int *min_heap) {
    if (max_size == min_size || abs(max_size
    -min_size) == 1) return;
    if (max_size > min_size){
        insert_min(min_heap, max_heap[1]);
        swap(max_heap(1), max_heap(max_size));
        max_size --;
        heapify_max(max_heap, 1);
    }
    else{
        insert_max(max_heap, min_heap[1]);
        swap(min_heap(1), min_heap(min_size));
        min_size --;
        heapify_min(min_heap, 1);
    }
}

int get_median(int *max_heap, int *min_heap) {
    if (!min_size && !max_size) return 0;
    if (max_size == min_size) return (max_heap[1] + min_heap[1]) / 2;
    return max_size > min_size ? max_heap[1] : min_heap[1];
}

void insert(int *max_heap, int *min_heap, int k) {
    int median = get_median(max_heap, min_heap);
    if (k > median) insert_min(min_heap, k);
    else insert_max(max_heap, k);
    balance(max_heap, min_heap);
}