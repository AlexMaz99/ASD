#include <iostream>

using namespace std;

struct node {
    int w;
    node *next;
};

node *get_last(node *current) {
    while (current != NULL && current->next != NULL)
        current = current->next;
    return current;
}

node *partition(node *first, node *last, node **new_first, node **new_last) {
    node *current = first;
    node *prev = NULL;
    node *pivot = last;
    node *tail = pivot;
    while (current != pivot) {
        if (current->w < pivot->w) {
            if ((*new_first) == NULL) (*new_first) = current;
            prev = current;
            current = current->next;
        } else {
            if (prev != NULL) prev->next = current->next;
            node *tmp = current->next;
            current->next = NULL;
            tail->next = current;
            tail = current;
            current = tmp;
        }
    }
    if ((*new_first) == NULL) (*new_first) = pivot;
    (*new_last) = tail;
    return pivot;
}

node *quicksort_rec(node *first, node *last) {
    if (first == NULL || first == last) return first;
    node *new_first = NULL, *new_last = NULL;
    node *pivot = particion(first, last, &new_first, &new_last);

    if (new_first != pivot) {
        node *tmp = new_first;
        while (tmp->next != pivot) tmp = tmp->next;
        tmp->next = NULL;
        new_first = quicksort_rec(new_first, tmp);
        tmp = get_last(new_first);
        tmp->next = pivot;

    }
    pivot->next = quicksort_rec(pivot->next, new_last);
    return new_first;
}

void quicksort(node *&first) {
    node *last = first;
    while (last->next != NULL) last = last->next;
    first = quicksort_rec(first, last);
}

void insert_last(node *&first, int n) //dodawanie elementu na koniec listy
{
    node *p = new node;
    p->w = n;
    p->next = NULL;
    if (first == NULL) first = p;
    else {
        node *r = first;
        while (r->next != NULL) {
            r = r->next;
        }
        r->next = p;
    }
}

int main() {
    node *first = new node;
    first = NULL;


    insert_last(first, 15);
    insert_last(first, 8);
    insert_last(first, 25);
    insert_last(first, 6);
    insert_last(first, 10);
    quicksort(first);
    while (first != NULL) {
        cout << first->w << " ";
        first = first->next;
    }

    return 0;
}