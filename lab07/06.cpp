#include <iostream>

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

node *tree(int *tab, int start, int end) {
    if (start > end) return NULL;
    node *root = new node;
    int mid = (start + end) / 2;
    root->w = tab[mid];
    root->left = root->right = NULL;

    if (start == end) return root;
    root->left = tree(tab, start, mid - 1);
    root->right = tree(tab, mid + 1, end);
    return root;
}


int main() {
    int n = 10;
    int t[n] = {1, 2, 4, 5, 6, 8, 10, 12, 14, 15};
    node *root = tree(t, 0, n - 1);
    print(root);
}