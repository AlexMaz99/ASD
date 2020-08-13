#include <bits/stdc++.h>

using namespace std;

struct node {
    int w;
    node *next;
};
struct TwoLists {
    node *even;
    node *odd;
};

TwoLists split(node *list) {
    node *p = NULL;
    node *np = NULL;
    node *tmp;

    while (list != NULL) {
        tmp = list;
        list = list->next;
        if (tmp->w % 2 == 0) {
            tmp->next = p;
            p = tmp;
        } else {
            tmp->next = np;
            np = tmp;
        }
    }


    TwoLists result;
    result.even = p;
    result.odd = np;
    return result;
}

void insert_last(node *&first, int n)
{
    node *p = new node;
    p->w = n;
    p->next = NULL;
    if (first == NULL) first = p;
    else {
        node *r = first;
        while (r->next != NULL) {
            r = r->next;
        }
        r->next = p;
    }
}

int main() {
    node *first = new node;
    first = NULL;


    insert_last(first, 1);
    insert_last(first, 2);
    insert_last(first, 5);
    insert_last(first, 8);
    insert_last(first, 9);
    insert_last(first, 13);

    TwoLists result = split(first);

    while (result.even != NULL) {
        cout << result.even->w << " ";
        result.even = result.even->next;
    }
    cout << endl;

    while (result.odd != NULL) {
        cout << result.odd->w << " ";
        result.odd = result.odd->next;
    }

    return 0;
}