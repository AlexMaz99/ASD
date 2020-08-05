#include <iostream>

using namespace std;


struct node {
    int w;
    node *next;
};


node *divide(node *first) {
    if (first == NULL || first->next == NULL) return NULL;
    node *fast = first->next;
    node *slow = first;

    while (fast != NULL) {
        fast = fast->next;
        if (fast != NULL) {
            slow = slow->next;
            fast = fast->next;
        }
    }
    first = slow->next;
    slow->next = NULL;
    return first;
}

node *merge(node *f1, node *f2) {

    if (f1 == NULL) return f2;
    if (f2 == NULL) return f1;
    node *f = new node;
    node *first = f;


    while (f1 != NULL && f2 != NULL) {
        if (f1->w < f2->w) {
            f->next = f1;
            f1 = f1->next;
        } else {
            f->next = f2;
            f2 = f2->next;
        }
        f = f->next;
    }
    if (f1 != NULL) f->next = f1;
    if (f2 != NULL) f->next = f2;
    f = first;
    first = first->next;
    delete f;
    return first;
}

node *merge_sort(node *first) {
    if (first == NULL || first->next == NULL) return first;
    node *f2 = divide(first);
    return merge(merge_sort(first), merge_sort(f2));
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

    insert_last(first, 9);
    insert_last(first, 4);
    insert_last(first, 2);
    insert_last(first, 1);
    insert_last(first, 3);

    first = merge_sort(first);
    while (first != NULL) {
        cout << first->w << " ";
        first = first->next;
    }

    return 0;
}