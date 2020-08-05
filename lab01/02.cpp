#include <iostream>
#include <cmath>

using namespace std;

struct node {
    int w;
    node *next;
};

void insert(node *first, node *n) {
    while (first->next != NULL && first->next->w < n->w) first = first->next;
    n->next = first->next;
    first->next = n;
}

node *insort(node *first) {
    if (first == NULL || first->next == NULL) return first;
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
    delete first;
    node *p = s;
    s = s->next;
    delete p;
    return s;
}

node *find_max(node *first) {
    node *max = first;
    first = first->next;
    while (first->next != NULL) {
        if (max->next->w < first->next->w) max = first;
        first = first->next;
    }
    first = max->next;
    max->next = first->next;
    first->next = NULL;
    return first;

}

node *selection_sort(node *first) {
    if (first == NULL || first->next == NULL) return first;
    node *f = new node;
    f->next = first;
    first = f;

    node *s = new node;
    s->next = NULL;

    while (f->next != NULL) {
        node *tmp = find_max(first);
        tmp->next = s->next;
        s->next = tmp;
    }
    f = s;
    s = s->next;
    delete f;
    delete first;
    return s;
}

void insert_last(node *&first, int n) {
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

    insert_last(first, 2);
    insert_last(first, 8);
    insert_last(first, 6);
    insert_last(first, 1);
    insert_last(first, 3);
    insert_last(first, 5);

    first = insort(first);
//    first = selection_sort(first);


    while (first != NULL) {
        cout << first->w << " ";
        first = first->next;
    }

    return 0;
}