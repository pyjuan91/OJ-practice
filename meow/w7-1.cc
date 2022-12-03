#include <iostream>
#define endl '\n'
using ll = long long;
using namespace std;
const ll MOD = 1e9 + 7;
ll fastPower(ll a, ll b, ll mod)
{
    ll ans = 1;
    while (b) {
        if (b & 1) {
            ans = 1ULL * (ans * a) % mod;
        }
        b >>= 1;
        a = 1ULL * (a * a) % mod;
    }
    return ans;
}
int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    ll n, a, b, c;
    cin >> n;
    while (n--) {
        cin >> a >> b >> c;
        ll r = fastPower(b, c, MOD - 1);
        cout << fastPower(a, r, MOD) << endl;
    }
    return 0;
}