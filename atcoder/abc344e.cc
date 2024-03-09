#include <bits/stdc++.h>
#define int long long
using namespace std;
int32_t main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int n, q, op, x, y;
  cin >> n;
  vector<int> a(n);
  for (auto &x : a) cin >> x;
  unordered_map<int, int> left, right;
  for (int i = 0; i < n; i++) {
    if (i == 0)
      left[a[i]] = 0;
    else
      left[a[i]] = a[i - 1];
    if (i == n - 1)
      right[a[i]] = 1e9 + 1;
    else
      right[a[i]] = a[i + 1];
  }
  right[0] = a[0];
  left[1e9 + 1] = a[n - 1];
  cin >> q;
  while (q--) {
    cin >> op;
    if (op == 1) {
      cin >> x >> y;
      left[right[x]] = y;
      right[y] = right[x];
      right[x] = y;
      left[y] = x;
    } else {
      cin >> x;
      right[left[x]] = right[x];
      left[right[x]] = left[x];
      left.erase(x), right.erase(x);
    }
  }
  int cur = right[0];
  while (cur != 1e9 + 1) {
    cout << cur << ' ';
    cur = right[cur];
  }
  return 0;
}
