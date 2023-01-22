#include <vector>
#include "iostream"
#include "algorithm"

using namespace std;
using ll = long long;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie();
    ll n;
    cin >> n;
    ll target = n * (n + 1) / 2;
    if (target % 2 == 1) cout << "NO\n";
    else {
        target = target / 2;
        ll sum = 0;
        vector<ll> v1, v2;
        for (ll i = n; i > 0; i--) {
            if (sum + i <= target) {
                v1.emplace_back(i);
                sum += i;
            }
        }
        if (sum == target) {
            cout << "YES\n";
            reverse(v1.begin(), v1.end());
            auto iter = v1.begin();
            for (int i = 1; i <= n; i++) {
                if (iter == v1.end()) break;
                if (*iter == i) iter++;
                else v2.emplace_back(i);
            }
            cout << v1.size() << "\n";
            for (auto i: v1) cout << i << " ";
            cout << "\n";
            cout << v2.size() << "\n";
            for (auto i: v2) cout << i << " ";
            cout << "\n";
        } else cout << "NO\n";
    }
    return 0;
}