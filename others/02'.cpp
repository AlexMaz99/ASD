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
    return t[(end + start) / 2];
}


int magic_fives(int A[], int start, int end, int k) {
    if (end - start < 10) {
        sort(A, start, end);
        return A[start + k];
    }
    int *B = new int[(end - start) / 5 + 1];
    for (int i = start; i < end; i += 5) B[i / 5] = find_median(A, i, min(i + 4, end));
    int med = magic_fives(B, 0, (end - start) / 5, ((end - start) / 5 + 1) / 2);

    delete[]B;
    int *smaller = new int[end - start + 1]; //tablica z elementami mniejszymi od mediany
    int *bigger = new int[end - start + 1]; //tablica z elementami wiekszymi od mediany

    int i = 0;
    int j = 0;
    int x = start;
    while (x <= end) {
        if (A[x] < med) smaller[i++] = A[x];
        else if (A[k] > med) bigger[j++] = A[x];
        x++;
    }
    // i-rozmiar tablicy smaller, j-rozmiar tablicy bigger

    int result = 0;
    if (i - 1 >= k)      // wiemy ktorym wyrazem z kolei jest m wiec teraz szukamy w mniejszej tablicy
        result = magic_fives(smaller, 0, i - 1, k);
    else if (i - 1 + (end - start + 1) - j - i >= k) result = med;
    else result = magic_fives(bigger, 0, j - 1, k - (i - 1 + (end - start + 1) - j - i) - 1); //k-i-1

    delete[]smaller;
    delete[]bigger;

    return result;
}

int SumBetween(int T[], int from, int to, int n) {
    int x = magic_fives(T, 0, n - 1, from);
    int y = magic_fives(T, 0, n - 1, to);
    cout << x << " " << y << endl;
    int sum = 0;
    for (int i = 0; i < n; i++)
        if (T[i] >= x && T[i] <= y) sum += T[i];
    return sum;
}

int main() {
    int n = 12;
    int k = 6;
    int tab[n] = {10, 9, 5, 6, 2, 3, 1, 12, 11, 8, 7, 4};
    cout << SumBetween(tab, 0, 5, n);
}
