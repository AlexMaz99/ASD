#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

struct slnode {
    int w;
    slnode **next;
};
struct skiplist {
    slnode *first;
    int max_level;
};

slnode *create_slnode(int key, int level) {
    slnode *p = new slnode;
    p->w = key;
    p->next = new slnode *[level + 1];
    for (int i = 0; i < level + 1; i++)
        p->next[i] = NULL;
    return p;
}

skiplist *create_skiplist(skiplist *SL, int max_level) {
    SL->max_level = max_level;
    SL->first = create_slnode(0, max_level);
    return SL;
}

slnode *find(skiplist *SL, int key) {
    slnode *p = SL->first;
    for (int lvl = SL->max_level - 1; lvl >= 0; lvl--)
        while (key > p->next[lvl]->w)
            p = p->next[lvl];
    p = p->next[0];
    if (p->w == key) return p;
    return NULL;
}

int get_level(int max_level) {
    int lvl = 0;
    while (rand() % 10 < max_level && lvl < max_level) lvl++;
    return lvl;
}

void insert(skiplist *SL, int key) {
    slnode *p = SL->first;

    for (int lvl = SL->max_level - 1; lvl >= 0; lvl--)
        while (p->next[lvl] != NULL && key > p->next[lvl]->w)
            p = p->next[lvl];
    if (p->next[0] == NULL || p->next[0]->w != key) {
        p = SL->first;
        int lvl = get_level(SL->max_level);
        slnode *n = create_slnode(key, lvl);


        for (; lvl >= 0; lvl--) {
            while (p->next[lvl] != NULL && key > p->next[lvl]->w)
                p = p->next[lvl];
            n->next[lvl] = p->next[lvl];
            p->next[lvl] = n;
        }
    }
}

void print(skiplist *SL) {

    for (int lvl = SL->max_level; lvl >= 0; lvl--) {
        slnode *p = SL->first;
        cout << "level " << lvl << ": ";
        while (p->next[lvl] != NULL) {
            cout << p->next[0]->w << " ";
            p = p->next[lvl];
        }
        cout << endl;
    }
}

int main() {
    srand(time(NULL));
    skiplist *SL = new skiplist;
    SL = create_skiplist(SL, 5);
    insert(SL, 3);
    insert(SL, 17);
    insert(SL, 22);
    insert(SL, 6);
    insert(SL, 11);
    insert(SL, 1);
    insert(SL, 9);
    insert(SL, 16);
    insert(SL, 4);
    insert(SL, 11);
    insert(SL, 10);
    insert(SL, 19);

    print(SL);
}