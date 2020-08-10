#include <iostream>

using namespace std;

struct node {
    int w;
    node *right;
    node *left;
    int l; //ile elementow jest w lewym poddrzewie
};

int find_n(node *p, int n, int &pos) {
    if (p == NULL) return -1;
    if (n == p->w) return pos + p->l + 1;
    if (n < p->w) return find_n(p->left, n, pos);
    return find_n(p->right, n, pos += p->l + 1);
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

    int pos = 0;
    cout << find_n(f, 12, pos) << endl;
}