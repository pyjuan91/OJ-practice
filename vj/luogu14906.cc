#include <bits/stdc++.h>
#ifdef LOCAL
#include "./debug.cc"
#else
#define debug(...)
#define debugArr(...)
#endif
#define int long long
using namespace std;
int32_t main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int n;
  cin >> n;
  set<string> s;
  for (int i = 0; i < n; i++) {
    string x;
    cin >> x;
    s.insert(x);
  }

  auto compare = [&](const string& lhs, const string& rhs) -> bool {
    const int n = lhs.size(), m = rhs.size();
    vector<pair<char, char>> diffs;
    for (int i = 0; i < max(n, m); i++) {
      char lc = i >= n ? '0' : lhs[n - i - 1];
      char rc = i >= m ? '0' : rhs[m - i - 1];
      if (lc != rc) {
        diffs.push_back({lc, rc});
        if (diffs.size() > 2) return false;
      }
    }
    if (diffs.size() != 2) return false;
    return diffs[0].first == diffs[1].second && diffs[0].second == diffs[1].first;
  };

  int comp_cnt = 0, ma_comp_mem = 0;
  while (!s.empty()) {
    queue<string> q;
    q.push(*s.rbegin());
    s.erase(prev(s.end()));
    comp_cnt++;
    int cur_comp_mem = 1;
    while (!q.empty()) {
      auto cur = q.front();
      q.pop();
      for (auto iter = s.begin(); iter != s.end();) {
        if (compare(*iter, cur)) {
          q.push(*iter);
          iter = s.erase(iter);
          cur_comp_mem++;
        } else {
          iter++;
        }
      }
    }
    ma_comp_mem = max(ma_comp_mem, cur_comp_mem);
  }
  cout << comp_cnt << " " << ma_comp_mem << "\n";
  return 0;
}
