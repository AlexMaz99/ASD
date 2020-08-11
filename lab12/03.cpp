#include <iostream>
#include <stack>

using namespace std;

void shortest_path(int *parent, int n, int v) {
    stack<int> S;
    while (v != -1) {
        S.push(v);
        v = parent[v];
    }
    while (!S.empty()) {
        cout << S.top() << " ";
        S.pop();
    }
    cout << endl;
}

int main() {
    int n = 6;
    int parent[n] = {-1, 0, 1, 5, 0, 4};
    for (int i = 0; i < n; i++)
        shortest_path(parent, n, i);
}