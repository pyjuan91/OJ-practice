#include <bits/stdc++.h>
#define int long long
using namespace std;
int32_t main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int t;
  string n, m;
  cin >> t;
  while (t--) {
    cin >> n >> m;
    int sz = n.size();
    bool first_modi = false;
    for (int i = 0; i < sz; i++) {
      if (n[i] == m[i])
        continue;
      else if (n[i] > m[i]) {
        if (first_modi == false) {
          first_modi = true;
        } else {
          swap(n[i], m[i]);
        }
      } else {
        if (first_modi == false) {
          swap(n[i], m[i]);
          first_modi = true;
        }
      }
    }
    cout << n << "\n" << m << "\n";
  }
  return 0;
}
