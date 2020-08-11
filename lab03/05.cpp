#include <iostream>

using namespace std;

struct node {
    float w;
    node *next;
};

void insert_last(node *first, float n) {
    node *p = new node;
    p->w = n;
    p->next = NULL;

    while (first->next != NULL) first = first->next;
    first->next = p;
}

void insert(node *first, node *el) {
    while (first->next != NULL && first->next->w < el->w) first = first->next;
    el->next = first->next;
    first->next = el;
}

void sort(node *&first) {
    if (first->next == NULL) return;
    node *f = first;

    node *s = new node;
    s->next = NULL;

    while (first->next != NULL) {
        f = first->next;
        first->next = f->next;
        f->next = NULL;
        insert(s, f);
    }
    node *p = first;
    first = s;
    delete p;
}

void bucketSort(float A[], int N, int k) {
    node *B[k];
    for (int i = 0; i < k; i++) {
        B[i] = new node;
        B[i]->next = NULL;
    }
    for (int i = 0; i < N; i++) insert_last(B[int(k * A[i])], A[i]);

    for (int i = 0; i < k; i++) sort(B[i]);

    int j = 0;
    for (int i = 0; i < k; i++) {
        while (B[i]->next != NULL) {
            node *tmp = B[i]->next;
            A[j++] = tmp->w;
            B[i]->next = tmp->next;
            tmp->next = NULL;
            delete tmp;
        }
        delete B[i];
    }


}

int main() {
    int N = 10;
    float t[N] = {0.897, 0.565, 0.656, 0.1234, 0.665, 0.3434, 0.352, 0.312, 0.85, 0.623};

    bucketSort(t, N, N);

    for (int i = 0; i < N; i++) cout << t[i] << " ";
    return 0;
}