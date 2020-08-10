#include <iostream>

using namespace std;


struct node {
    node *left;
    node *right;
    int key;
};

bool isAVL(node *root, int &height) {
    bool leftAVL, rightAVL;
    int lh, rh;
    if (root->left == NULL) {
        leftAVL = true;
        lh = 0;
    } else leftAVL = isAVL(root->left, lh);
    if (root->right == NULL) {
        rightAVL = true;
        rh = 0;
    } else rightAVL = isAVL(root->right, rh);
    height = max(lh, rh) + 1;
    if (abs(height - rh) <= 1 && abs(height - lh) <= 1 && rightAVL && leftAVL) return true;
    return false;
}

int main() {

}
