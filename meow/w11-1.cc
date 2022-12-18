#include <bits/stdc++.h>
#define pb emplace_back
#define F first
#define S second
#define rep(X, a, b) for (int X = a; X < b; ++X)
#define ALL(a) (a).begin(), (a).end()
#define SZ(a) (int)(a).size()
#define NL "\n"
using namespace std;
typedef pair<long long, long long> pll;
typedef pair<int, int> pii;
typedef long long ll;

ll num[22];
ll dp[1 << 22], last[1 << 22];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    ll n, x;
    cin >> n >> x;
    rep(i, 0, n) cin >> num[i];
    dp[0] = 1;
    last[0] = 0;
    for (ll i = 1; i < (1 << n); ++i) {
        dp[i] = INT_MAX;
        last[i] = INT_MAX;
        for (int a = 0; a < n; ++a) {
            if (i & (1 << a)) {
                int s = i & ~(1 << a);
                // subset without a
                if (last[s] + num[a] <= x) {
                    if (dp[s] < dp[i] || (dp[s] == dp[i] && last[s] + num[a] < last[i])) {
                        // if dp is smaller or if dp is equal but the weight is lesser
                        last[i] = last[s] + num[a];
                        dp[i] = dp[s];
                    }
                } else {
                    if (dp[s] + 1 < dp[i] || (dp[s] + 1 == dp[i] && num[a] < last[i])) {
                        last[i] = num[a];
                        dp[i] = dp[s] + 1;
                    }
                }
            }
        }
    }
    cout << dp[(1 << n) - 1] << NL;
}