#include <iostream>

using namespace std;


struct person {
    char *name;
    char *surname;
    int n_len;
    int s_len;
    int age;
};

int hash(osoba *x, int k) {
    int j = 0;
    char v[4];
    for (int i = 0; i < 4; i++) v[i] = 211;
    for (int i = 0; i < x->n_len; i++) {
        v[j % 4] = v[j % 4] ^ x->name[i];
        j++;
    }
    for (int i = 0; i < x->s_len; i++) {
        v[j % 4] = v[j % 4] ^ x->surname[i];
        j++;
    }

    v[0] = v[0] ^ x->age;
    v[1] = v[1] ^ (255 - x->age);
    v[2] = v[2] ^ x->age;
    v[3] = v[3] ^ (255 - x->age);

    j = 0;
    for (int i = 0; i < 4; i++) {
        j += v[i];
        j = j << 8;
    }
    return j % k;
}


int main() {

}
