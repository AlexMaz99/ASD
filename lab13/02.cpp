#include <iostream>
#include <string>

using namespace std;

int main() {
    int n;
    cin >> n;
    string A[n];

    for (int i = 0; i < n; i++) cin >> A[i];

    string s;
    cin >> s;

    int *f = new int[s.size() + 1];
    for (int i = 1; i < s.size() + 1; i++) f[i] = INT_MAX / 2;
    f[0] = 0;

    for (int i = 1; i <= s.size(); i++)
        for (int j = 0; j < n; j++)
            if (A[j].size() <= i && s.substr(i - A[j].size(), A[j].size()) == A[j])
                f[i] = min(f[i - A[j].size()] + 1, f[i]);


    if (f[s.size()] < INT_MAX / 2)cout << f[s.size()] << endl;
    else cout << "Nie da sie" << endl;

    return 0;
}