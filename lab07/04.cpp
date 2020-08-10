struct node {
    int w;
    node *right;
    node *left;
    node *parent;
};

void print(node *p) {
    if (p != NULL) {
        print(p->left);
        cout << p->w;
        print(p->right);
    }
}

node *find(node *p, int key) {
    if (p == NULL || p->w == key) return p;
    if (key < p->w) return find(p->left, key);
    return find(p->right, key);
}

node *find_min(node *p) {
    if (p == NULL) return -1;
    while (p->left != NULL) p = p->left;
    return p;
}

node *find_max(node *p) {
    if (p == NULL) return -1;
    while (p->right != NULL) p = p->right;
    return p;
}

node *successor(node *p) {
    if (p->right != NULL) return find_min(p->right);
    node *q = p->parent;
    while (q != NULL && q->right == p) {
        p = q;
        q = q->parent;
    }
    return q;
}

void insert_rec(node *&p, int key) {
    if (p == NULL) {
        p = new node;
        p->left = p->right = NULL;
        p->w = key;
    } else if (key < p->w) insert_rec(p->left, key);
    else insert_rec(p->right, key);
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

void transplant(node *&root, node *p, node *q) {
    if (p->parent == NULL) root = q;
    else if (p == p->parent->left) p->parent->left = q;
    else p->parent->right = q;
    if (q != NULL) q->parent = p->parent;
}

void tree_delete(node *&root, node *n) {
    if (n->left == NULL) transplant(root, n, n->right);
    else if (n->right == NULL) transplant(root, n, n->left);
    else {
        node *p = find_min(n->right);
        if (p->parent != n) {
            transplant(root, p, p->right);
            p->right = n->right;
            p->right->parent = p;
        }
        transplant(root, n, p);
        p->left = n->left;
        p->left->parent = p;
    }
}