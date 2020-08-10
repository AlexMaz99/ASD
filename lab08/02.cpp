#include <iostream>

using namespace std;


struct trie {
    trie *A;
    trie *C;
    trie *T;
    trie *G;
    bool exist;
};

void free_trie(trie *root) {
    if (root == NULL) return;
    free_trie(root->A);
    free_trie(root->C);
    free_trie(root->T);
    free_trie(root->G);
    delete root;
}

bool duplicates(char **DNA, int n) {
    trie *root = new trie;
    root->A = root->C = root->T = root->G = NULL;
    root->exist = false;

    for (int i = 0; i < n; i++) {
        trie *current = root;
        char *S = DNA[i];
        for (int j = 0; S[j] != '\0'; j++) {
            if (S[j] == 'A') {
                if (current->A != NULL) current = current->A;
                else {
                    current->A = new trie;
                    current = current->A;
                    current->A = current->C = current->T = current->G = NULL;
                    current->exist = false;
                }
            }
            if (S[j] == 'C') {
                if (current->C != NULL) current = current->C;
                else {
                    current->C = new trie;
                    current = current->C;
                    current->A = current->C = current->T = current->G = NULL;
                    current->exist = false;
                }
            }
            if (S[j] == 'T') {
                if (current->T != NULL) current = current->T;
                else {
                    current->T = new trie;
                    current = current->T;
                    current->A = current->C = current->T = current->G = NULL;
                    current->exist = false;
                }
            }
            if (S[j] == 'G') {
                if (current->G != NULL) current = current->G;
                else {
                    current->G = new trie;
                    current = current->G;
                    current->A = current->C = current->T = current->G = NULL;
                    current->exist = false;
                }
            }
        }
        if (!current->exist) current->exist = true;
        else {
            free_trie(root);
            return true;
        }
    }
    free_trie(root);
    return false;
}


int main() {

}