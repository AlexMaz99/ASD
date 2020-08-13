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


void hunters(pokemon *tab, int *result, int n, int &counter, int idx) {
    int count = 0;
    node *p = tab[idx].preys;
    while (p != NULL && count < 2) {
        if (tab[p->w].free) counter++;
        p = p->next;
    }
    if (count < 2) return;

    tab[idx].free = true;
    result[counter++] = idx;
    p = tab[idx].predators;

    while (p != NULL) {
        if (!tab[p->w].free) hunters(tab, result, n, counter, p->w);
        p = p->next;
    }
}

int *releaseThemAll(HuntingList *list, int n) {
    pokemon *tab = new pokemon[n];
    int *result = new int[n];

    for (int i = 0; i < n; i++) {
        tab[i].preys = tab[i].predators = NULL;
        tab[i].free = false;
        result[i] = -1;
    }

    HuntingList *tmp = list;

    while (tmp != NULL) {
        node *prey = new node;
        prey->w = tmp->prey;
        prey->next = tab[tmp->predator].preys;
        tab[tmp->predator].preys = prey;

        node *hunter = new node;
        hunter->w = tmp->predator;
        hunter->next = tab[tmp->prey].predators;
        tab[tmp->prey].predators = hunter;

        tmp = tmp->next;
    }

    int counter = 0;

    for (int i = 0; i < n; i++)
        if (tab[i].preys == NULL) {
            tab[i].free = true;
            result[counter++] = i;
        }

    for (int i = 0; i < n; i++)
        if (!tab[i].free)
            hunters(tab, result, n, counter, i);

    for (int i = 0; i < n; i++) cout << result[i] << " ";

    if (result[n - 1] != -1) return result;

    delete[]result;
    return NULL;
}

void insert(HuntingList *list, int predator, int prey) {
    HuntingList *p = new HuntingList;
    p->predator = predator;
    p->prey = prey;
    p->next = NULL;
    while (list->next != NULL) list = list->next;
    list->next = p;
}

int main() {
    int n = 6;
    HuntingList *list = new HuntingList;

    list->predator = 3;
    list->prey = 0;
    list->next = NULL;
    insert(list, 3, 1);
    insert(list, 4, 1);
    insert(list, 4, 5);

    int *result = new int[n];
    result = releaseThemAll(list, n);
    for (int i = 0; i < n; i++) cout << result[i];
}