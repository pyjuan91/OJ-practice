#include <bits/stdc++.h>
using namespace std;
int main(void)
{
    int kase, num, n, q;
    char cmd;
    cin >> kase;
    while (kase--) {
        cin >> n >> q;
        stack<int> head;
        stack<int> tail;
        stack<int> trueTail;
        vector<int> state(n + 1);
        fill(state.begin(), state.end(), 0);
        while (q--) {
            cin >> cmd >> num;
            if (cmd == 'H') {
                head.push(num);
                state[num] = 1;
            }
            if (cmd == 'T') {
                tail.push(num);
                state[num] = 2;
            }
        }

        bool first = true;
        while (!head.empty()) {
            if (state[head.top()] == 1) {
                if (first)
                    first = false;
                else
                    cout << " ";
                cout << head.top();
                state[head.top()] = -1;
            }
            head.pop();
        }

        for (int i = 1; i <= n; i++) {
            if (state[i] == 0) {
                if (first)
                    first = false;
                else
                    cout << " ";
                cout << i;
            }
        }

        while (!tail.empty()) {
            if (state[tail.top()] == 2) {
                trueTail.push(tail.top());
                state[tail.top()] = -1;
            }
            tail.pop();
        }

        while (!trueTail.empty()) {
            if (first)
                first = false;
            else
                cout << " ";
            cout << trueTail.top();
            trueTail.pop();
        }
        putchar('\n');
    }
}