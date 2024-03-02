#include <bits/stdc++.h>
#define int long long
using namespace std;
int32_t main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int t, n;
  cin >> t;
  while (t--) {
    cin >> n;
    vector<int> a(n);
    for (auto &i : a) cin >> i;
    sort(a.begin(), a.end());
    int x1 = a[1] - a[0], x2 = a[n - 2] - a[1], x3 = a[n - 1] - a[n - 2];
    cout << 2 * x1 + 4 * x2 + 2 * x3 << '\n';
  }
  return 0;
}
