#include <iostream>

using namespace std;


struct container {
    int lx;
    int ly;
    int rx;
    int ry;
};

int flooded_containers(container tab[], int n, int A) {
    int max = tab[0].ly;
    int min = tab[0].ry;
    for (int i = 1; i < n; i++) {
        if (tab[i].ly > max) max = tab[i].ly;
        if (tab[i].ry < min) min = tab[i].ry;
    }
    int size = max - min + 1;
    int *water = new int[size];
    for (int i = 0; i < size; i++) water[i] = 0;

    for (int i = 0; i < n; i++) {
        water[tab[i].ry - min] += tab[i].rx - tab[i].lx;
        water[tab[i].ly - min] += tab[i].lx - tab[i].rx;
    }
    for (int i = 1; i < size; i++) water[i] += water[i - 1];

    for (int i = 1; i < size; i++) water[i] += water[i - 1];

    int i = 0;
    while (i < size && A >= water[i]) i++;

    int result = 0;
    for (int j = 0; j < n; j++)
        if (tab[j].ly <= i) result++;

    delete[] water;

    return result;
};


int main() {
    int N = 3, A;
    container tab[N];
    for (int i = 0; i < N; i++)
        cin >> tab[i].lx >> tab[i].ly >> tab[i].rx >> tab[i].ry;
    cout << "Podaj ilosc wody: ";
    cin >> A;

    cout << endl << endl << flooded_containers(tab, N, A);
    return 0;
}