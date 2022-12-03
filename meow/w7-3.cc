#include <algorithm>
#include <bitset>
#include <iostream>
#include <vector>
using namespace std;
#define ll long long
const int MAX = 1e6 + 5;
bitset<MAX> isPrime;
vector<int> primes;
int spf[MAX];
int mobius[MAX];
void sieve()
{
    isPrime.set();
    isPrime[0] = isPrime[1] = 0;
    mobius[1] = 1;
    for (int i = 2; i < MAX; i++) {
        if (isPrime[i]) {
            primes.push_back(i);
            spf[i] = i;
            mobius[i] = -1;
        }
        for (int j = 0; j < (int)primes.size()
             && primes[j] <= (MAX - 1) / i;
             j++) {
            int p = primes[j];
            isPrime[i * p] = 0;
            spf[i * p] = p;
            mobius[i * p] = (spf[i] == p) ? 0 : -mobius[i];
            if (i % primes[j] == 0)
                break;
        }
    }
}
void solve(int tc = 0)
{
    sieve();
    int n;
    cin >> n;
    vector<int> cnt(MAX);
    while (n--) {
        int x;
        cin >> x;
        cnt[x]++;
    }
    ll ans = 0;
    for (int i = 1; i < MAX; i++) {
        ll num = 0;
        for (int j = i; j < MAX; j += i)
            num += cnt[j];
        ans += num * (num - 1) / 2 * mobius[i];
    }
    cout << ans << "\n";
}
signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int tc = 1;
    // cin >> tc;
    for (int t = 1; t <= tc; t++) {
        // cout << "Case #" << t << ": ";
        solve(t);
    }
}