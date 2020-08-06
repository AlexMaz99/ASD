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

int find_median(int t[], int start, int end) //sortuje tablice od indeksu start do end i zwraca wartosc srodkowa
{
    sort(t, start, end);
    return t[start + (end - start) / 2];
}

int magic5(int t[], int start, int end) {
    int n = end - start + 1; //rozmiar tablicy
    int median[(n + 4) / 5]; //tworzymy tablice o odpowiednim rozmiarze
    int i;
    for (i = 0; i < n / 5; i++)
        median[i] = find_median(t, 5 * i, 5 * i +
                                          4); //wpisujemy do tablicy median wartosci srodkowe z posortowanych odcinkow o dlugosci 5
    if (5 * i < n) //jezeli jest zostal odcinek o dlugosci mniejszej niz 5
    {
        median[i] = find_median(t, 5 * i, n - 1);
        i++; //rozmiar tablicy median
    }

    if (i == 1) return median[0]; //jezeli tablica median ma jeden element to zwracamy jego wartosc
    return magic5(median, 0, i - 1); //jezeli nie to wywolujemy rekurencyjnie dla tablicy median
}

int main() {
    int n = 27;
    int tab[n] = {1, 20, 2, 17, 3, 16, 4, 12, 10, 8, 5, 22, 24, 26, 2, 12, 14, 16, 3, 14, 21, 6, 11, 10, 2, 6, 12};
    return magic5(tab, 0, n - 1);
}