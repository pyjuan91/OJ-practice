#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;
int n;
ll a[200005], mi, k, num;
void input(void);
bool helper(ll value);
void solve(void);
void output(void);
int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    input();
    solve();
    output();
    return 0;
}
void input(void)
{
    cin >> n >> k;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    return;
}
bool helper(ll value)
{
    ll sum = 0;
    for (int i = 0; i < n; i++) {
        sum += min(value, a[i]);
        if (sum > k)
            break;
    }
    return sum <= k;
}
void solve(void)
{
    ll left = 0, right = 1e12 + 5;
    while (left + 1 < right) {
        ll mid = (left + right) / 2;
        if (helper(mid))
            left = mid;
        else
            right = mid;
    }

    for (int i = 0; i < n; i++) {
        ll minus = min(a[i], left);
        a[i] -= minus;
        k -= minus;
    }

    for (int i = 0; i < n; i++) {
        if (a[i] && k) {
            a[i]--;
            k--;
        }
    }

    return;
}
void output(void)
{
    cout << a[0];
    for (int i = 1; i < n; i++) {
        cout << " " << a[i];
    }
    cout << "\n";
    return;
}