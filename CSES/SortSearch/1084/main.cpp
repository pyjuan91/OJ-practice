#include <vector>
#include "iostream"
#include "algorithm"

using namespace std;
using ll = long long;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie();

    ll n, m, k, res = 0;
    cin >> n >> m >> k;
    vector<ll> a(n), b(m);

    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < m; i++) cin >> b[i];

    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    ll applyIndex = 0, apartIndex = 0;
    while (applyIndex < n && apartIndex < m) {
        ll lowerBound = a[applyIndex] - k;
        ll upperBound = a[applyIndex] + k;
        if (b[apartIndex] >= lowerBound && b[apartIndex] <= upperBound) {
            applyIndex += 1;
            apartIndex += 1;
            res += 1;
        } else if (b[apartIndex] < lowerBound) apartIndex += 1;
        else applyIndex += 1;
    }
    cout << res;
    return 0;
}