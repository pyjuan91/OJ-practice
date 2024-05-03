#include <bits/stdc++.h>
using namespace std;
int32_t main() {
  cin.tie(nullptr)->sync_with_stdio(false);

  int t;
  cin >> t;
  while (t--) {
    int n, m;
    cin >> n >> m;
    vector<int> a(n + 1), pref_xor(n + 1);
    map<int, vector<int>> xor_pos;
    for (int i = 1; i <= n; i++) {
      cin >> a[i];
      pref_xor[i] = pref_xor[i - 1] ^ a[i];
      xor_pos[pref_xor[i]].push_back(i);
    }

    while (m--) {
      int l, r;
      cin >> l >> r;
      if (pref_xor[r] == pref_xor[l - 1]) {
        cout << "YES\n";
        continue;
      }

      auto it1 = lower_bound(xor_pos[pref_xor[r]].begin(),
                             xor_pos[pref_xor[r]].end(), l);
      auto it2 = upper_bound(xor_pos[pref_xor[l - 1]].begin(),
                             xor_pos[pref_xor[l - 1]].end(), *it1);
      if (it2 != xor_pos[pref_xor[l - 1]].end() && *it2 < r) {
        cout << "YES\n";
      } else {
        cout << "NO\n";
      }
    }
  }
  return 0;
}
