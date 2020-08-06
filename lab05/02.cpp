#include <iostream>

using namespace std;

struct stack {
    int size = 6;
    int top = 0;
    int *T;
public:
    stack();
};

bool is_empty(stack S) {
    return !(S.top);
}

void put(stack &S, int el) {
    if (S.top + 1 > S.size) {
        int *nT = NULL;
        nT = new int[S.size * 2];

        for (int i = 0; i < S.size; i++) nT[i] = S.T[i];

        S.size *= 2;
        S.T = nT;
    }

    S.T[S.top++] = el;
}

int pop(stack &S) {
    if (is_empty(S)) {
        cout << "Stack is empty!" << endl;
        return -1;
    }
    return S.T[--S.top];
}

stack::stack() {
    size = 2;
    top = 0;
    T = new int[2];
}

struct queue {
    stack s1;
    stack s2;
};

void push(queue &Q, int el) {
    put(Q.s2, el);
}

int get(queue &Q) {
    if (is_empty(Q.s1)) {
        if (is_empty(Q.s2)) {
            cout << "Queue is empty!" << endl;
            return -1;
        } else {
            while (!is_empty(Q.s2))
                put(Q.s1, pop(Q.s2));
        }
    }
    return pop(Q.s1);
}

int main() {
    queue Q;

    push(Q, 3);
    push(Q, 6);
    push(Q, 7);
    push(Q, 2);
    push(Q, 7);
    push(Q, 8);

    cout << get(Q) << endl;
    cout << get(Q) << endl;
    cout << get(Q) << endl;
    cout << get(Q) << endl;
    cout << get(Q) << endl;
    cout << get(Q) << endl;
    cout << get(Q) << endl;
}