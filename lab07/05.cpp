#include<iostream>

using namespace std;

struct node {
    int w;
    node *right;
    node *left;
};


void print(node *p) {
    if (p != NULL) {
        print(p->left);
        cout << p->w << " ";
        print(p->right);
    }
}

void insert(node *p, int key) {
    node *q = NULL;
    node *n = new node;
    n->right = n->left = NULL;
    n->w = key;
    while (p != NULL) {
        q = p;
        if (key < p->w) p = p->left;
        else p = p->right;
    }
    if (q == NULL) p = n;
    else if (key < q->w) q->left = n;
    else q->right = n;
}

node *tree(node *root) {
    if (root == NULL) return root;
    if (root->left != NULL) {
        node *min_el = tree(root->left);
        while (min_el->right != NULL) min_el = min_el->right;
        min_el->right = root;
        root->left = min_el;
    }
    if (root->right != NULL) {
        node *max_el = tree(root->right);
        while (max_el->left != NULL) max_el = max_el->left;
        max_el->left = root;
        root->right = max_el;
    }
    return root;
}

node *tree_to_list(node *root) {
    if (root == NULL) return root;
    root = tree(root);
    while (root->left != NULL) root = root->left;
    return root;
}

node *list_to_tree(node *first) {
    if (first == NULL || (first->left == NULL && first->right == NULL)) return first;
    node *root = first;
    node *tmp = first;
    while (tmp != NULL && tmp->right != NULL) {
        root = root->right;
        tmp = tmp->right->right;
    }

    tmp = root->left;
    if (tmp != NULL) tmp->right = NULL;
    tmp = root->right;
    if (tmp != NULL) tmp->left = NULL;
    root->left = list_to_tree(first);
    root->right = list_to_tree(tmp);
    return root;
}

int main() {
    node *p = new node;
    p->right = p->left = NULL;
    p->w = 8;
    insert(p, 2);
    insert(p, 12);
    insert(p, 1);
    insert(p, 5);
    insert(p, 10);
    insert(p, 9);
    insert(p, 6);

    node *first = tree_to_list(p);

    p = list_to_tree(first);
    print(p);
}