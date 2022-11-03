#include <algorithm>
#include <iostream>
#include <stack>
using namespace std;
using ll = long long;
int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    ll h, ans = 0;

    while (cin >> n) {
        ans = 0;
        stack<int> index;
        stack<ll> tp;
        cin >> h;
        index.push(0);
        tp.push(h);
        for (int i = 1; i <= n; i++) {
            int left_most_id = i;
            if (i < n)
                cin >> h;
            else
                h = 0;
            while (!tp.empty() && tp.top() >= h) {
                left_most_id = index.top();
                ans = max(ans, (long long)(i - left_most_id) * tp.top());
                tp.pop();
                index.pop();
            }
            index.push(left_most_id);
            tp.push(h);
        }
        cout << ans << endl;
    }
    return 0;
}