#include <bits/stdc++.h>
using namespace std;

bool is_palin(string s) {
  for (int i = 0; i < s.size() / 2; i++) {
    if (s[i] != s[s.size() - i - 1]) return false;
  }
  return true;
}

bool chaewon(set<pair<string, int>>& a) {
  for (const auto& [s, id] : a) {
    if (is_palin(s)) return true;
  }
  for (const auto& [s, id] : a) {
    if (s.size() == 2) {
      string t = s;
      reverse(t.begin(), t.end());
      auto it = a.lower_bound({t, 0});
      if (it != a.end() && it->first == t) return true;
      for (char c = 'a'; c <= 'z'; c++) {
        string tt = c + t;
        auto it = a.lower_bound({tt, id});
        if (it != a.end() && it->first == tt) return true;
      }
    } else {
      string t = s;
      reverse(t.begin(), t.end());
      auto it = a.lower_bound({t, 0});
      if (it != a.end() && it->first == t) return true;
      t.erase(t.begin());
      it = a.lower_bound({t, id});
      if (it != a.end() && it->first == t) return true;
    }
  }
  return false;
}

int32_t main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int t, n;
  cin >> t;
  while (t--) {
    cin >> n;
    set<pair<string, int>> a;
    string s;
    for (int i = 0; i < n; i++) {
      cin >> s;
      a.insert(make_pair(s, i));
    }
    cout << (chaewon(a) ? "YES\n" : "NO\n");
  }
  return 0;
}
