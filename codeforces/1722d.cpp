#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;
using ll = long long;
char line[200005];
ll foo, n;
queue<ll> q;
void go()
{
    ll left = 0, right = n - 1, cnt = 0;
    while (left < right) {
        if (line[left] == 'L') {
            q.push(left);
        }
        if (line[right] == 'R') {
            q.push(right);
        }
        left++, right--;
    }
}
ll solve()
{
    if (q.empty())
        return foo;
    if (line[q.front()] == 'L') {
        foo -= q.front(), foo += n - 1 - q.front();
    } else {
        foo -= n - 1 - q.front(), foo += q.front();
    }
    q.pop();
    return foo;
}
int main(void)
{
    bool first;
    ll t, i, j, left, right;
    cin >> t;
    while (t--) {
        while (!q.empty()) {
            q.pop();
        }

        cin >> n;
        left = 0, right = n - 1, foo = 0;
        for (i = 0; i < n; i++) {
            cin >> line[i];
            if (line[i] == 'L') {
                foo += i - 0;
            } else {
                foo += n - 1 - i;
            }
        }
        go();
        first = true;
        for (i = 0; i < n; i++) {
            if (first)
                first = false;
            else
                cout << " ";
            cout << solve();
        }
        cout << endl;
    }
    return 0;
}