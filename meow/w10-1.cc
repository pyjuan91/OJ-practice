#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll mod = 1e9 + 7;
vector<vector<ll>> matrix_multiply(vector<vector<ll>>& a,
    vector<vector<ll>>& b, ll& n)
{
    vector<vector<ll>> ans;
    ans.resize(n + 1, vector<ll>(n + 1, 0LL));
    for (ll i = 1; i <= n; i++) {
        for (ll j = 1; j <= n; j++) {
            for (ll k = 1; k <= n; k++) {
                ans[i][j] += (a[i][k] * b[k][j]) % mod;
                ans[i][j] %= mod;
            }
        }
    }
    return ans;
}
ll solve(vector<vector<ll>>& g, ll& n, ll& k)
{
    vector<vector<ll>> ans;
    ans.resize(n + 1, vector<ll>(n + 1, 0LL));
    for (int i = 1; i <= n; i++)
        ans[i][i] = 1;
    while (k) {
        if (k & 1) {
            ans = matrix_multiply(ans, g, n);
        }
        g = matrix_multiply(g, g, n);
        k = k >> 1;
    }
    // for (int i = 1; i <= n; i++) {
    //     for (int j = 1; j <= n; j++) {
    //         cout << ans[i][j] << " ";
    //     }
    //     cout << endl;
    // }
    return ans[1][n];
}
int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    ll n, m, k, a, b;
    cin >> n >> m >> k;
    vector g = vector<vector<ll>>(n + 1, vector<ll>(n + 1, 0));
    for (int i = 0; i < m; i++) {
        cin >> a >> b;
        g[a][b] += 1;
    }
    cout << solve(g, n, k) << "\n";
    return 0;
}