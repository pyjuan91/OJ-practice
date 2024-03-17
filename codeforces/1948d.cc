#include <bits/stdc++.h>
using namespace std;

int chaewon(string& s, int n) {
  if (n % 2 == 1) n--;
  for (int ideal_len = n; ideal_len >= 2; ideal_len -= 2) {
    int success_pairs = 0;
    int d = ideal_len / 2;
    for (int i = 0; i < d; i++) {
      if (s[i] == s[i + d] || s[i] == '?' || s[i + d] == '?') {
        success_pairs++;
      }
    }
    if (success_pairs == d) return ideal_len;
    for (int i = d; i + d < s.size(); i++) {
      success_pairs -= (s[i - d] == s[i] || s[i - d] == '?' || s[i] == '?');
      success_pairs += (s[i] == s[i + d] || s[i] == '?' || s[i + d] == '?');
      // cout << "s[i - d]: " << s[i - d] << " s[i]: " << s[i]
      //      << " s[i + d]: " << s[i + d] << "\n";
      // cout << "i: " << i << " success_pairs: " << success_pairs << " d: " << d
      //      << " ideal_len: " << ideal_len << "\n";
      if (success_pairs == d) return ideal_len;
    }
  }
  return 0;
}

int32_t main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int t, n;
  string s;
  cin >> t;
  while (t--) {
    cin >> s;
    n = s.size();
    cout << chaewon(s, n) << '\n';
  }
  return 0;
}
