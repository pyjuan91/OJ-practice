#include <vector>
#include "iostream"
#include "algorithm"

using namespace std;
using ll = long long;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie();
    ll n, x;
    cin >> n >> x;
    vector<ll> v(n);
    for (int i = 0; i < n; i++) cin >> v[i];
    sort(v.begin(), v.end());
    ll left = 0, right = n - 1, res = 0;
    while (left <= right) {
        if (v[left] + v[right] <= x) left += 1;
        right -= 1;
        res += 1;
    }
    cout << res;
    return 0;
}