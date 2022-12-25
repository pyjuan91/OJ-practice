#include <bits/stdc++.h>
using namespace std;
int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, k;
    cin >> n >> k;
    vector<int> h(n), dp(n, 2e9);
    for (int i = 0; i < n; i++)
        cin >> h[i];
    dp[0] = 0;
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j <= i + k && j < n; j++) {
            dp[j] = min(dp[j], dp[i] + abs(h[j] - h[i]));
        }
    }
    cout << dp[n - 1];
    return 0;
}