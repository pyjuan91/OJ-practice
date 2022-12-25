#include <bits/stdc++.h>
using namespace std;
int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<int> h(n);
    vector<int> dp(n, 2e9);
    for (int i = 0; i < n; i++)
        cin >> h[i];
    dp[0] = 0;
    for (int i = 0; i < n - 2; i++) {
        dp[i + 1] = min(dp[i + 1], dp[i] + abs(h[i + 1] - h[i]));
        dp[i + 2] = min(dp[i + 2], dp[i] + abs(h[i + 2] - h[i]));
    }
    dp[n - 1] = min(dp[n - 1], dp[n - 2] + abs(h[n - 1] - h[n - 2]));
    cout << dp[n - 1] << endl;
    return 0;
}