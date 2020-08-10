#include <iostream>

using namespace std;

struct node {
    int w;
    node *right;
    node *left;
    int l; //ile elementow jest w lewym poddrzewie
};

int find_i(node *p, int i) {
    if (p == NULL) return -1;
    if (i == p->l) return p->w;
    if (i < p->l) return find_i(p->left, i);
    return find_i(p->right, i - p->l - 1);
}

int main() {
    node *f = new node;
    node *a = new node;
    node *b = new node;
    node *c = new node;
    node *d = new node;
    node *e = new node;
    node *i = new node;
    node *g = new node;
    node *h = new node;
    f->w = 4;
    a->w = 0;
    b->w = 1;
    c->w = 3;
    d->w = 2;
    e->w = 10;
    g->w = 8;
    h->w = 12;
    i->w = 9;

    a->right = a->left = b->right = c->left = c->right = g->left = i->right = i->left = h->right = h->left = NULL;
    f->right = e;
    e->right = h;
    e->left = g;
    g->right = i;
    f->left = d;
    d->right = c;
    d->left = b;
    b->left = a;
    a->l = c->l = i->l = g->l = h->l = 0;
    b->l = 1;
    d->l = e->l = 2;
    f->l = 4;

    for (int i = 1; i < 10; i++)
        cout << i << ". " << find_i(f, i - 1) << endl;
}