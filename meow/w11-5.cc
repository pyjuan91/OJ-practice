#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    ll n, x;
    cin >> n >> x;
    vector<pair<ll, ll>> a(n);
    for (ll i = 0; i < n; i++) {
        cin >> a[i].first;
        a[i].second = i + 1;
    }
    sort(a.begin(), a.end());
    for (ll i = 0; i < n - 3; i++) {
        for (ll j = i + 1; j < n - 2; j++) {
            ll left = j + 1, right = n - 1;
            ll target = x - a[i].first - a[j].first;
            while (left < right) {
                if (a[left].first + a[right].first == target) {
                    cout << a[i].second << " " << a[j].second
                         << " " << a[left].second << " " << a[right].second;
                    return 0;
                }
                if (a[left].first + a[right].first < target)
                    left++;
                else
                    right--;
            }
        }
    }
    cout << "IMPOSSIBLE";
    return 0;
}