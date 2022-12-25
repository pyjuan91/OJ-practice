#include <bits/stdc++.h>
using namespace std;
const int ma = 1e5 + 5;
using ll = long long;
const ll mod = 1e9 + 7;
void solve(vector<vector<ll>>& dp, int cur, int parent,
    vector<vector<int>>& g)
{
    for (auto child : g[cur]) {
        if (child != parent) {
            solve(dp, child, cur, g);
            // 0 represent drawing white
            dp[cur][0] *= (dp[child][0] + dp[child][1]) % mod;
            dp[cur][0] %= mod;
            //  1 represent drawing black
            dp[cur][1] *= (dp[child][0]);
            dp[cur][1] %= mod;
        }
    }
}
int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, a, b;
    cin >> n;
    vector<vector<int>> g(n + 1);
    for (int i = 1; i < n; i++) {
        cin >> a >> b;
        g[a].emplace_back(b);
        g[b].emplace_back(a);
    }
    vector<vector<ll>> dp(n + 1, vector<ll>(2, 1LL));
    solve(dp, 1, 0, g);
    cout << (dp[1][0] + dp[1][1]) % mod;
    return 0;
}

// #include <algorithm>
// #include <stdio.h>
// #include <string>
// #include <vector>
// using namespace std;

// const int mod = 1000000007;
// int N;
// long long D[100100][2];
// vector<int> G[100100];

// void go(int x, int l)
// {
//     D[x][0] = D[x][1] = 1;
//     for (auto y : G[x])
//         if (l != y) {
//             go(y, x);
//             D[x][0] = D[x][0] * (D[y][0] + D[y][1]) % mod;
//             D[x][1] = D[x][1] * D[y][0] % mod;
//         }
// }

// int main()
// {
//     scanf("%d", &N);
//     for (int i = 1; i < N; i++) {
//         int x, y;
//         scanf("%d %d", &x, &y);
//         G[x].push_back(y);
//         G[y].push_back(x);
//     }
//     go(1, 0);
//     printf("%lld\n", (D[1][0] + D[1][1]) % mod);

//     return 0;
// }