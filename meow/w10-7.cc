#include <bits/stdc++.h>
using namespace std;
int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<int> a(n), b(n), c(n);
    for (int i = 0; i < n; i++)
        cin >> a[i] >> b[i] >> c[i];
    int dp[3] = { a[0], b[0], c[0] };
    for (int i = 1; i < n; i++) {
        int copy[3];
        copy[0] = a[i] + max(dp[1], dp[2]);
        copy[1] = b[i] + max(dp[0], dp[2]);
        copy[2] = c[i] + max(dp[0], dp[1]);
        swap(dp, copy);
    }
    cout << max({ dp[0], dp[1], dp[2] }) << "\n";
    return 0;
}