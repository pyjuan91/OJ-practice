#include <bits/stdc++.h>
#ifndef ONLINE_JUDGE
#include "./debug.cc"
#else
#define debug(...)
#define debugArr(...)
#endif
#define int long long
using namespace std;

int patty(int n, string& s)
{
    // 000 -> (10, 01) -> 0
    // 001 -> (11, 00) -> 1
    // 010 -> (10, 01) -> 0
    // 011 -> (01, 01) -> 0
    // 100 -> (00, 11) -> 1
    // 101 -> (01, 10) -> 0
    // 110 -> (10, 10) -> 0
    // 111 -> (11, 11) -> 1
    vector<vector<int>> dp(n + 1, vector<int>(2, 0));
    s = " " + s;
    int res = 0;
    for (int i = 1; i <= n; i++)
    {
        if (s[i] == '0')
        {
            dp[i][1] += dp[i - 1][0];
            dp[i][0] += dp[i - 1][1] + 1;
        }
        else
        {
            dp[i][1] = dp[i - 1][1] + 1;
            dp[i][0] = dp[i - 1][0];
        }
        res += dp[i][1];
    }
    return res;
}

int32_t main()
{
    cin.tie(nullptr)->sync_with_stdio(false);
    int n;
    string s;
    cin >> n >> s;
    cout << patty(n, s) << "\n";
    return 0;
}
