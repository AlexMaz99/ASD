#include <iostream>
#include <string>

using namespace std;


bool possible(string u, string v, string w) {
    int *words = new int[26];

    for (int i = 0; i < 26; i++) words[i] = 0;
    for (int i = 0; i < u.size(); i++) words[u[i] - 'a']++;
    for (int i = 0; i < v.size(); i++) words[v[i] - 'a']++;
    for (int i = 0; i < w.size(); i++) words[w[i] - 'a']--;

    for (int i = 0; i < 26; i++)
        //  cout<<words[i]<<" ";
        for (int i = 0; i < 26; i++)
            if (words[i] < 0)
                return false;

    return true;
}

int main() {
    string u = "olka";
    string v = "domek";
    string w = "moda";

    return possible(u, v, w);
}