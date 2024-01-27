#include <bits/stdc++.h>
using namespace std;
int32_t main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int cnt[26] = {};
  string s;
  cin >> s;
  for (char c : s) {
    cnt[c - 'a']++;
  }
  int mx = *max_element(cnt, cnt + 26);
  for (int i = 0; i < 26; i++) {
    if (cnt[i] == mx) {
      cout << (char)('a' + i) << '\n';
      break;
    }
  }
  return 0;
}
