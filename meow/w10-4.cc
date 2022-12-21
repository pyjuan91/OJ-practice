#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll mod = 2e9 + 14;
ll solve(int n)
{
    if (n * (n + 1) % 4 != 0)
        return 0LL;
    int target = n * (n + 1) / 4;
    // cout << target << endl;
    vector dp = vector<vector<ll>>(n + 1, vector<ll>(target + 1, 0));
    dp[0][0] = 1;
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= target; j++) {
            dp[i][j] += dp[i - 1][j];
            if (j - i >= 0)
                dp[i][j] += dp[i - 1][j - i];
            dp[i][j] %= mod;
            // if(dp[i][j] >=  mod)
            // cout << "i: " << i << " j: " << j << " dp: " << dp[i][j] << endl;
        }
    }
    return (dp[n][target] / 2);
}
int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    cout << solve(n) << "\n";
    return 0;
}