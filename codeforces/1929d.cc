#include <bits/stdc++.h>
#define int long long
using namespace std;

const int kMax = 3e5 + 5, kMod = 998244353;
int t, n, a, b, res;
vector<int> g[kMax];
int dp[kMax];

void kazuha(int u, int p) {
  dp[u] = 1;
  for (int v : g[u]) {
    if (v != p) {
      kazuha(v, u);
      dp[u] *= (dp[v] + 1);
      dp[u] %= kMod;
    }
  }
}

int32_t main() {
  cin.tie(nullptr)->sync_with_stdio(false);

  cin >> t;
  while (t--) {
    cin >> n;
    for (int i = 1; i <= n; i++) {
      dp[i] = 0;
      g[i].clear();
    }
    for (int i = 1; i < n; i++) {
      cin >> a >> b;
      g[a].push_back(b);
      g[b].push_back(a);
    }
    res = 1, kazuha(1, 0);
    for (int i = 1; i <= n; i++) {
      res += dp[i];
      res %= kMod;
    }
    cout << res << '\n';
  }
  return 0;
}
