#include <bits/stdc++.h>
#define int long long
using namespace std;
int32_t main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int n, m;
  string s, t;
  vector<int> pending;

  auto zuha = [&](int x) {
    for (int i = 0; i < m; i++)
      if (s[x + i] != '?' && s[x + i] != t[i]) return false;
    return true;
  };

  auto woogie = [&](int x) {
    for (int i = 0; i < m; i++) s[x + i] = '?';
  };

  cin >> n >> m >> s >> t;
  for (int i = 0; i < n - m + 1; i++) {
    if (zuha(i)) {
      s.replace(i, m, m, '?');
      while (!pending.empty() && zuha(pending.back())) {
        woogie(pending.back());
        pending.pop_back();
      }
    } else {
      pending.push_back(i);
    }
  }
  while (!pending.empty()) {
    if (zuha(pending.back())) woogie(pending.back());
    pending.pop_back();
  }
  cout << (s == string(n, '?') ? "Yes" : "No") << '\n';
  return 0;
}
