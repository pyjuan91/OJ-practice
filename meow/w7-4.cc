#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll mod = 1e9 + 7;
ll mbs(ll base, ll expo)
{
    ll ans = 1;
    while (expo) {
        if (expo & 1) {
            ans *= base;
            ans %= mod;
        }
        base *= base;
        base %= mod;
        expo >>= 1;
    }
    return ans;
}
ll sigmoid(ll n)
{
    ll res = 0;
    ll i = 1;
    ll two_p_minus_2 = mbs(2LL, mod - 2);
    // cout << two_p_minus_2 << endl;
    while (i <= n) {
        ll q = n / i;
        ll next_i = n / q + 1;
        // ll sum_to_next_i = (((next_i * (next_i - 1)) % mod) * two_p_minus_2) % mod;
        // ll sum_to_i = (((i * (i - 1)) % mod) * two_p_minus_2) % mod;
        ll ns = ((((next_i % mod) * ((next_i - 1) % mod)) % mod) * two_p_minus_2) % mod;
        ll cs = ((((i % mod) * ((i - 1) % mod)) % mod) * two_p_minus_2) % mod;
        // ll w = (ns-cs+mod)%mod;
        res += ((q % mod) * ((ns - cs + mod) % mod)) % mod;
        res %= mod;
        // cout << i << " " << res << endl;
        i = next_i;
    }
    return res;
}
int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    ll n;
    cin >> n;
    cout << sigmoid(n) << endl;
    return 0;
}