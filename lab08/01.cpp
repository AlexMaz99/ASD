#include <iostream>

using namespace std;

struct node {
    int w;
    node *right;
    node *left;
    node *parent;
    string color;
};

void print(node *p) {
    if (p != NULL) {
        print(p->left);
        cout << p->w << " " << p->color << endl;
        print(p->right);
    }
}

int find_min(node *root) {
    if (root == NULL)return 0;
    return min(find_min(root->left), find_min(root->right)) + 1;
}

bool colorRB(node *root, node *p, int black_counter) {
    if (black_counter < 0) return false;
    if (p == NULL) return true;
    if (p == root || p->parent->color == "red" || find_min(p) == black_counter) {
        p->color = "black";
        black_counter--;
        return colorRB(root, p->right, black_counter) && colorRB(root, p->left, black_counter);
    } else {
        if (find_min(p) < black_counter) return false;
        p->color = "red";
        return colorRB(root, p->right, black_counter) && colorRB(root, p->left, black_counter);
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
    n->parent = q;
    if (q == NULL) p = n;
    else if (key < q->w) q->left = n;
    else q->right = n;
}

int main() {
    node *p = new node;
    p->left = p->right = p->parent = NULL;
    p->w = 10;
    insert(p, 4);
    insert(p, 15);
    insert(p, 2);
    insert(p, 6);
    insert(p, 1);
    insert(p, 3);
    insert(p, 11);
    insert(p, 18);
    insert(p, 17);
    insert(p, 19);
    insert(p, 20);
    //insert (p,24);


    if (colorRB(p, p, find_min(p))) {
        print(p);
        return 1;
    }
    return 0;
}