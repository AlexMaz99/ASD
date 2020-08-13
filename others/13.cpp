#include <iostream>

using namespace std;

//1-blue
//0-green

struct Pupil {
    int group;
    Pupil *next;
};

int distanceToIdeal(Pupil *L, int n) {
    int ind = 0;
    for (int i = 0; i < 2 * n; i++) {
        if (L->group == 0) ind += i;
        L = L->next;
    }
    return 2 * (ind - (n - 1) * n / 2);
}

void insert_last(Pupil *&first, int n)
{
    Pupil *p = new Pupil;
    p->group = n;
    p->next = NULL;
    if (first == NULL) first = p;
    else {
        Pupil *r = first;
        while (r->next != NULL) {
            r = r->next;
        }
        r->next = p;
    }
}

int main() {
    Pupil *first = new Pupil;
    first = NULL;

    insert_last(first, 0);
    insert_last(first, 1);
    insert_last(first, 0);
    insert_last(first, 1);
    insert_last(first, 0);
    insert_last(first, 1);
    insert_last(first, 1);
    insert_last(first, 0);

    cout << distanceToIdeal(first, 4);

    return 0;
}