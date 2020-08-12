#include <iostream>

using namespace std;


bool DFS(int i, bool *visited, node *t, int N) {
    visited[i] = true;
    int count = 0;

    for (node *x = t[i]; x != NULL; x = x->next) {
        if (!visited[x] && DFS(x->val, visited, t, N)) return true;
        else count++;
    }

    return count > 1;
}

bool is_cycle(node *t, int N, int v) //funkcja sprawdzajaca czy graf jest cyklem
{
    bool visited[N];
    for (int i = 0; i < N; i++) visited[i] = false;

    for (int i = 0; i < N; i++)
        if (!visited[i] && DFS(i, visited, t, N)) return true;

    return false;
}

int main() {

}