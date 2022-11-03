#include <algorithm>
#include <deque>
#include <functional>
#include <iostream>
#include <queue>
using namespace std;
int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int q, cmd, val;
    cin >> q;
    deque<int> buf;
    priority_queue<int, vector<int>, greater<int>> stay;
    while (q--) {
        cin >> cmd;
        if (cmd == 1) {
            cin >> val;
            buf.push_back(val);
        } else if (cmd == 2) {
            if (stay.empty()) {
                cout << buf.front() << "\n";
                buf.pop_front();
            } else {
                cout << stay.top() << "\n";
                stay.pop();
            }
        } else { // cmd == 3
            for (auto i : buf)
                stay.push(i);
            buf.clear();
        }
    }
    return 0;
}