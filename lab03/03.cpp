#include <iostream>

using namespace std;


struct point {
    int x;
    int y;
};
struct container {
    point l; //wspolrzedne lewego gornego rogu
    point p; //wspolrzedne prawego dolnego rogu
};

int flooded_containers(container tab[], int N, int A) {
    int MAX = -1;  //MAX to najwiekszy y z lewego roku
    for (int i = 0; i < N; i++)
        if (tab[i].l.y > MAX) MAX = tab[i].l.y;

    int X[MAX + 1]; //w tablicy bedzie zapisane ile jednostek znajduje sie pod danym indeksem (miedzy i a i-1)
    for (int i = 0; i < MAX + 1; i++) X[i] = 0;

    for (int i = 0; i < N; i++)
        for (int j = tab[i].p.y + 1; j <= tab[i].l.y; j++)
            X[j] += tab[i].p.x - tab[i].l.x;

    int height = 0;
    while (A > 0) {
        height++;
        A -= X[height];
    }

    if (A != 0) height--; //jezeli A jest rozne od 0 to znaczy ze nie zapelni sie caly poziom
    int result = 0;
    for (int i = 0; i < N; i++)
        if (tab[i].l.y <= height) result++;
    return result;
}

int main() {
    int N = 3, A;
    container tab[N];
    for (int i = 0; i < N; i++)
        cin >> tab[i].l.x >> tab[i].l.y >> tab[i].p.x >> tab[i].p.y;
    cout << "Podaj ilosc wody: ";
    cin >> A;

    cout << endl << endl << flooded_containers(tab, N, A);
    return 0;
}