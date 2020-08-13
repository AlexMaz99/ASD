#include <iostream>

using namespace std;

const int MAX_LEVEL = 5;

struct SLNode {
    int value;
    int level;
    SLNode **next;
};

struct SkipList {
    SLNode *first;
    SLNode *last;
};

SLNode *createslnode(int key, int level) {
    SLNode *p = new SLNode;
    p->value = key;
    p->next = new SLNode *[level];
    for (int i = 0; i < level; i++)
        p->next[i] = NULL;
    return p;
}

void insert(SkipList res, SLNode *tmp) {
    SLNode *p = res.first;
    for (int i = tmp->level - 1; i >= 0; i--) {
        while (p->next[i] != res.last && tmp->value > p->next[i]->value) p = p->next[i];
        tmp->next[i] = p->next[i];
        p->next[i] = tmp;
    }
}

SkipList merge(SkipList A, SkipList B) {
    SkipList res;
    res.first = new SLNode;
    res.first->next = new SLNode *[MAX_LEVEL];
    res.first->level = res.last->level = MAX_LEVEL;
    res.first->value = -100000;
    res.last->value = 100000;
    res.last = new SLNode;
    res.last->next = new SLNode *[MAX_LEVEL];

    for (int i = 0; i < MAX_LEVEL; i++) {
        res.last->next[i] = NULL;
        res.first->next[i] = res.last;
    }

    SLNode *a = A.first->next[0];
    SLNode *b = B.first->next[0];
    SLNode *tmp;

    while (a != A.last && b != B.last) {
        if (a->value < b->value) {
            tmp = createslnode(a->value, a->level);
            a = a->next[0];
        } else {
            tmp = createslnode(b->value, b->level);
            b = b->next[0];
        }

        insert(res, tmp);
    }

    while (a != A.last) {
        tmp = createslnode(a->value, a->level);
        a = a->next[0];
        insert(res, tmp);
    }

    while (b != B.last) {
        tmp = createslnode(b->value, b->level);
        b = b->next[0];
        insert(res, tmp);
    }
}


int main() {


}