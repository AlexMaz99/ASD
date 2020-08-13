#include <iostream>

using namespace std;

struct node {
    double w;
    node *next;
};

void insert_last(node *&first, double n) {
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

void insert_to_list(node *&first, node *n) {
    if (first == NULL) first = n;
    else {
        while (first->next != NULL) first = first->next;
        first->next = n;
    }
}

void insert(node *first, node *el) {
    while (first->next != NULL && first->next->w < el->w) first = first->next;
    el->next = first->next;
    first->next = el;
}

void sort(node *&first) {
    if (first == NULL || first->next == NULL) return;
    node *f = new node;
    f->next = first;
    first = f;

    node *s = new node;
    s->next = NULL;

    while (first->next != NULL) {
        f = first->next;
        first->next = f->next;
        f->next = NULL;
        insert(s, f);
    }

    node *p = first;
    first = s->next;
    delete p;
    s->next = NULL;
    delete s;
}

void Sort(node *first) {
    node *B[10];
    node *tmp;

    for (int i = 0; i < 10; i++) B[i] = NULL;

    while (first->next != NULL) {
        tmp = first->next;
        first->next = tmp->next;
        tmp->next = NULL;
        insert_to_list(B[(int) (tmp->w)], tmp);
    }


    for (int i = 0; i < 10; i++) sort(B[i]);

    for (int i = 0; i < 10; i++) {
        while (B[i] != NULL) {
            first->next = B[i];
            B[i] = B[i]->next;
            first = first->next;
        }
    }

    delete[]B;
}

int main() {
    node *first = NULL;

    insert_last(first, 1);
    insert_last(first, 9.52);
    insert_last(first, 8.61);
    insert_last(first, 6.24);
    insert_last(first, 7.23);
    insert_last(first, 6.1);
    insert_last(first, 7.5);
    insert_last(first, 2.56);
    insert_last(first, 7.4);
    insert_last(first, 9.999);
    insert_last(first, 4.78);
    insert_last(first, 0.001);
    insert_last(first, 1.12);
    insert_last(first, 8.61);
    insert_last(first, 5.55);

    node *f = new node;
    f->next = first;
    first = f;

    Sort(first);

    first = first->next;
    while (first != NULL) {
        cout << first->w << "    ";
        first = first->next;
    }
}