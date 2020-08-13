#include <iostream>
#include <cmath>

using namespace std;

struct Cyclist {
    int id; //identyfikator rowerzysty
    int n_id; //identyfikator tego przed rowerzysta
};


int hash(int x) {
    return abs(x);
}

int find(Cyclist tab[], int n, int x) {
    int h = hash(x) % n;
    int j = h;

    while (tab[j].id != -1) {
        if (tab[j].n_id == x) return j;
        h = (h + 1) % n;
        if (j == h) return -1;
    }
}

int smallestGroup(Cyclist cyclist[], int n) {
    int s = 2 * n;
    Cyclist tab[s];

    for (int i = 0; i < s; i++)
        tab[i].id = tab[i].n_id = -1;

    for (int i = 0; i < n; i++) {
        int h = hash(cyclist[i].n_id) % s;
        while (tab[h].id != -1) h = (h + 1) % s;
        tab[h].id = cyclist[i].id;
        tab[h].n_id = cyclist[i].n_id;
    }


    for (int i = 0; i < s; i++) {
        cout << i << ": " << tab[i].n_id << " " << tab[i].id << endl;
    }

    int smallest = 1000;
    int counter = 0;

    for (int i = 0; i < s; i++) {
        if (tab[i].id != -1 && tab[i].n_id == -1) {
            counter = 1;
            Cyclist tmp = tab[i];
            while (true) {
                int h = find(tab, s, tmp.id);
                if (h == -1) break;
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