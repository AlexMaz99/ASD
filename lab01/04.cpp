#include <iostream>

using namespace std;

struct min_max {
    int min;
    int max;
};

min_max find(int n, int t[]) {
    int b = INT16_MIN;
    int s = INT16_MAX;
    for (int i = 0; i < n; i += 2) {
        if (t[i] < t[i + 1]) {
            s = min(s, t[i]);
            b = max(b, t[i + 1]);
        } else {
            b = max(b, t[i]);
            s = min(s, t[i + 1]);
        }
    }

    min_max result;
    result.min = s;
    result.max = b;
    return result;
}

int main() {
    int t[10] = {1, 2, 6, 4, 3, 5, 3, 9, 10, 1};
    min_max result = find(10, t);
    cout << result.min << " " << result.max;
    return 0;
}