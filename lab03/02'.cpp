#include <iostream>

using namespace std;


// zwraca cyfre o pozycji 1...num len(num) liczac od tylu
int get_num_by_pos(int num, int base, int pos) {
    if (pos == 1)
        return num % base;

    int i = 1;
    num /= base;
    int dig = 0;

    while (num != 0 && i != pos) {
        dig = num % base;
        num /= base;
        i++;
    }

    return dig;
}

// sortuje wzgledem pozycji p
void sort_by_pos(int A[], int n, int p) {
    int *res = new int[n];
    int *tab = new int[n];

    for (int i = 0; i < n; i++)
        tab[i] = 0;
    for (int i = 0; i < n; i++)
        tab[get_num_by_pos(A[i], n, p)]++;
    for (int i = 1; i < n; i++)
        tab[i] = tab[i] + tab[i - 1];
    cout << "tab: ";

    for (int i = 0; i < n; i++) cout << tab[i] << " ";
    cout << endl << "res: ";

    for (int i = n - 1; i >= 0; i--)
        res[--tab[get_num_by_pos(A[i], n, p)]] = A[i];
    for (int i = 0; i < n; i++) cout << res[i] << " ";
    cout << endl << endl;
    for (int i = 0; i < n; i++)
        A[i] = res[i];

    delete[] res;
    delete[] tab;
}

// Sortuje n elementoww tablicy z elementami z zakresu [0, n^p-1]
void radix_sort(int A[], int n, int p) {
    for (int i = 1; i <= p; i++)
        sort_by_pos(A, n, i);
}

int main() {
    int n = 10;
    int A[n] = {99, 24, 1, 55, 79, 64, 23, 12, 5, 67};

    radix_sort(A, n, 2);
    for (int i = 0; i < n; i++) cout << A[i] << " ";

    return 0;
}