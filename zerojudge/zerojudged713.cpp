#include <algorithm>
#include <functional>
#include <iostream>
#include <queue>
using namespace std;
int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    priority_queue<int> left;
    priority_queue<int, vector<int>, greater<int>> right;
    bool even = true;
    while (cin >> n) {
        even = !even;
        if (left.empty())
            left.push(n);
        else if (right.empty())
            right.push(n);
        else {
            if (n >= right.top()) {
                right.push(n);
            } else {
                left.push(n);
            }
        }
        if ((int)left.size() - (int)right.size() > 1) {
            right.push(left.top());
            left.pop();
        }
        if ((int)right.size() - (int)left.size() > 0) {
            left.push(right.top());
            right.pop();
        }
        if (!even)
            cout << left.top() << "\n";
        else
            cout << (left.top() + right.top()) / 2 << "\n";
    }
    return 0;
}