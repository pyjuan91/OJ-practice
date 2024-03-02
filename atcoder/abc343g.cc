#include <bits/stdc++.h>
#define int long long
using namespace std;
int32_t main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int n;
  string s;
  vector<string> a;
  unordered_set<string> st;
  cin >> n;
  while (n--) {
    cin >> s;
    st.insert(s);
  }
  for (const auto& x : st) {
    bool too_small = false;
    for (const auto& y : st) {
      if (x.size() < y.size() && y.find(x) != string::npos) {
        too_small = true;
        break;
      }
    }
    if (!too_small) a.push_back(x);
  }
  n = a.size();

  auto kazuha = [&](const string& s1, const string& s2) {
    int n = s1.size(), m = s2.size();
    for (int len = min(n, m); len > 0; len--) {
      if (s1.substr(n - len) == s2.substr(0, len)) return len;
    }
    return 0ll;
  };

  vector<vector<int>> shrink(n, vector<int>(n));
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (i != j) shrink[i][j] = kazuha(a[i], a[j]);
    }
  }

  vector<vector<int>> dp(n + 1, vector<int>((1ll << n), 1e9));

  for (int mask = 1; mask < (1ll << n); mask++) {
    if (__popcount(mask) == 1) {
      dp[__builtin_ctzll(mask)][mask] = a[__builtin_ctzll(mask)].size();
      continue;
    }
    for (int end_with = 0; end_with < n; end_with++) {
      if (!(mask & (1ll << end_with))) continue;
      for (int prev = 0; prev < n; prev++) {
        if (prev == end_with || !(mask & (1ll << prev))) continue;
        dp[end_with][mask] =
            min(dp[end_with][mask], dp[prev][mask ^ (1ll << end_with)] +
                                        (int)a[end_with].size() -
                                        shrink[prev][end_with]);
      }
    }
  }

  int res = INT32_MAX;
  for (int i = 0; i < n; i++) {
    res = min(res, dp[i][(1ll << n) - 1]);
  }
  cout << res << '\n';
  return 0;
}
