#include <iostream>

using namespace std;

//f-4-5-7-2-10-12
//f-9-3-4-5-6
//f-2-3-9-6-8

struct node {
    node *next;
    int w;
};

bool is_ascending(node *first) {
    int asc = 0;
    int desc = 0;
    while (asc + desc != 3 && first->next != NULL) {
        if (first->w < first->next->w) asc++;
        else desc++;
        first = first->next;
    }
    return asc > desc;
}

node *fixSortedList(node *L) {
    bool ascending = is_ascending(L);
    node *f = new node;
    f->next = L;
    L = f;

    if (ascending)
        while (f->next->next != NULL && f->next->w < f->next->next->w) f = f->next;
    else
        while (f->next->next != NULL && f->next->w > f->next->next->w) f = f->next;

    if (f != L && f->next->next->next != NULL) {
        if (ascending && f->next->w < f->next->next->next->w) f = f->next;
        else if (!ascending && f->next->w > f->next->next->next->w) f = f->next;
    }

    node *tmp = f->next;
    f->next = tmp->next;
    tmp->next = NULL;

    f = L;

    if (ascending)
        while (f->next != NULL && f->next->w < tmp->w) f = f->next;
    else
        while (f->next != NULL && f->next->w > tmp->w) f = f->next;

    tmp->next = f->next;
    f->next = tmp;
    f = L;
    L = L->next;

    delete f;
    return L;
}

void insert_last(node *&first, int n) {
    node *p = new node;
    p->w = n;
    p->next = NULL;
    if (first == NULL) {
        first = p;
        return;
    }
    node *r = first;
    while (r->next != NULL) r = r->next;
    r->next = p;
}

int main() {
    node *first = NULL;
    insert_last(first, 1);
    insert_last(first, 8);
    insert_last(first, 6);
    insert_last(first, 5);
    insert_last(first, 4);
    insert_last(first, 2);

    first = fixSortedList(first);

    while (first != NULL) {
        cout << first->w << " ";
        first = first->next;
    }
}
