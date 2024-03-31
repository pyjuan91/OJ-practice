#include <bits/stdc++.h>
#define int long long
using namespace std;

const int kMax = 5e3 + 5;
int t, n, m, a[kMax][kMax];
vector<int> dp[kMax];

int32_t main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  cin >> t;
  while (t--) {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
      for (int j = i; j <= n; j++) cin >> a[i][j];
      dp[i].clear();
    }
    dp[0] = {0};

    for (int i = 1; i <= n; i++) {
      priority_queue<array<int, 3>> pq;
      pq.push({dp[i - 1][0], i - 1, 0});

      for (int j = i - 2; j >= -1; j--) {
        pq.push({(j < 0 ? 0 : dp[j][0]) + a[j + 2][i], j, 0});
      }

      while (!pq.empty() && dp[i].size() < m) {
        auto [sum, j, k] = pq.top();
        pq.pop();
        dp[i].push_back(sum);

        if (j < 0 || k + 1 == dp[j].size()) continue;

        if (j == i - 1)
          pq.push({dp[i - 1][k + 1], i - 1, k + 1});
        else
          pq.push({dp[j][k + 1] + a[j + 2][i], j, k + 1});
      }
    }
    for (auto x : dp[n]) cout << x << ' ';
    cout << '\n';
  }
  return 0;
}
