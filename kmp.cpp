#include <bits/stdc++.h>
using namespace std;

const int kMax = 1e6 + 5;
int kmp[kMax], n, m, i, j;
string s, t;

int32_t main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  cin >> s >> t;
  n = s.size(), m = t.size();
  s = ' ' + s + ' ', t = ' ' + t + ' ', j = 0;
  for (int i = 2; i <= m; i++) {
    while (j && t[i] != t[j + 1]) j = kmp[j];
    if (t[i] == t[j + 1]) j++;
    kmp[i] = j;
  }
  j = 0;
  for (int i = 1; i <= n; i++) {
    while (j && s[i] != t[j + 1]) j = kmp[j];
    if (s[i] == t[j + 1]) j++;
    if (j == m) {
      cout << i - m + 1 << '\n';
      j = kmp[j];
    }
  }
  for (int i = 1; i <= m; i++) cout << kmp[i] << ' ';
  return 0;
}
