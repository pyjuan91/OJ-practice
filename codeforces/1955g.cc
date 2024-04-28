#include <bits/stdc++.h>
using namespace std;

const int kMax = 105;
int t, n, m, a[kMax][kMax];
bool dp[kMax][kMax];

bool check(int factor) {
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) dp[i][j] = false;
  }
  dp[0][0] = true;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (a[i][j] % factor == 0 && dp[i][j]) {
        if (i + 1 < n) dp[i + 1][j] = true;
        if (j + 1 < m) dp[i][j + 1] = true;
      }
    }
  }
  return dp[n - 1][m - 1];
}

int32_t main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  cin >> t;
  while (t--) {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) cin >> a[i][j];
    }
    vector<int> factors;
    int g = __gcd(a[0][0], a[n - 1][m - 1]);
    for (int i = 1; i <= sqrt(g); i++) {
      if (g % i == 0) {
        factors.push_back(i);
        if (i != g / i) factors.push_back(g / i);
      }
    }
    sort(factors.rbegin(), factors.rend());
    for (auto factor : factors) {
      if (check(factor)) {
        cout << factor << '\n';
        break;
      }
    }
  }
  return 0;
}
