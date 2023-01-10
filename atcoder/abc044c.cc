#include <bits/stdc++.h>
using namespace std;
using ll = long long;
ll dp[55][55][50 * 50 + 5];
int main(void)
{
    int n, a, x;
    cin >> n >> a;
    dp[0][0][0] = 1;
    for (int i = 1; i <= n; i++) {
        cin >> x;
        for (int j = 0; j <= i; j++) {
            for (ll sum = 0; sum <= 50 * i; sum++) {
                if (dp[i - 1][j][sum]) {
                    dp[i][j][sum] += dp[i - 1][j][sum];
                    dp[i][j + 1][sum + x] += dp[i - 1][j][sum];
                }
            }
        }
    }
    ll res = 0;
    for (int i = 1; i <= n; i++)
        res += dp[n][i][a * i];
    cout << res;
    return 0;
}