#include <iostream>
#include <string>

using namespace std;


int digit(string a, int pos) {
    return int(a[pos] - 'a');
}

void radixSort(string A[], int start, int n, int pos) {
    int *counters = new int[26];
    string *result = new string[n];

    for (int i = 0; i < 26; i++) counters[i] = 0;
    for (int i = start; i < n; i++) counters[digit(A[i], pos)]++;
    for (int i = 1; i < 26; i++) counters[i] += counters[i - 1];
    for (int i = n - 1; i >= start; i--) {
        --counters[digit(A[i], pos)];
        result[start + counters[digit(A[i], pos)]] = A[i];
    }
    for (int i = start; i < n; i++) A[i] = result[i];

    delete[]counters;
    delete[]result;
}

void counting_by_size(string A[], int n, int minsize, int maxsize) {
    int *counters = new int[maxsize - minsize + 1];
    string *result = new string[n];

    for (int i = 0; i < maxsize - minsize + 1; i++) counters[i] = 0;
    for (int i = 0; i < n; i++) counters[A[i].size() - minsize]++;
    for (int i = 1; i < maxsize - minsize + 1; i++) counters[i] += counters[i - 1];
    for (int i = n - 1; i >= 0; i--) result[--counters[A[i].size() - minsize]] = A[i];
    for (int i = 0; i < n; i++) A[i] = result[i];

    delete[]counters;
    delete[]result;
}

void sortString(string A[], int n) {
    int minsize = A[0].size();
    int maxsize = A[0].size();

    for (int i = 1; i < n; i++) {
        if (A[i].size() < minsize) minsize = A[i].size();
        else if (A[i].size() > maxsize) maxsize = A[i].size();
    }
    counting_by_size(A, n, minsize, maxsize);

    int start = n - 1;

    for (int i = maxsize - 1; i >= 0; i--) {
        while (start >= 0 && A[start].size() - 1 >= i)
            start--;
        radixSort(A, start + 1, n, i);
    }
}

int main() {
    int n = 10;
    string A[n] = {"abcd", "ola", "mama", "kot", "amarant", "kawa", "maskotka", "rolki", "rower", "szpilki"};
    sortString(A, n);
    for (int i = 0; i < n; i++) cout << A[i] << " ";
}