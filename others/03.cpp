#include <iostream>
#include <cmath>

using namespace std;

int binary(string x, int start, int end) {
    int result = 0;
    int j = 0;

    for (int i = end; i >= start; i--) {
        result += pow(2, j) * (x[i] - 'a');
        j++;
    }

    return result;
}

string series(string x, int n, int k) {
    int *count = new int[int(pow(2, k))];

    for (int i = 0; i < pow(2, k); i++) count[i] = 0;
    for (int i = 0; i + k - 1 < n; i++) {
        count[binary(x, i, i + k - 1)]++;
    }

    int max = 0;
    int val = 0;

    for (int i = 0; i < pow(2, k); i++) {
        if (count[i] > max) {
            max = count[i];
            val = i;
        }
    }

    delete[]count;

    string help = "";
    string result = "";
    int p = k;

    while (p != 0) {
        if (val % 2 == 0) help += "a";
        else help += "b";
        val /= 2;
        p--;
    }

    for (int i = 0; i < k; i++) {
        result += help[k - i - 1];
    }

    return result;
}

int main() {
    int n = 10, k = 3;
    string x = "abababaabb";
    cout << series(x, n, k);
}