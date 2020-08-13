#include <iostream>
#include <string>

using namespace std;


struct Set {
    Set *right;
    Set *left;
    bool exist;
};

Set *createSet(string A[], int n) {
    Set *root = new Set;
    root->right = root->left = NULL;
    root->exist = false;

    for (int i = 0; i < n; i++) {
        Set *tmp = root;
        string x = A[i];

        for (int j = 0; j < x.size(); j++) {
            if (x[j] == '0') {
                if (tmp->left == NULL) {
                    tmp->left = new Set;
                    tmp = tmp->left;
                    tmp->left = tmp->right = NULL;
                    tmp->exist = false;
                } else tmp = tmp->left;
            } else {
                if (tmp->right == NULL) {
                    tmp->right = new Set;
                    tmp = tmp->right;
                    tmp->left = tmp->right = NULL;
                    tmp->exist = false;
                } else tmp = tmp->right;
            }
        }
        tmp->exist = true;
    }
    return root;
}

bool contains(Set *a, string s) {
    for (int i = 0; i < s.size() && a != NULL; i++) {
        if (s[i] == '0') a = a->left;
        else a = a->right;
    }
    if (a == NULL || !a->exist) return false;
    return true;
}

int main() {
    int n = 5;
    string A[n];
    for (int i = 0; i < n; i++) cin >> A[i];

    Set *root = createSet(A, n);
    return contains(root, "1010");
}
