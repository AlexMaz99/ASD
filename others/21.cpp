#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

struct slnode {
    int w;
    int level;
    slnode **next;
};

struct skiplist {
    slnode *first;
    slnode *last;
    int MAXLEVEL;
};

slnode *create_slnode(int key, int MAX) {
    int lvl = 1;
    while (lvl < MAX) lvl++;

    slnode *p = new slnode;
    p->w = key;
    p->level = lvl;

    p->next = new slnode *[lvl];
    for (int i = 0; i < lvl; i++)
        p->next[i] = NULL;

    return p;
}

skiplist *create_skiplist(skiplist *SL, int maxlevel) {
    SL = new skiplist;
    SL->MAXLEVEL = maxlevel;
    SL->first = create_slnode(-1000, maxlevel);
    SL->last = create_slnode(1000, maxlevel);
    for (int i = 0; i < maxlevel; i++) SL->first->next[i] = SL->last;
    return SL;
}

void insert(skiplist *SL, int key) {
    slnode *n = create_slnode(key, SL->MAXLEVEL);
    slnode *p = SL->first;

    for (int i = SL->MAXLEVEL - 1; i >= 0; i--) {
        while (p->next[i] != SL->last && key > p->next[i]->w) p = p->next[i];
        n->next[i] = p->next[i];
        p->next[i] = n;
    }
}

void deleted(skiplist *SL, int key) {
    slnode *p = SL->first;
    slnode *n;
    int i;

    for (i = SL->MAXLEVEL - 1; i >= 0; i--) {
        while (key > p->next[i]->w) p = p->next[i];
        if (key == p->next[i]->w) {
            n = p->next[i];
            break;
        }
    }

    for (i; i >= 0; i--) {
        while (p->next[i] != n) p = p->next[i];
        p->next[i] = n->next[i];
        n->next[i] = NULL;
    }

    delete n;

}

void print(skiplist *SL) {

    for (int lvl = SL->MAXLEVEL - 1; lvl >= 0; lvl--) {
        slnode *p = SL->first;
        cout << "level " << lvl << ": ";
        while (p->next[lvl] != SL->last) {
            cout << p->next[0]->w << " ";
            p = p->next[lvl];
        }
        cout << endl;
    }
}

int main() {
    srand(time(NULL));
    skiplist *SL = create_skiplist(SL, 5);

    insert(SL, 3);
    insert(SL, 17);
    insert(SL, 22);
    insert(SL, 6);
    insert(SL, 11);
    insert(SL, 1);
    insert(SL, 9);
    insert(SL, 16);
    insert(SL, 4);
    insert(SL, 10);
    insert(SL, 19);

    print(SL);
    cout << endl << endl;

    deleted(SL, 22);
    deleted(SL, 1);
    deleted(SL, 11);

    print(SL);
    return 0;
}