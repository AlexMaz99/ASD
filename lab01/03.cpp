struct node {
    int w;
    node *next;
};

node *reverse(node *first) {
    node *reversed = NULL;
    while (first != NULL) {
        node *tmp = first;
        first = first->next;
        tmp->next = reversed;
        reversed = tmp;
    }
    return reversed;
}