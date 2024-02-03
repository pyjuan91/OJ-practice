#include <bits/stdc++.h>
using namespace std;
int32_t main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  string s, res;
  cin >> s;
  while (!s.empty() && s.back() != '.') {
    res.push_back(s.back());
    s.pop_back();
  }
  reverse(res.begin(), res.end());
  cout << res << "\n";
  return 0;
}
