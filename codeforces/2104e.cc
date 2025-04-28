#include <bits/stdc++.h>
#ifndef ONLINE_JUDGE
#include "./debug.cc"
#else
#define debug(...)
#define debugArr(...)
#endif
#define int long long
using namespace std;
int32_t main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int n, k;
  string s;
  cin >> n >> k >> s;

  vector<vector<int>> pos(k);
  for (int i = 0; i < n; i++) {
    pos[s[i] - 'a'].push_back(i + 1);
  }

  vector<int> dp(n + 5), next_pos(k);


  for (int i = n; i >= 1; i--) {
    int c = s[i - 1] - 'a';
    next_pos[c] = i;

    bool all_appear = true;
    for (int c = 0; c < k; c++) {
      if (next_pos[c] == 0) {
        all_appear = false;
        break;
      }
    }
    if (!all_appear) {
      dp[i] = 0;
      continue;
    }
    else {
      int mi = INT64_MAX;
      for (int c = 0; c < k; c++) {
        int p = next_pos[c] + 1;
        mi = min(mi, dp[p]);
      }
      dp[i] = mi + 1;
    }
  }

  int q;
  cin >> q;
  string t;
  while (q--) {
    cin >> t;
    int current_pos = 1;
    bool is_sub = true;
    for (auto ch : t) {
      const auto& v = pos[ch - 'a'];
      auto it = lower_bound(v.begin(), v.end(), current_pos);
      if (it == v.end()) {
        is_sub = false;
        break;
      }
      current_pos = *it + 1;
    }

    cout << (not is_sub ? 0 : dp[current_pos] + 1) << "\n";
  }
  return 0;
}
