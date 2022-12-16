#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = LLONG_MAX / 2;
void floyd(vector<vector<ll>>& g, ll& n)
{
    for (int mid = 0; mid < n; mid++) {
        for (int start = 0; start < n; start++) {
            for (int end = 0; end < n; end++) {
                g[start][end] = min(
                    g[start][end],
                    g[start][mid] + g[mid][end]);
            }
        }
    }
}
int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    // cout << INF << endl;
    ll n, m, k, a, b, c;
    cin >> n >> m >> k;

    vector buy = vector<vector<ll>>(n, vector<ll>(k));
    vector sell = vector<vector<ll>>(n, vector<ll>(k));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < k; j++)
            cin >> buy[i][j] >> sell[i][j];
    }

    vector<vector<ll>> g(n, vector<ll>(n, INF));
    for (int i = 0; i < m; i++) {
        cin >> a >> b >> c;
        g[a - 1][b - 1] = c;
    }

    floyd(g, n);

    vector profit = vector<vector<ll>>(n, vector<ll>(n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            for (int p = 0; p < k; p++) {
                if (buy[i][p] != -1 && sell[j][p] != -1) {
                    profit[i][j] = max(
                        profit[i][j],
                        sell[j][p] - buy[i][p]);
                }
            }
        }
    }

    vector g2 = vector<vector<ll>>(n, vector<ll>(n));
    ll left = 1, right = 1e9, mid;
    while (left <= right) {
        mid = left + (right - left) / 2;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                g2[i][j]
                    = mid * min(g[i][j], INF / mid) - profit[i][j];
            }
        }

        floyd(g2, n);

        bool hasNNCycle = false;

        for (int i = 0; i < n; i++) {
            if (g2[i][i] <= 0)
                hasNNCycle = true;
        }

        if (hasNNCycle)
            left = mid + 1;
        else
            right = mid - 1;
    }

    cout << right << "\n";
    return 0;
}