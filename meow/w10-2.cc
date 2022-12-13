#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = 1e18;
int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m, q, a, b, c;
    cin >> n >> m >> q;
    // vector g = vector<vector<vector<ll>>>(n + 1,
    //     vector<vector<ll>>(n + 1, vector<ll>(n + 1, INF)));
    vector g = vector<vector<ll>>(n + 1, vector<ll>(n + 1, INF));
    for (int i = 1; i <= n; i++)
        g[i][i] = 0;
    // for (auto i : g) {
    //     for (auto j : i)
    //         cout << j << " ";
    //     cout << endl;
    // }
    while (m--) {
        cin >> a >> b >> c;
        g[a][b] = min(g[a][b], 1LL * c);
        g[b][a] = g[a][b];
    }
    for (int mid = 1; mid <= n; mid++) {
        for (int start = 1; start < n; start++) {
            if (start == mid)
                continue;
            for (int end = start + 1; end <= n; end++) {
                if (end == mid)
                    continue;
                if (g[start][mid] + g[mid][end] < g[start][end]) {
                    g[start][end] = g[start][mid] + g[mid][end];
                    g[end][start] = g[start][end];
                }
            }
        }
    }
    while (q--) {
        cin >> a >> b;
        if (g[a][b] >= INF)
            cout << "-1\n";
        else
            cout << g[a][b] << "\n";
    }
    return 0;
}