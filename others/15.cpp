#include <iostream>

using namespace std;

struct node {
    int w;
    node *next;
};

struct HuntingList {
    HuntingList *next; // nastepny element listy
    int predator; // numer pokemona, ktory poluje
    int prey;  // numer pokemona, na ktorego poluje
};

struct pokemon {
    int free;
    node *preys;
    node *predators;
};

node *insert(node *f, int val) {
    if (f == NULL) {
        f = new node;
        f->w == val;
        return f;
    }
    node *p = new node;
    p->w = val;
    p->next = f->next;
    f->next = p;
    return f;
}

bool hunters(pokemon **tab, int idx, int *result, int counter, int n) {
    int count = 0;
    node *p = tab[idx]->preys;

    while (p != NULL && count != 2) {
        counter++;
        p = p->next;
    }

    if (count != 2) return false;
    tab[idx]->free = true;
    result[counter++] = idx;
    p = tab[idx]->preys;

    while (p != NULL) {
        if (!tab[p->w]->free)
            hunters(tab, p->w, result, counter, n);
        p = p->next;
    }

    if (result[n - 1] != -1) return true;
    return false;
}

int *releaseThemAll(HuntingList *list, int n) {
    pokemon **tab = new pokemon *[n];
    int *result = new int[n];

    for (int i = 0; i < n; i++) {
        tab[i]->preys = tab[i]->predators = NULL;
        tab[i]->free = false;
        result[i] = -1;
    }
    HuntingList *tmp = list;
    while (tmp != NULL) {
        tab[tmp->predator]->preys = insert(tab[tmp->predator]->preys, tmp->prey);
        tab[tmp->prey]->predators = insert(tab[tmp->prey]->predators, tmp->predator);
        tmp = tmp->next;
    }
    int counter = 0;
    for (int i = 0; i < n; i++)
        if (tab[i]->preys == NULL) {
            tab[i]->free = true;
            result[counter++] = i;
        }
    for (int i = 0; i < n; i++) {
        if (!tab[i]->free)
            if (hunters(tab, i, result, counter, n))
                return true;
    }
    return NULL;
}


int main() {


}