#include <iostream>

using namespace std;


void sort(int t[], int start, int end) //sortuje tablice od indeksu start do end
{
    for (int j = start + 1; j <= end; j++) {
        int k = j;
        while (k > start && t[k - 1] > t[k]) {
            swap(t[k], t[k - 1]);
            k--;
        }
    }
}

int find_median(int t[], int start, int end) //sortuje tablice od indeksu start do end i zwraca srodkowy indeks
{
    sort(t, start, end);
    return (start + (end - start) / 2);
}

int magic5(int t[], int start, int end) {
    int n = end - start + 1; //rozmiar tablicy
    if (n == 1) return t[0]; //jezeli mamy tylko jeden element w tablicy to go zwracamy
    int i, j;
    for (i = 0; i < n / 5; i++) {
        j = find_median(t, 5 * i,
                        5 * i + 4); //zamieniamy w tablicy t poczatkowe wartosci z medianami 5-elementowych przedzialow
        swap(t[i], t[j]);
    }
    if (5 * i < n) //jezeli zostal odcinek o dlugosci mniejszej niz 5
    {
        j = find_median(t, 5 * i, n - 1);
        swap(t[i], t[j]);
        i++; //ilosc przedzialow na ktorych podzielilismy tablice t (ilosc median)
    }

    return magic5(t, 0, i - 1); //wywolujemy rekurencyjnie dla tablicy t wypelnionej medianami
}

int main() {
    int n = 12;
    int tab[n] = {1, 5, 7, 8, 12, 3, 4, 11, 15, 5, 6, 2};
    return median = magic5(tab, 0, n - 1);
}