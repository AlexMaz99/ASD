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

void insert(SkipList res, SLNode *tmp) {
    SLNode *p = res.first;

    for (int i = tmp->level - 1; i >= 0; i--) {
        while (p->next[i] != NULL && tmp->value > p->next[i]->value) p = p->next[i];
        tmp->next[i] = p->next[i];
        p->next[i] = tmp;
    }
}

SkipList merge(SkipList A, SkipList B) {
    SkipList res;
    res.first = new SLNode;
    res.first->next = new SLNode *[MAX_LEVEL];

    for (int i = 0; i < MAX_LEVEL; i++) {
        res.last = NULL;
        res.first->next[i] = res.last;
    }

    while (A.first->next[0] != A.last && B.first->next[0] != B.last) {
        SLNode *tmp;

        if (A.first->next[0]->value < B.first->next[0]->value) {
            tmp = A.first->next[0];
            for (int i = 0; i < tmp->level; i++) {
                A.first->next[i] = tmp->next[i];
                tmp->next[i] = NULL;
            }
        } else {
            tmp = B.first->next[0];
            for (int i = 0; i < tmp->level; i++) {
                B.first->next[i] = tmp->next[i];
                tmp->next[i] = NULL;
            }
        }

        insert(res, tmp);
    }

    if (A.first->next[0] != A.last) {
        for (int i = res.first->level - 1; i >= 0; i--) {
            SLNode *p = res.first;
            while (p->next[i] != NULL) p = p->next[i];
            p->next[i] = A.first->next[i];
        }
        res.last = A.last;
    }

    if (B.first->next[0] != B.last) {
        for (int i = res.first->level - 1; i >= 0; i--) {
            SLNode *p = res.first;
            while (p->next[i] != NULL) p = p->next[i];
            p->next[i] = B.first->next[i];
        }
        res.last = B.last;
    }
}


int main() {


}