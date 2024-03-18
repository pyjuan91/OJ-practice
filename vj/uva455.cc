#include <bits/stdc++.h>
#define int long long
using namespace std;

int zuha(string& s) {
  int n = s.size();
  for (int i = 1; i <= n; i++) {
    if (n % i) continue;
    bool ok = true;
    for (int j = i; j < n; j++) {
      if (s[j] != s[j % i]) {
        ok = false;
        break;
      }
    }
    if (ok) return i;
  }
  return n;
}

int32_t main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int t;
  string s;
  cin >> t;
  for (int kase = 0; kase < t; kase++) {
    if (kase) cout << "\n";
    cin >> s;
    cout << zuha(s) << "\n";
  }
  return 0;
}
