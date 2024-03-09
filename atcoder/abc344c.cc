#include <bits/stdc++.h>
#define int long long
using namespace std;
int32_t main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int n, m, k, q;
  cin >> n;
  vector<int> a(n);
  for (auto &x : a) cin >> x;
  cin >> m;
  vector<int> b(m);
  for (auto &x : b) cin >> x;
  cin >> k;
  vector<int> c(k);
  for (auto &x : c) cin >> x;
  unordered_set<int> us;
  for (auto x : a) {
    for (auto y : b) {
      for (auto z : c) {
        us.insert(x + y + z);
      }
    }
  }
  cin >> q;
  while (q--) {
    int x;
    cin >> x;
    cout << (us.count(x) ? "Yes" : "No") << "\n";
  }
  return 0;
}
