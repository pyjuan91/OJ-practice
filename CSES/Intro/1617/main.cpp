#include "iostream"

using namespace std;
using ll = long long;
const ll mod = 1e9 + 7;

ll solve(ll n) {
    ll res = 1;
    ll mul = 2;
    while (n) {
        if (n & 1) {
            res *= mul;
            res %= mod;
        }
        mul *= mul;
        mul %= mod;
        n >>= 1;
    }
    return res;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie();
    ll n;
    cin >> n;
    cout << solve(n) << "\n";
    return 0;
}