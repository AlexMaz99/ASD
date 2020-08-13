#include <iostream>

using namespace std;

struct Cyclist {
    int id; //identyfikator rowerzysty
    int n_id; //identyfikator tego przed rowerzysta
};

struct BetterCyclist {
    int id; //identyfikator rowerzysty
    int n_before_id; //identyfikator tego przed rowerzysta
    int n_after_id; //identyfikator tego za rowerzysta
};

int hash(int x) {
    return x;
}

int smallestGroup(Cyclist cyclist[], int n) {
    int s = 2 * n;
    BetterCyclist tab[s];

    for (int i = 0; i < s; i++)
        tab[i].id = tab[i].n_after_id = tab[i].n_before_id = -1;

    for (int i = 0; i < n; i++) {
        int h = hash(cyclist[i].id) % s;
        while (tab[h].id != -1) h = (h + 1) % s;
        tab[h].id = cyclist[i].id;
        tab[h].n_before_id = cyclist[i].n_id;
    }

    for (int i = 0; i < n; i++) {
        if (cyclist[i].n_id != -1) {
            int h = hash(cyclist[i].n_id) % s;
            while (tab[h].id != cyclist[i].n_id) h = (h + 1) % s;
            tab[h].n_after_id = cyclist[i].id;
        }
    }

    for (int i = 0; i < s; i++) {
        cout << i << ": " << tab[i].n_before_id << " " << tab[i].id << " " << tab[i].n_after_id << endl;
    }

    int smallest = 1000;
    int counter = 0;

    for (int i = 0; i < s; i++) {
        if (tab[i].id != -1 && tab[i].n_before_id == -1) {
            counter = 1;
            BetterCyclist tmp = tab[i];
            while (tmp.n_after_id != -1) {
                int h = hash(tmp.n_after_id) % s;
                while (tab[h].id != tmp.n_after_id) h = (h + 1) % s;
                counter++;
                tmp = tab[h];
            }
            if (counter < smallest) smallest = counter;
        }
    }

    return smallest;
}

void insert1(Cyclist cyclist[], int i, int id, int nid) {
    cyclist[i].id = id;
    cyclist[i].n_id = nid;
}

int main() {
    int n = 10;
    Cyclist cyclist[n];

    insert1(cyclist, 0, 12, -1);
    insert1(cyclist, 1, 10, 8);
    insert1(cyclist, 2, 8, 5);
    insert1(cyclist, 3, 6, 19);
    insert1(cyclist, 4, 5, -1);
    insert1(cyclist, 5, 19, -1);
    insert1(cyclist, 6, 3, 6);
    insert1(cyclist, 7, 4, 14);
    insert1(cyclist, 8, 14, 3);
    insert1(cyclist, 9, 1, 12);

    return smallestGroup(cyclist, n);
}