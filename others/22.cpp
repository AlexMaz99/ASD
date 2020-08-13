#include <iostream>
#include <cmath>

using namespace std;

struct BST {
    BST *right;
    BST *left;
    int value;
};

int get_size(BST *root) {
    if (root == NULL) return 0;
    return get_size(root->left) + get_size(root->right) + 1;
}

int countInterval(BST *T, int a, int b) {
    if (a == b) return 1;

    while ((a < T->value && b < T->value) || (a > T->value && b > T->value)) {
        if (a < T->value) T = T->left;
        else T = T->right;
    }

    int counter = 0;

    if (a == T->value) {
        counter++;
        T = T->right;
        while (b != T->value) {
            if (b < T->value) T = T->left;
            else {
                counter = counter + 1 + get_size(T->left);
                T = T->right;
            }
        }
        return counter + 1 + get_size(T->left);
    } else if (b == T->value) {
        counter++;
        T = T->left;
        while (a != T->value) {
            if (a < T->value) {
                counter = counter + 1 + get_size(T->right);
                T = T->left;
            } else T = T->right;
        }
        return counter + 1 + get_size(T->right);
    }

    BST *tmp = T;

    while (a != T->value) {
        if (a < T->value) {
            if (T != tmp) counter = counter + 1 + get_size(T->right);
            else counter++;
            T = T->left;
        } else T = T->right;
    }

    counter = counter + get_size(T->right);
    T = tmp;

    while (b != T->value) {
        if (b < T->value) T = T->left;
        else {
            if (T != tmp)counter = counter + 1 + get_size(T->left);
            else counter++;
            T = T->right;
        }
    }

    counter = counter + get_size(T->left);
    return counter + 1;
}

void insert(BST *root, int w) {
    BST *p = new BST;
    p->value = w;
    p->right = p->left = NULL;
    BST *q = NULL;

    while (root != NULL) {
        q = root;
        if (w < root->value) root = root->left;
        else root = root->right;
    }

    if (w < q->value) q->left = p;
    else q->right = p;
}

int main() {
    BST *root = new BST;
    root->value = 10;
    root->right = root->left = NULL;

    insert(root, 5);
    insert(root, 20);
    insert(root, 15);
    insert(root, 3);
    insert(root, 8);
    insert(root, 9);
    insert(root, 1);
    insert(root, 2);

    cout << countInterval(root, 2, 15);
    return 0;
}
