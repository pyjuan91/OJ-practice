#include <bits/stdc++.h>
using namespace std;
string chaewon(string s, const string& t) {
  int n = s.size(), m = t.size();
  for (int i = n - m; i >= 0; i--) {
    auto check = [&](int id) {
      for (int j = 0; j < m; j++) {
        if (s[id + j] == '?') continue;
        if (s[id + j] != t[j]) return false;
      }
      return true;
    };
    if (check(i)) {
      for (int j = 0; j < m; j++) s[i + j] = t[j];
      for (int j = 0; j < n; j++)
        if (s[j] == '?') s[j] = 'a';
      return s;
    }
  }
  return "UNRESTORABLE";
}
int32_t main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  string s, t;
  cin >> s >> t;
  cout << chaewon(s, t) << "\n";
  return 0;
}
